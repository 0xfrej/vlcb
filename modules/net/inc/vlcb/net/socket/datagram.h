#pragma once

#include "../addr.h"
#include "../packet/datagram.h"
#include "../socket.h"
#include "../storage/packet_buf.h"
#include "vlcb/platform/interface.h"

#define VLCB_NET_SOCK_DGRAM_BUF(name, size)                                    \
  uint8_t                                                                      \
      name##_data[sizeof(VlcbPacketBuf) + sizeof(VlcbPacketDatagram) * size];  \
  vlcb_net_packetbuf_Init(name##_data, size, sizeof(VlcbPacketDatagram));      \
  VlcbPacketBuf *const name = (VlcbPacketBuf *const)name##_data;

typedef struct {
  _INTERFACE_IMPLEMENT(IVlcbNetSocket);
  VlcbPacketBuf *const rxBuf;
  VlcbPacketBuf *const txBuf;
  const VlcbNetHwAddr *addr;
} VlcbNetSocketDatagram;

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(VlcbPacketBuf *const rxBuf,
                                              VlcbPacketBuf *const txBuf);

VlcbNetSocketErr
vlcb_net_sock_dgram_Send(VlcbNetSocketDatagram *const sock,
                         const VlcbPacketDatagram *const packet);
VlcbNetSocketErr vlcb_net_sock_dgram_Recv(VlcbNetSocketDatagram *const sock,
                                          VlcbPacketDatagram *const packet);

static inline IVlcbNetSocket *const
vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *const sock) {
  return (IVlcbNetSocket *)sock;
}
