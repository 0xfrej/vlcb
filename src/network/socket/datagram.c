#include "datagram.h"

#include "../../shared/interface.h"
#include "socket.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(VlcbNetDatagramSocket *self,
                               const VlcbPacket *const packet) {
  // TODO: if full return full error

  int res = vlcb_net_packetbuf_Push(self->rx_buf, &packet);
  if (res == -1) {
    return VLCB_NET_SOCK_ERR_
  }
}

VlcbNetSocketErr DispatchPacket(VlcbNetDatagramSocket *self) {}

VlcbNetSocket vlcb_net_sock_datagram_Upcast(VlcbNetDatagramSocket *sock) {
  _TYPE_UPCAST_METHOD_PTR_SIG(SupportsProtocol, bool, VlcbProtocol);
  _TYPE_UPCAST_METHOD_PTR_SIG(ProcessPacket, VlcbNetSocketErr,
                              VlcbNetDatagramSocket *, const VlcbPacket *const);
  _TYPE_UPCAST_METHOD_PTR_SIG(DispatchPacket, VlcbNetSocketErr,
                              VlcbNetDatagramSocket *);
  _TYPE_UPCAST_VTABLE_DEF(
      tc, VlcbNetSocketTrait,
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(SupportsProtocol, SupportsProtocol, bool,
                                       VlcbProtocol),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(ProcessPacket, ProcessPacket,
                                       VlcbNetSocketErr, void *,
                                       const VlcbPacket *const),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(DispatchPacket, DispatchPacket,
                                       VlcbNetSocketErr, void *));
  return (VlcbNetSocket){.tc = &tc, .self = sock};
}

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf *const rx_buf, VlcbPacketBuf *const tx_buf) {
  return (VlcbNetDatagramSocket){.rx_buf = rx_buf, .tx_buf = tx_buf};
}
