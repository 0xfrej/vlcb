#include "vlcb/net/socket/datagram.h"

#include <assert.h>
#include <stdbool.h>

#include "vlcb/common/interface.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(VlcbNetSocketDatagram *const self,
                               const VlcbPacket *const packet) {
  assert(self && packet);

  int res = vlcb_net_packetbuf_Push(self->rx_buf, &packet);
  if (res == -1) {
    return VLCB_NET_SOCK_ERR_RX_BUF_FULL;
  }

  return VLCB_NET_SOCK_ERR_OK;
}

bool DispatchPacket(VlcbNetSocketDatagram *const self,
                    VlcbPacket *const packet) {
  assert(self && packet);

  VlcbPacketDatagram datagram_packet;
  int res = vlcb_net_packetbuf_Pop(self->tx_buf, &datagram_packet);
  if (res == -1) {
    return false;
  }

  vlcb_net_pkt_NewUnchecked(VLCB_PROTO_DATAGRAM, datagram_packet.opc,
                              datagram_packet.payload_len,
                              &datagram_packet.payload, packet);

  return true;
}

VlcbNetSocket vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *sock) {
  _TYPE_UPCAST_METHOD_PTR_SIG(SupportsProtocol, bool, VlcbProtocol);
  _TYPE_UPCAST_METHOD_PTR_SIG(ProcessPacket, VlcbNetSocketErr,
                              VlcbNetSocketDatagram *const,
                              const VlcbPacket *const);
  _TYPE_UPCAST_METHOD_PTR_SIG(DispatchPacket, bool,
                              VlcbNetSocketDatagram *const, VlcbPacket *const);
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

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(
    VlcbPacketBuf *const rx_buf, VlcbPacketBuf *const tx_buf) {
  return (VlcbNetSocketDatagram){.rx_buf = rx_buf, .tx_buf = tx_buf};
}
