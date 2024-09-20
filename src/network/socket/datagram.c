#include "datagram.h"

#include "socket.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(VlcbNetDatagramSocket *self,
                               const VlcbPacket *const packet) {
  // TODO: if full return full error

  vlcb_net_packetbuf_Push(self->rx_buf, &packet);
}

VlcbNetSocketErr DispatchPacket(VlcbNetDatagramSocket *self) {}

VlcbNetSocket vlcb_net_sock_datagram_Upcast(VlcbNetDatagramSocket *sock) {
  _TYPE_UPCAST_METHOD_PTR_SIG(SupportsProtocol, bool, VlcbProtocol)
  _TYPE_UPCAST_METHOD_PTR_SIG(ProcessPacket, VlcbNetSocketErr,
                              VlcbNetDatagramSocket *, const VlcbPacket *const)
  _TYPE_UPCAST_METHOD_PTR_SIG(DispatchPacket, VlcbNetSocketErr,
                              VlcbNetDatagramSocket *)
  _TYPE_UPCAST_VTABLE_DEF(
      tc, VlcbNetSocketTrait,
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(SupportsProtocol, SupportsProtocol, bool,
                                       VlcbProtocol),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(ProcessPacket, ProcessPacket, void *,
                                       const VlcbPacket *const),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(DispatchPacket, DispatchPacket, void *))
  return (VlcbNetSocket){.tc = &tc, .self = x};
}

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf const *rx_buf, VlcbPacketBuf const *tx_buf) {
  return (VlcbNetDatagramSocket){.rx_buf = rx_buf, .tx_buf = tx_buf};
}
