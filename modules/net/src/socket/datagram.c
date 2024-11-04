#include "vlcb/net/socket/datagram.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/vlcb.h"
#include "vlcb/net/socket.h"
#include "vlcb/net/storage/packet_buf.h"
#include "vlcb/platform/interface.h"

bool SupportsProtocol(VlcbNetProtocol proto) {
  return proto == VLCB_NET_PROTO_DATAGRAM;
}

VlcbNetSocketProcessErr ProcessPacket(const VlcbNetSocketDatagram *const self,
                                      const VlcbNetPacket *const packet) {
  assert(self != NULL && packet != NULL &&
         packet->proto == VLCB_NET_PROTO_DATAGRAM && self->rxBuf != NULL);

  VlcbNetPacketDatagram dgramPacket;
  VlcbNetPacketDatagramConstructErr err = vlcb_net_pkt_dgram_New(
      packet->opc, packet->payload_len, &packet->payload, &dgramPacket);
  if (err != VLCB_DGRAM_PKT_CONSTRUCT_ERR_OK) {
    switch (err) {
    case VLCB_DGRAM_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE:
      return VLCB_NET_SOCK_PROC_ERR_PAYLOAD_TOO_LARGE;
    default:
      return VLCB_NET_SOCK_PROC_ERR_UNKNOWN;
    }
  }

  int res = vlcb_net_packetbuf_Push(self->rxBuf, &dgramPacket);
  if (res == -1) {
    return VLCB_NET_SOCK_PROC_ERR_RX_BUF_FULL;
  }

  return VLCB_NET_SOCK_PROC_ERR_OK;
}

VlcbNetSocketDispatchErr DispatchPacket(const VlcbNetSocketDatagram *const self,
                                        VlcbNetPacket *const packet) {
  assert(self != NULL && packet != NULL && self->txBuf != NULL);

  VlcbNetPacketDatagram dgramPacket;
  int res = vlcb_net_packetbuf_Pop(self->txBuf, &dgramPacket);
  if (res == -1) {
    return VLCB_NET_SOCK_DISP_ERR_WOULD_BLOCK;
  }

  vlcb_net_pkt_NewUnchecked(VLCB_NET_PROTO_DATAGRAM, dgramPacket.opc,
                            dgramPacket.payload_len, &dgramPacket.payload,
                            packet);

  return VLCB_NET_SOCK_DISP_ERR_OK;
}

_INTERFACE_VTABLE_DEFINE(
    IVlcbNetSocket,
    _INTERFACE_VTABLE_METHOD(SupportsProtocol, SupportsProtocol, bool,
                             VlcbNetProtocol),
    _INTERFACE_VTABLE_METHOD(ProcessPacket, ProcessPacket,
                             VlcbNetSocketProcessErr,
                             _INTERFACE_SELF_PTR_MUT(IVlcbNetSocket),
                             const VlcbNetPacket *const),
    _INTERFACE_VTABLE_METHOD(DispatchPacket, DispatchPacket,
                             VlcbNetSocketDispatchErr,
                             _INTERFACE_SELF_PTR_MUT(IVlcbNetSocket),
                             VlcbNetPacket *const));

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(VlcbPacketBuf *const rxBuf,
                                              VlcbPacketBuf *const txBuf) {
  assert(rxBuf != NULL && txBuf != NULL);
  return (VlcbNetSocketDatagram){_INTERFACE_ASSIGN_VTABLE(IVlcbNetSocket),
                                 .rxBuf = rxBuf, .txBuf = txBuf};
}

VlcbNetSocketDgramSendErr
vlcb_net_sock_dgram_Send(VlcbNetSocketDatagram *const sock,
                         const VlcbNetPacketDatagram *const packet) {
  assert(sock != NULL && packet != NULL && sock->txBuf != NULL);

  int res = vlcb_net_packetbuf_Push(sock->txBuf, packet);
  if (res == -1) {
    return VLCB_NET_SOCK_DGRAM_SEND_ERR_BUF_FULL;
  }
  return VLCB_NET_SOCK_DGRAM_SEND_ERR_OK;
}

VlcbNetSocketDgramRecvErr
vlcb_net_sock_dgram_Recv(VlcbNetSocketDatagram *const sock,
                         VlcbNetPacketDatagram *const packet) {
  assert(sock != NULL && packet != NULL && sock->rxBuf != NULL);
  int res = vlcb_net_packetbuf_Pop(sock->rxBuf, packet);
  if (res == -1) {
    return VLCB_NET_SOCK_DGRAM_RECV_ERR_WOULD_BLOCK;
  }
  return VLCB_NET_SOCK_DGRAM_RECV_ERR_OK;
}

void vlcb_net_sock_dgram_Flush(VlcbNetSocketDatagram *const sock,
                               const VlcbNetSockDgramFlushMode mode) {
  assert(sock != NULL && sock->rxBuf != NULL && sock->txBuf != NULL);

  if (mode == VLCB_NET_SOCK_DGRAM_FLUSH_TX ||
      mode == VLCB_NET_SOCK_DGRAM_FLUSH_BOTH) {
    vlcb_net_packetbuf_Reset(sock->txBuf);
  }

  if (mode == VLCB_NET_SOCK_DGRAM_FLUSH_RX ||
      mode == VLCB_NET_SOCK_DGRAM_FLUSH_BOTH) {
    vlcb_net_packetbuf_Reset(sock->rxBuf);
  }
}
