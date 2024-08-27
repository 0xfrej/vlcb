#include "iface_vlcb.h"

#include <stddef.h>
#include <stdint.h>

void ProcessVlcbPacket(VlcbNetIface *const iface,
                       VlcbNetSocketList *const sockets,
                       VlcbPacket *const packet) {
  VlcbProtocol proto = vlcb_pkt_DetectProtocol(packet->opc);

  for (uint8_t i = 0; i < sockets->len; i++) {
    VlcbNetSocket *const sock = &sockets->list[i];

    // TODO: check first if the socket handles this VlcbProtocol
    VlcbNetSocketErr err = sock->ingress(packet);
    if (err != ok) {
      // TODO: handle error
    }
  }
}
