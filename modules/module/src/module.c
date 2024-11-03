#include "./module.h"

#include <assert.h>
#include <time.h>

#include "param.h"
#include "state_machine.h"
#include "vlcb/common/vlcb_defs.h"
#include "vlcb/module.h"
#include "vlcb/module/param.h"
#include "vlcb/module/state.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/datagram/module.h"
#include "vlcb/net/socket.h"
#include "vlcb/net/socket/datagram.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/log.h"
#include "vlcb/platform/time.h"

#ifndef VLCB_MODULE_HEARTBEAT_MS
#define VLCB_MODULE_HEARTBEAT_MS 5000
#endif /* ifndef VLCB_MODULE_HEARTBEAT_MS */

static inline void HandleHeartbeat(VlcbModule *const self, const clock_t now) {
  // send heartbeat if module is in normal mode, heartbeat is enabled and
  // heartbeat timeout passed (or if it's the first heartbeat) heartbeatSequence
  // increments, until it overflows, which is expected
  if (self->sm.state == VLCB_MODULE_STATE_NORMAL &&
      self->config.operationFlags & VLCB_MODULE_FLAGS_HEARTBEAT &&
      (self->lastHeartbeat == 0 ||
       vlcb_platform_time_DiffInMs(self->lastHeartbeat, now) >=
           VLCB_MODULE_HEARTBEAT_MS)) {
    VlcbNetPacketDatagram packet;
    vlcb_net_pkt_dgram_module_Heartbeat_Serialize(
        &packet, (VlcbNetDgramHeartbeat){
                     .nodeNumber = self->config.nodeNumber,
                     .sequence = self->heartbeatSequence,
                     .status = 0, // TODO: replace with diagnostic status
                     .statusBits = 0});

    VlcbNetSocketDgramSendErr err =
        vlcb_net_sock_dgram_Send(self->socket, &packet);
    // we can ignore misseed heartbeats due to socket buffer being full
    if (err != VLCB_NET_SOCK_DGRAM_SEND_ERR_OK) {
      if (err != VLCB_NET_SOCK_DGRAM_SEND_ERR_BUF_FULL) {
        VLCBLOG_ERROR(vlcb_net_sock_dgram_SendErrToStr(err));
      }
      return; // ensure that when socket errors out, we don't update heartbeat
              // stats
    }

    self->lastHeartbeat = now;
    self->heartbeatSequence++;
  }
}

static inline void HandleQueryNodeParameters(VlcbModule *const self) {
  // RQNP, targets only modules in Setup mode
  if (self->sm.state == VLCB_MODULE_STATE_SETUP) {
    VlcbNetPacketDatagram response;
    const VlcbModuleParams *const params = self->params;
    vlcb_net_pkt_dgram_module_NodeParams_Serialize(
        &response,
        (VlcbNetDgramNodeParams){
            .manuId = ModuleParamGetByte(params,
                                         VLCB_MODULE_PARAM_MODULE_MANUFACTURER),
            .moduleType =
                ModuleParamGetByte(params, VLCB_MODULE_PARAM_MODULE_TYPE),
            .majorVersion =
                ModuleParamGetByte(params, VLCB_MODULE_PARAM_MAJOR_VERSION),
            .minorVersion =
                ModuleParamGetByte(params, VLCB_MODULE_PARAM_MINOR_VERSION),
            .eventCount =
                ModuleParamGetByte(params, VLCB_MODULE_PARAM_MAX_EVENT_COUNT),
            .eventVariableCount = ModuleParamGetByte(
                params, VLCB_MODULE_PARAM_EVENT_VARIABLE_COUNT),
            .nodeVariableCount = ModuleParamGetByte(
                params, VLCB_MODULE_PARAM_NODE_VARIABLE_COUNT)});
    VlcbNetSocketDgramSendErr err =
        vlcb_net_sock_dgram_Send(self->socket, &response);
    if (err != VLCB_NET_SOCK_DGRAM_SEND_ERR_OK) {
      if (err == VLCB_NET_SOCK_DGRAM_SEND_ERR_BUF_FULL) {
        VLCBLOG_INFO(vlcb_net_sock_dgram_SendErrToStr(err));
      } else {
        VLCBLOG_ERROR(vlcb_net_sock_dgram_SendErrToStr(err));
      }
      return; // at the moment we don't do anything, just drop the packet
    }
  }
}

static inline void
HandleQueryNodeParameterByIndex(VlcbModule *const self,
                                const VlcbNetPacketDatagram *const packet) {
  // RQNPN, index 0 should return number of available params, followed by each
  // param as a separate packet
}

static inline void
HandleSetNodeNumber(VlcbModule *const self,
                    const VlcbNetPacketDatagram *const packet) {
  // SNN - set only in response to RQNN by the setup tool, only to node in setup
  // mode
  if (self->sm.state == VLCB_MODULE_STATE_SETUP) {
  }
}

static inline void AbortSetup(VlcbModule *const self, clock_t now) {
  // Abort setup mode, if another mode entered setup (MNS Spec 3.2.1)
  if (self->sm.state == VLCB_MODULE_STATE_SETUP) {
    state_Dispatch(self, (ModuleStateEvent){.sig = MSE_ABORT_SETUP}, now);
  }
}

static inline void HandleQueryNodeInfo(VlcbModule *const self) {
  // QNN - only initialized modules should respond
  if (self->sm.state == VLCB_MODULE_STATE_NORMAL) {
  }
}

static inline void HandleQueryModuleName(VlcbModule *const self) {
  // only respond in setup node or if node is in normal mode and the learn flag
  // is set
  if (self->sm.state == VLCB_MODULE_STATE_SETUP ||
      (self->sm.state == VLCB_MODULE_STATE_NORMAL &&
       ModuleParamGetByte(self->params, VLCB_MODULE_PARAM_FLAGS) &
           VLCB_MODULE_FLAG_LEARN_MODE)) {
    VlcbNetPacketDatagram response;

    // 11 - request for node module name, excluding "CAN" prefix
    // sent during module transition, so no node number check
    // DEBUG_SERIAL << F("> RQMN received") << endl;

    // only respond if in transition to Normal, i.e. Setup mode, or in learn
    // mode.

    // if (instantMode == MODE_SETUP ||
    //     (controller->getParam(PAR_FLAGS) & PF_LRN)) {
    //   // respond with NAME
    //   VlcbMessage response;
    //   response.len = 8;
    //   response.data[0] = OPC_NAME;
    //   memcpy(response.data + 1, controller->getModuleName(), 7);
    //   controller->sendMessage(&response);
    // }
    // request for module name, sent during transition to normal or during learn
    // mode
  }
}

static inline void
HandleRebootRequest(VlcbModule *const self,
                    const VlcbNetPacketDatagram *const packet) {
  if (packet->opc == VLCB_OPC_RESTART_ALL_NODES) {
    self->restart();
    return;
  }

  VlcbNetDgramRestartNode request =
      vlcb_net_pkt_dgram_module_RestartNode_Deserialize(packet);
  if (self->config.nodeNumber == request.nodeNumber) {
    self->restart();
  }
}

static inline void HandleMnsMessages(VlcbModule *const self,
                                     const VlcbNetPacketDatagram *const packet,
                                     clock_t now) {
  switch (packet->opc) {
  case VLCB_OPC_QUERY_NODE_PARAMETERS:
    HandleQueryNodeParameters(self);
    break;
  case VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX:
    HandleQueryNodeParameterByIndex(self, packet);
    break;
  case VLCB_OPC_SET_NODE_NUMBER:
    HandleSetNodeNumber(self, packet);
    break;
  case VLCB_OPC_REQUEST_NEW_NODE_NUMBER:
    AbortSetup(self, now);
    break;
  case VLCB_OPC_QUERY_NODE_INFO:
    HandleQueryNodeInfo(self);
    break;
  case VLCB_OPC_QUERY_MODULE_NAME:
    HandleQueryModuleName(self);
    break;

    // case OPC_RQSD:
    // 78 - Request Service Definitions.
    // handleRequestServiceDefinitions(msg, nn);
    break;

    // case OPC_RDGN:
    // 87 - Request Diagnostic Data
    // handleRequestDiagnostics(msg, nn);
    break;

    // case OPC_MODE:
    // 76 - Set Operating Mode
    // handleModeMessage(msg, nn);
    break;

    // case OPC_NNRSM:
    // 4F - reset to manufacturer's defaults
    // if (nn == module_config->nodeNum) {
    //   controller->sendMessageWithNN(OPC_NNREL); // release node number first
    //   module_config->resetModule();
    // }
    break;

  case VLCB_OPC_RESTART_ALL_NODES:
  case VLCB_OPC_RESTART_NODE:
    HandleRebootRequest(self, packet);
    break;
  }
}

VlcbModule vlcb_module_New(const char *const name, VlcbNetIface *const iface,
                           VlcbNetSocketDatagram *const socket,
                           const IVlcbModuleUi ui,
                           VlcbModuleParams *const params,
                           RestartRequestHandler restartHandler) {
  assert(iface != NULL && socket != NULL && params != NULL &&
         restartHandler != NULL && name != NULL);

  return (VlcbModule){.name = name,
                      .iface = iface,
                      .socket = socket,
                      .params = params,
                      .ui = ui,
                      .config =
                          {
                              .operationFlags = 0,
                              .state = VLCB_MODULE_STATE_UNINITIALIZED,
                              .hwAddr = 0,
                              .nodeNumber = VLCB_NODE_NUMBER_UNINITIALIZED,
                          },
                      .restart = restartHandler};
}

void vlcb_module_Init(VlcbModule *const module, const clock_t now) {
  assert(module != NULL);
  // todo: load config from persistent storage
  state_Dispatch(module, (ModuleStateEvent){.sig = MSE_INIT}, now);
  _INTERFACE_CALL(module->ui, Poll, now);
}

void vlcb_module_Poll(VlcbModule *const module, const clock_t now) {
  assert(module != NULL && module->iface != NULL);

  VlcbNetPacketDatagram packet;

  while (1) {
    const VlcbNetSocketDgramRecvErr err =
        vlcb_net_sock_dgram_Recv(module->socket, &packet);
    if (err != VLCB_NET_SOCK_DGRAM_RECV_ERR_OK) {
      if (err == VLCB_NET_SOCK_DGRAM_RECV_ERR_WOULD_BLOCK) {
        break; // nothing to receive
      }
    }
    HandleMnsMessages(module, &packet, now);

    if (module->sm.state == VLCB_MODULE_STATE_NORMAL) {
      // TODO: handle services
    }
  }

  HandleHeartbeat(module, now);

  _INTERFACE_CALL(module->ui, Poll, now);
}
