#pragma once

#include "../packet/datagram.h"
#include "../packet/vlcb.h"
#include "../storage/packet_buf.h"
#include "socket.h"

#define VLCB_SOCK_DGRAM_BUF(name, size)                      \
  unsigned char data_##name[sizeof(VlcbPacketDatagram) * size]; \
  VlcbPacketBuf name =                                          \
      vlcb_net_packetbuf_New(data_##name, size, sizeof(VlcbPacketDatagram));

typedef struct {
  VlcbPacketBuf *const rx_buf;
  VlcbPacketBuf *const tx_buf;
} VlcbNetSocketDatagram;

VlcbNetSocket vlcb_net_sock_dgram_Upcast(VlcbNetSocketDatagram *const sock);

VlcbNetSocketDatagram vlcb_net_sock_dgram_New(
    VlcbPacketBuf *const rx_buf, VlcbPacketBuf *const tx_buf);
