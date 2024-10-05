#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "../../../../shared/log.h"
#include "iface_can.h"

void ProcessVlcbPacket(VlcbNetIface *const iface,
                       VlcbPacket *const packet) {
  VlcbProtocol proto = vlcb_net_pkt_DetectProtocol(packet->opc);

  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);
  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);
    if (!sock->tc->SupportsProtocol(proto)) {
      continue;
    }

    VlcbNetSocketErr err = sock->tc->ProcessPacket(sock->self, packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      VLCBLOG_ERROR(vlcb_net_sock_ErrToStr(err));
    }
  }
}

VlcbNetAdptErr DispatchVlcbPacket(VlcbNetIface *const iface,
                                  const VlcbNetAdptCaps caps,
                                  const VlcbPacket *const packet) {
  switch (caps.medium) {
    case VLCB_MEDIUM_CAN:
      return DispatchCanPacket(iface, packet);
      break;
  }
  assert(false /* unimplemented behavior guard */);
}