#include "datagram.h"

#include "socket.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(VlcbNetDatagramSocket* self,
                               const VlcbPacket* const packet) {
  // TODO: if full return full error

  vlcb_net_packetbuf_Push(self->rx_buf, &packet);
}

VlcbNetSocketErr DispatchPacket(VlcbNetDatagramSocket* self) {}

// TODO: move into a macro
const VlcbNetSocketTrait impl = {
    .SupportsProtocol = (bool (*const)(VlcbProtocol))(SupportsProtocol),

    .ProcessPacket = (VlcbNetSocketErr(*const)(void*, const VlcbPacket* const))(
        ProcessPacket),
    .DispatchPacket = (VlcbNetSocketErr(*const)(void*))(DispatchPacket),
};

VlcbNetSocket vlcb_net_sock_UpcastDatagram(VlcbNetDatagramSocket* sock) {
  return (VlcbNetSocket){
      .self = (void*)sock,
      .tc = &impl,
  };
}

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf const* rx_buf, VlcbPacketBuf const* tx_buf) {
  return (VlcbNetDatagramSocket){.rx_buf = rx_buf, .tx_buf = tx_buf};
}
