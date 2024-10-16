#include "vlcb/net/socket/datagram.h"

#include <assert.h>
#include <stdbool.h>

#include "vlcb/platform/interface.h"

bool SupportsProtocol(VlcbProtocol proto) {
  return proto == VLCB_PROTO_DATAGRAM;
}

VlcbNetSocketErr ProcessPacket(const VlcbNetSocketDatagram *const self,
                               const VlcbPacket *const packet) {
  assert(self != NULL && packet != NULL);
  if (self->addr == NULL) {
    return VLCB_NET_SOCK_ERR_OK;
  }

  int res = vlcb_net_packetbuf_Push(self->rxBuf, &packet);
  if (res == -1) {
    return VLCB_NET_SOCK_ERR_RX_BUF_FULL;
  }

  return VLCB_NET_SOCK_ERR_OK;
}

bool DispatchPacket(const VlcbNetSocketDatagram *const self,
                    VlcbPacket *const packet) {
  assert(self != NULL && packet != NULL);

  if (self->addr == NULL) {
    return VLCB_NET_SOCK_ERR_OK;
  }

  VlcbPacketDatagram datagram_packet;
  int res = vlcb_net_packetbuf_Pop(self->txBuf, &datagram_packet);
  if (res == -1) {
    return false;
  }

  vlcb_net_pkt_NewUnchecked(VLCB_PROTO_DATAGRAM, datagram_packet.opc,
                              datagram_packet.payload_len,
                              &datagram_packet.payload, packet);

  return true;
}

int Bind(VlcbNetSocketDatagram *const sock, const VlcbNetHwAddr *const addr) {
  assert(sock != NULL && addr != NULL);
  if (sock->addr == NULL) {
    sock->addr = addr;
    return 0;
  }
  return 1;
}

VlcbNetSocket vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *sock) {
  _TYPE_UPCAST_METHOD_PTR_SIG(SupportsProtocol, bool, VlcbProtocol);
  _TYPE_UPCAST_METHOD_PTR_SIG(ProcessPacket, VlcbNetSocketErr,
                              VlcbNetSocketDatagram *const,
                              const VlcbPacket *const);
  _TYPE_UPCAST_METHOD_PTR_SIG(DispatchPacket, bool,
                              VlcbNetSocketDatagram *const, VlcbPacket *const);
  _TYPE_UPCAST_METHOD_PTR_SIG(Bind, bool,
                              VlcbNetSocketDatagram *const, const VlcbNetHwAddr *const);
  _TYPE_UPCAST_VTABLE_DEF(
      tc, VlcbNetSocketTrait,
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(SupportsProtocol, SupportsProtocol, bool,
                                       VlcbProtocol),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(ProcessPacket, ProcessPacket,
                                       VlcbNetSocketErr, void *const,
                                       const VlcbPacket *const),
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(DispatchPacket, DispatchPacket, bool,
                                       void *const, VlcbPacket *const)
                                       ,
      _TYPE_UPCAST_VTABLE_METHOD_ENTRY(Bind, Bind, int,
                                       void *const, const VlcbNetHwAddr *const)
                                       );
  return (VlcbNetSocket){.tc = &tc, .self = sock};
}

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(
    VlcbPacketBuf *const rxBuf, VlcbPacketBuf *const txBuf) {
  assert(rxBuf !=NULL && txBuf!=NULL);
  return (VlcbNetSocketDatagram){.rxBuf = rxBuf, .txBuf = txBuf, .addr = NULL};
}

VlcbNetSocketErr vlcb_net_sock_dgram_Send(VlcbNetSocketDatagram *const sock, const VlcbPacketDatagram *const packet) {
  assert(sock != NULL);


}

VlcbNetSocketErr vlcb_net_sock_dgram_Recv(VlcbNetSocketDatagram *const sock, VlcbPacketDatagram *const packet) {
  assert(sock != NULL && packet != NULL);


}