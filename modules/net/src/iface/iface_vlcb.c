#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "iface_can.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/log.h"

void ProcessVlcbPacket(VlcbNetIface *const iface, VlcbNetPacket *const packet) {
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);
  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);

    VlcbNetSocketProcessErr err =
        _INTERFACE_PTR_CALL(sock, ProcessPacket, packet);
    if (err != VLCB_NET_SOCK_PROC_ERR_OK) {
      VLCBLOG_ERROR(vlcb_net_sock_ProcessErrToStr(err));
    }
  }
}

VlcbNetAdptErr DispatchVlcbPacket(VlcbNetIface *const iface,
                                  const VlcbNetAdptCaps caps,
                                  const VlcbNetPacket *const packet) {
  switch (caps.medium) {
  case VLCB_MEDIUM_CAN:
    return DispatchCanPacket(iface, packet);
    break;
  default:
    assert(false /* unimplemented behavior guard */);
  }
}
