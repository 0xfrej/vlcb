#include "module.h"

#include <assert.h>
#include <time.h>

#include "state_machine.h"
#include "vlcb/common/vlcb_defs.h"
#include "vlcb/module.h"
#include "vlcb/module/state.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/time.h"

#ifndef VLCB_MODULE_HEARTBEAT_MS
#define VLCB_MODULE_HEARTBEAT_MS 5000
#endif /* ifndef VLCB_MODULE_HEARTBEAT_MS */

static inline void HandleHeartbeat(VlcbModule *const self, const clock_t now) {
  if (self->sm.state == VLCB_MODULE_STATE_NORMAL &&
      self->config.operationFlags & VLCB_MODULE_FLAGS_HEARTBEAT &&
      (self->lastHeartbeat == 0 ||
       vlcb_platform_time_DiffInMs(self->lastHeartbeat, now) >=
           VLCB_MODULE_HEARTBEAT_MS)) {
    // TODO: send the packet
    self->lastHeartbeat = now;
    self->heartbeatCount++;
  }
}

static inline void HandleMnsMessages(VlcbModule *const self,
                                     const VlcbPacketDatagram *const packet) {
  switch (packet->opc) {
  case VLCB_OPC_QUERY_NODE_PARAMETERS:
    // 10 - RQNP message - request for node parameters -- does not contain a NN
    // or EN, so only respond if we are in transition to Normal
    handleRequestNodeParameters();
    break;

  case VLCB_OPC_QUERY_NODE_PARAMETER_BY_INDEX:
    // 73 - RQNPN message -- request parameter by index number
    // index 0 = number of params available followed by each parameter as a
    // seperate PARAN respond with PARAN
    handleRequestNodeParameter(msg, nn);
    break;

  case VLCB_OPC_SET_NODE_NUMBER:
    // 42 - received SNN - set node number
    handleSetNodeNumber(msg, nn);
    break;

  case VLCB_OPC_REQUEST_NEW_NODE_NUMBER:
    // 50 - Another module has entered setup.
    // If we are in setup, abort (MNS Spec 3.2.1)

    if (instantMode == MODE_SETUP) {
      instantMode = module_config->currentMode;
      controller->indicateMode(module_config->currentMode);
    }
    break;

  case VLCB_OPC_QUERY_NODE_INFO:
    // 0D - this is probably a config recreate -- respond with PNN if we have a
    // node number DEBUG_SERIAL << F("> QNN received, my node number = ") <<
    // module_config->nodeNum << endl;

    if (module_config->nodeNum > 0) {
      // DEBUG_SERIAL << ("> responding with PNN message") << endl;
      controller->sendMessageWithNN(OPC_PNN, controller->getParam(PAR_MANU),
                                    controller->getParam(PAR_MTYP),
                                    controller->getParam(PAR_FLAGS));
    }
    break;

  case VLCB_OPC_QUERY_MODULE_NAME:
    // 11 - request for node module name, excluding "CAN" prefix
    // sent during module transition, so no node number check
    // DEBUG_SERIAL << F("> RQMN received") << endl;

    // only respond if in transition to Normal, i.e. Setup mode, or in learn
    // mode.

    if (instantMode == MODE_SETUP ||
        (controller->getParam(PAR_FLAGS) & PF_LRN)) {
      // respond with NAME
      VlcbMessage response;
      response.len = 8;
      response.data[0] = OPC_NAME;
      memcpy(response.data + 1, controller->getModuleName(), 7);
      controller->sendMessage(&response);
    }
    break;

  case OPC_RQSD:
    // 78 - Request Service Definitions.
    handleRequestServiceDefinitions(msg, nn);
    break;

  case OPC_RDGN:
    // 87 - Request Diagnostic Data
    handleRequestDiagnostics(msg, nn);
    break;

  case OPC_MODE:
    // 76 - Set Operating Mode
    handleModeMessage(msg, nn);
    break;

  case OPC_NNRSM:
    // 4F - reset to manufacturer's defaults
    if (nn == module_config->nodeNum) {
      controller->sendMessageWithNN(OPC_NNREL); // release node number first
      module_config->resetModule();
    }
    break;

  case OPC_NNRST:
    // 5E - software reset
    if (nn == module_config->nodeNum) {
      module_config->reboot();
    }
    break;
  }
}

VlcbModule vlcb_module_New(VlcbNetIface *const iface,
                           VlcbNetSocketDatagram *const socket,
                           const VlcbModuleUi ui,
                           const VlcbModuleParams params) {
  assert(iface != NULL && socket != NULL && _INTERFACE_IS_VALID(ui));

  return (VlcbModule){
      .iface = iface,
      .socket = socket,
      .params = params,
      .ui = ui,
      .config =
          {
              .operationFlags = 0,
              .state = VLCB_MODULE_STATE_UNINITIALIZED,
              .hwAddr = 0,
              .nodeAddr = VLCB_NODE_ADDR_UNINITIALIZED,
          },
  };
}

void vlcb_module_Init(VlcbModule *const module, const clock_t now) {
  assert(module != NULL);
  // todo: load config from persistent storage
  state_Dispatch(module, (ModuleStateEvent){.sig = MSE_INIT}, now);
  _INTERFACE_CALL(module->ui, Poll, now);
}

int vlcb_module_BindSock(const VlcbModule *const module,
                         const VlcbNetSocket *const socket) {
  assert(module != NULL && _INTERFACE_PTR_IS_VALID(socket));
  return _INTERFACE_PTR_CALL(socket, Bind, &module->config.hwAddr);
}

void vlcb_module_Poll(VlcbModule *const module, const clock_t now) {
  assert(module != NULL && module->iface != NULL);

  VlcbPacketDatagram packet;
  VlcbPacketDatagram *const packetPtr = &packet;

  while (1) {
    const VlcbNetSocketErr err =
        vlcb_net_sock_dgram_Recv(module->socket, packetPtr);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      if (err == VLCB_NET_SOCK_ERR_WOULD_BLOCK) {
        break;
      }
    }
  }

  HandleHeartbeat(module, now);

  _INTERFACE_CALL(module->ui, Poll, now);
}
