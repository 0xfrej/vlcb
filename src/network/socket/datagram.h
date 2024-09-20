#pragma once

#include "../packet/vlcb.h"
#include "../storage/packet_buf.h"
#include "socket.h"

#define VLCB_DATAGRAM_SOCK_BUF(name, size)              \
  unsigned char data_##name[sizeof(VlcbPacket) * size]; \
  VlcbPacketBuf #name =                                 \
      vlcb_net_packetbuf_New(data_##name, size, sizeof(VlcbPacketBuf) * size);

typedef struct {
  VlcbPacketBuf const *rx_buf;
  VlcbPacketBuf const *tx_buf;
} VlcbNetDatagramSocket;

VlcbNetSocket vlcb_net_sock_datagram_Upcast(VlcbNetDatagramSocket *);

VlcbNetDatagramSocket vlcb_net_sock_NewDatagramSocket(
    VlcbPacketBuf const *rx_buf, VlcbPacketBuf const *tx_buf);
