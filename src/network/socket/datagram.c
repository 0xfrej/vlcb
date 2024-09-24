#include "datagram.h"

#include <assert.h>
#include <stdbool.h>

#include "../../shared/interface.h"
#include "socket.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(VlcbNetDatagramSocket *const self,
                               const VlcbPacket *const packet) {
  assert(self && packet);

  int res = vlcb_net_packetbuf_Push(self->rx_buf, &packet);
  if (res == -1) {
    return VLCB_NET_SOCK_ERR_RX_BUF_FULL;
  }

  return VLCB_NET_SOCK_ERR_OK;
}

bool DispatchPacket(VlcbNetDatagramSocket *const self,
                    VlcbPacket *const packet) {
  assert(self && packet);

  VlcbDatagramPacket datagram_packet;
  int res = vlcb_net_packetbuf_Pop(self->tx_buf, &datagram_packet);
  if (res == -1) {
    return false;
  }

  vlcb_pkt_NewPacketUnchecked(VLCB_PROTO_DATAGRAM, datagram_packet.opc,
                              datagram_packet.payload_len,
                              &datagram_packet.payload, packet);

  return true;
}

VlcbNetSocket vlcb_net_sock_datagram_Upcast(VlcbNetDatagramSocket *sock) {
  _TYPE_UPCAST_METHOD_PTR_SIG(SupportsProtocol, bool, VlcbProtocol);
  _TYPE_UPCAST_METHOD_PTR_SIG(ProcessPacket, VlcbNetSocketErr,
                              VlcbNetDatagramSocket *const,
                              const VlcbPacket *const);
  _TYPE_UPCAST_METHOD_PTR_SIG(DispatchPacket, bool,
                              VlcbNetDatagramSocket *const, VlcbPacket *const);
  _TYPE_UPCAST_VTABLE_DEF(
      tc, VlcbNetSocketTrait,
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(SupportsProtocol, SupportsProtocol, bool,
                                       VlcbProtocol),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(ProcessPacket, ProcessPacket,
                                       VlcbNetSocketErr, void *const,
                                       const VlcbPacket *const),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(DispatchPacket, DispatchPacket, bool,
                                       void *const, VlcbPacket *const));
  return (VlcbNetSocket){.tc = &tc, .self = sock};
}

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf *const rx_buf, VlcbPacketBuf *const tx_buf) {
  return (VlcbNetDatagramSocket){.rx_buf = rx_buf, .tx_buf = tx_buf};
}
