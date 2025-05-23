#pragma once

#include "vlcb/net/socket.h"
#include "vlcb/net/storage/packet_buf.h"
#include "vlcb/net/wire.h"
#include "vlcb/platform/interface.h"
#include <stdint.h>

#define VLCB_NET_SOCK_DGRAM_BUF(name, size)                                    \
  uint8_t                                                                      \
      name##_data[sizeof(VlcbPacketBuf) + sizeof(VlcbPacketDatagram) * size];  \
  vlcb_net_packetbuf_Init(name##_data, size, sizeof(VlcbPacketDatagram));      \
  VlcbPacketBuf *const name = (VlcbPacketBuf *const)name##_data;

typedef struct {
  _INTERFACE_IMPLEMENT(IVlcbNetSocket);
  VlcbPacketBuf *const rxBuf;
  VlcbPacketBuf *const txBuf;
  VlcbNetWireEndpoint endpoint;
} VlcbNetSocketDatagram;

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(VlcbPacketBuf *const rxBuf,
                                              VlcbPacketBuf *const txBuf,
                                              VlcbNetWireEndpoint endpoint);

typedef enum {
  VLCB_NET_SOCK_DGRAM_SEND_ERR_OK = 0,
  VLCB_NET_SOCK_DGRAM_SEND_ERR_BUF_FULL,
  VLCB_NET_SOKC_DGRAM_SEND_ERR_COUNT,
} VlcbNetSocketDgramSendErr;
vlcb_error vlcb_net_sock_dgram_SendErrToStr(VlcbNetSocketDgramSendErr err);

typedef enum {
  VLCB_NET_SOCK_DGRAM_RECV_ERR_OK = 0,
  VLCB_NET_SOCK_DGRAM_RECV_ERR_WOULD_BLOCK,
  VLCB_NET_SOKC_DGRAM_RECV_ERR_COUNT,
} VlcbNetSocketDgramRecvErr;
vlcb_error vlcb_net_sock_dgram_SendErrToStr(VlcbNetSocketDgramSendErr err);

VlcbNetSocketDgramSendErr
vlcb_net_sock_dgram_Send(VlcbNetSocketDatagram *const sock,
                         const VlcbNetPacket *const packet);
VlcbNetSocketDgramRecvErr
vlcb_net_sock_dgram_Recv(VlcbNetSocketDatagram *const sock,
                         VlcbNetPacket *const packet);

static inline IVlcbNetSocket *const
vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *const sock) {

  return (IVlcbNetSocket *)sock;
}

typedef enum {
  VLCB_NET_SOCK_DGRAM_FLUSH_BOTH,
  VLCB_NET_SOCK_DGRAM_FLUSH_TX,
  VLCB_NET_SOCK_DGRAM_FLUSH_RX,
} VlcbNetSockDgramFlushMode;

void vlcb_net_sock_dgram_Flush(VlcbNetSocketDatagram *const sock,
                               const VlcbNetSockDgramFlushMode mode);
