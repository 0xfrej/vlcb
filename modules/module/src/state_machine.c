#include "state_machine.h"

#include "vlcb/common/node.h"
#include "vlcb/module.h"
#include "vlcb/module/state.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/datagram/module.h"
#include "vlcb/net/socket.h"
#include "vlcb/net/socket/datagram.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/time.h"
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#ifndef VLCB_MODULE_STATE_CHANGE_TIMEOUT_MS
#define VLCB_MODULE_STATE_CHANGE_TIMEOUT_MS 30000
#endif /* ifndef VLCB_MODULE_STATE_CHANGE_TIMEOUT_MS                           \
        */

static bool HandleTransitionToUninitialized(VlcbModule *const self) {
  // TODO: do we need to also release the setup-state address, which is not
  // persisted yet?
  const VlcbNodeNumber addr = self->config.nodeAddr;

  // release the address if it was set
  if (addr != VLCB_NODE_ADDR_UNINITIALIZED) {
    VlcbPacketDatagram packet;
    vlcb_net_pkt_dgram_module_ReleaseNodeNumber_Serialize(
        &packet, (VlcbNetDgramReleaseNodeNumber){.addr = addr});
    const VlcbNetSocketErr err =
        vlcb_net_sock_dgram_Send(self->socket, &packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      // todo: log
      return false;
    }
    self->config.nodeAddr = VLCB_NODE_ADDR_UNINITIALIZED;
  }

  self->config.state = VLCB_MODULE_PERSISTED_STATE_UNINITIALIZED;

  return true;
}

static bool HandleTransitionToSetup(VlcbModule *const self,
                                    VlcbModuleStateMachineSetupData setupData) {
  VlcbPacketDatagram packet;
  vlcb_net_pkt_dgram_module_RequestNodeNumber_Serialize(
      &packet, (VlcbNetDgramRequestNodeNumber){.addr = setupData.nodeAddr});
  const VlcbNetSocketErr err = vlcb_net_sock_dgram_Send(self->socket, &packet);
  if (err != VLCB_NET_SOCK_ERR_OK) {
    // TODO: log
    return false;
  }
  return true;
}

static bool HandleTransitionToNormal(VlcbModule *const self) {
  if (self->config.nodeAddr != VLCB_NODE_ADDR_UNINITIALIZED) {
    VlcbPacketDatagram packet;
    vlcb_net_pkt_dgram_module_ReleaseNodeNumber_Serialize(
        &packet,
        (VlcbNetDgramReleaseNodeNumber){.addr = self->config.nodeAddr});
    const VlcbNetSocketErr err =
        vlcb_net_sock_dgram_Send(self->socket, &packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      // TODO: log
      return false;
    }
    self->config.nodeAddr =
        VLCB_NODE_ADDR_UNINITIALIZED; // if next call fails, prevent next
                                      // transition to double-release the node
                                      // number
  }

  VlcbPacketDatagram packet;
  vlcb_net_pkt_dgram_module_NodeNumberAck_Serialize(
      &packet,
      (VlcbNetDgramNodeNumberAck){.addr = self->sm.data.setup.nodeAddr});
  const VlcbNetSocketErr err = vlcb_net_sock_dgram_Send(self->socket, &packet);
  if (err != VLCB_NET_SOCK_ERR_OK) {
    // TODO: log
    return false;
  }

  self->config.state = VLCB_MODULE_PERSISTED_STATE_NORMAL;
  self->config.nodeAddr = self->sm.data.setup.nodeAddr;
  return true;
}

static inline bool CheckForSetupTimeout(VlcbModule *const self,
                                        const clock_t now) {
  return vlcb_platform_time_DiffInMs(self->sm.data.setup.startedAt, now) >=
         VLCB_MODULE_STATE_CHANGE_TIMEOUT_MS;
}

void state_Dispatch(VlcbModule *const self, const ModuleStateEvent e,
                    const clock_t now) {
  if (e.sig == MSE_INIT) {
    // reset state, node and hw address when invalid state was resolved from
    // config
    VlcbModulePersistedState persistedState = self->config.state;
    if (persistedState < VLCB_MODULE_PERSISTED_STATE_UNINITIALIZED ||
        persistedState > VLCB_MODULE_PERSISTED_STATE_NORMAL) {
      self->config.nodeAddr = 0;
      memset(&self->config.hwAddr, 0, sizeof(VlcbNetHwAddr));
      self->config.state = VLCB_MODULE_PERSISTED_STATE_UNINITIALIZED;
    }
    switch (self->config.state) {
    case VLCB_MODULE_PERSISTED_STATE_UNINITIALIZED:
      self->sm.state = VLCB_MODULE_STATE_UNINITIALIZED;
      break;
    case VLCB_MODULE_PERSISTED_STATE_NORMAL:
      self->sm.state = VLCB_MODULE_STATE_NORMAL;
    default:
      assert(false);
    }
    _INTERFACE_CALL(self->ui, IndicateState, self->sm.state);
    return;
  }

  // TODO: include error responses to invalid commands like in MNS 2.3.4.1

  const VlcbModuleState currentState = self->sm.state;
  switch (currentState) {
  case VLCB_MODULE_STATE_UNINITIALIZED:
    if (e.sig == MSE_UI_REQ_TO_SETUP) {
      const VlcbModuleStateMachineSetupData setupData = {
          .prevState = currentState,
          .nodeAddr = VLCB_NODE_ADDR_UNINITIALIZED,
          .startedAt = now};
      if (HandleTransitionToSetup(self, setupData)) {
        self->sm.state = VLCB_MODULE_STATE_SETUP;
        self->sm.data.setup = setupData;
      }
    }
    break;
  case VLCB_MODULE_STATE_SETUP:
    switch (e.sig) {
    case MSE_MODE_MSG_FOR_ANOTHER_MODULE:
      // Module encountered a MODE message for another module, aborting it's
      // setup
      // TODO: send NNACK, on fail log and either restart the module or send to
      // uninitialized
      self->sm.state = self->sm.data.setup.prevState;
      break;
    case MSE_UI_REQ_TO_PREV:
      // UI or MODE requested to go back to previous state without saving
      switch (self->sm.data.setup.prevState) {
      case VLCB_MODULE_STATE_UNINITIALIZED:
        // ignore req if transition failed
        if (HandleTransitionToUninitialized(self)) {
          self->sm.state = VLCB_MODULE_STATE_UNINITIALIZED;
        }
        break;
      case VLCB_MODULE_STATE_NORMAL:
        self->sm.state = VLCB_MODULE_STATE_NORMAL;
        break;
      }
      break;
    case MSE_NNRSM_MSG:
      if (HandleTransitionToUninitialized(self)) {
        self->sm.state = VLCB_MODULE_STATE_UNINITIALIZED;
      }
      break;
    case MSE_SNN_MSG:
      if (HandleTransitionToNormal(self)) {
        self->sm.state = VLCB_MODULE_STATE_NORMAL;
      }
      break;
    case MSE_POLL:
      // revert state on timeout
      if (CheckForSetupTimeout(self, now)) {
        switch (self->sm.data.setup.prevState) {
        case VLCB_MODULE_STATE_UNINITIALIZED:
          if (HandleTransitionToUninitialized(self)) {
            self->sm.state = VLCB_MODULE_STATE_UNINITIALIZED;
          }
          break;
        case VLCB_MODULE_STATE_NORMAL:
          self->sm.state = VLCB_MODULE_STATE_NORMAL;
          break;
        }
      }
      break;
    }
    break;
  case VLCB_MODULE_STATE_NORMAL:
    switch (e.sig) {
    case MSE_UI_REQ_TO_SETUP:
    case MSE_MODE_REQ_TO_SETUP:;
      const VlcbModuleStateMachineSetupData setupData = {
          .prevState = currentState,
          .nodeAddr = self->config.nodeAddr,
          .startedAt = now};
      if (HandleTransitionToSetup(self, setupData)) {
        self->sm.state = VLCB_MODULE_STATE_SETUP;
        self->sm.data.setup = setupData;
      }
      break;
    case MSE_NNRSM_MSG:
      // ignore on failure to transition
      if (HandleTransitionToUninitialized(self)) {
        self->sm.state = VLCB_MODULE_STATE_UNINITIALIZED;
      }
      break;
    }
    break;
  default:
    assert(false /* unhandled state */);
  }

  if (currentState != self->sm.state) {
    _INTERFACE_CALL(self->ui, IndicateState, self->sm.state);
  }
}
