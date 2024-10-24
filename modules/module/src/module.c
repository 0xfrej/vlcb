#include "module.h"

#include <assert.h>

#include "vlcb/net/packet/datagram.h"
#include "vlcb/platform/interface.h"

#include "state_machine.h"

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
  state_Dispatch(module, (ModuleStateEvent){.sig = MSE_INIT});
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

  _INTERFACE_CALL(module->ui, Poll, now);
}
