#pragma once

#include "../packet/datagram.h"
#include "../storage/packet_buf.h"
#include "../socket.h"
#include "../addr.h"

#define VLCB_SOCK_DGRAM_BUF(name, size)                      \
  unsigned char data_##name[sizeof(VlcbPacketDatagram) * size]; \
  VlcbPacketBuf name =                                          \
      vlcb_net_packetbuf_New(data_##name, size, sizeof(VlcbPacketDatagram));

typedef struct {
  VlcbPacketBuf *const rxBuf;
  VlcbPacketBuf *const txBuf;
  const VlcbNetHwAddr *addr;
} VlcbNetSocketDatagram;

VlcbNetSocket vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *const sock);

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(
    VlcbPacketBuf *const rxBuf, VlcbPacketBuf *const txBuf);

VlcbNetSocketErr vlcb_net_sock_dgram_Send(VlcbNetSocketDatagram *const sock, const VlcbPacketDatagram *const packet);
VlcbNetSocketErr vlcb_net_sock_dgram_Recv(VlcbNetSocketDatagram *const sock, VlcbPacketDatagram *const packet);