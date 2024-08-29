#include "iface_vlcb.h"

#include <stddef.h>
#include <stdint.h>

void ProcessVlcbPacket(VlcbNetIface *const iface,
                       VlcbNetSocketList *const sockets,
                       VlcbPacket *const packet) {
  VlcbProtocol proto = vlcb_pkt_DetectProtocol(packet->opc);

  for (uint8_t i = 0; i < sockets->len; i++) {
    VlcbNetSocket *const sock = &sockets->list[i];

    if (!sock->tc->SupportsProtocol(proto)) {
      continue;
    }

    VlcbNetSocketErr err = sock->tc->ProcessPacket(sock->self, packet);
    if (err != VLCB_NET_SOCK_ERR_OK) {
      // TODO: handle error
    }
  }
}
