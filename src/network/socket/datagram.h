#pragma once

#include "../packet/datagram.h"
#include "../packet/vlcb.h"
#include "../storage/packet_buf.h"
#include "socket.h"

#define VLCB_DATAGRAM_SOCK_BUF(name, size)                      \
  unsigned char data_##name[sizeof(VlcbDatagramPacket) * size]; \
  VlcbPacketBuf name =                                          \
      vlcb_net_packetbuf_New(data_##name, size, sizeof(VlcbDatagramPacket));

typedef struct {
  VlcbPacketBuf *const rx_buf;
  VlcbPacketBuf *const tx_buf;
} VlcbNetDatagramSocket;

VlcbNetSocket vlcb_net_sock_datagram_Upcast(VlcbNetDatagramSocket *);

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf *const rx_buf, VlcbPacketBuf *const tx_buf);
