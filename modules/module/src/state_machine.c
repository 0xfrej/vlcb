#include "state_machine.h"

#include "vlcb/net/packet/datagram/module.h"

inline void EnterUninitializedMode(VlcbModule *const module) {
  const VlcbNodeAddr addr = module->config.nodeAddr;

  // release the address if it was set
  if (addr != VLCB_NODE_ADDR_UNINITIALIZED) {
    VlcbPacketDatagram packet;
    vlcb_net_pkt_dgram_module_ReleaseNodeNumber_Serialize(
      &packet,
      (VlcbNetDgramReleaseNodeNumber) {.addr = addr}
    );
    const VlcbNetSocketErr err = vlcb_net_sock_dgram_Send(module->socket, &packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      // todo: log
      return;
    }
    module->config.nodeAddr = VLCB_NODE_ADDR_UNINITIALIZED;
  }

  module->canCommunicate = false;
  module->config.state = VLCB_MODULE_STATE_UNINITIALIZED;
}

inline void HandleUninitializedMode(
  VlcbModule *const module,
  const VlcbPacketDatagram *const packet
) {
  if (packet->opc == VLCB_OPC_QUERY_NODE_INFO) {
    VlcbPacketDatagram packet;
    vlcb_net_pkt_dgram_module_ReleaseNodeNumber_Serialize(
      &packet,
      (VlcbNetDgramReleaseNodeNumber) {.addr = addr}
    );
    const VlcbNetSocketErr err = vlcb_net_sock_dgram_Send(module->socket, &packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      // todo: log
    }
  }
}

inline void EnterSetupMode(VlcbModule *const module) {

  module->canCommunicate = false;
  module->config.state = VLCB_MODULE_STATE_SETUP;
}

inline void ModuleStatePoll(
  VlcbModule *const module,
  VlcbNetSocketDatagram *const packet
) {
  const VlcbModuleState prevState = module->state.currentState;

  switch (prevState) {
    case VLCB_MODULE_STATE_ENTERING_UNINITIALIZED:
      return EnterUninitializedMode(module);
    case VLCB_MODULE_STATE_UNINITIALIZED:
      return HandleUninitializedMode(module, packet);
    case VLCB_MODULE_STATE_ENTERING_SETUP:
      return EnterSetupMode(module);
  }

  const VlcbModuleState currentState = module->state.currentState;
  if (prevState != currentState) {
    module->config.state = currentState;
    _INTERFACE_CALL(module->ui, IndicateState, currentState);
  }
}