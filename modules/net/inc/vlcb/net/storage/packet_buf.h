#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  void *const buffer;
  size_t head;
  size_t tail;
  const size_t maxlen;
  const size_t bucket_size;
} VlcbPacketBuf;

VlcbPacketBuf vlcb_net_packetbuf_New(void *const buf, size_t maxlen,
                                     size_t bucket_size);
void vlcb_net_packetbuf_Reset(VlcbPacketBuf *const c);
bool vlcb_net_packetbuf_IsEmpty(VlcbPacketBuf *const c);
bool vlcb_net_packetbuf_IsFull(VlcbPacketBuf *const c);
size_t vlcb_net_packetbuf_Capacity(VlcbPacketBuf *const c);
size_t vlcb_net_packetbuf_BucketSize(VlcbPacketBuf *const c);
int vlcb_net_packetbuf_Push(VlcbPacketBuf *const c, const void *data);
int vlcb_net_packetbuf_Pop(VlcbPacketBuf *const c, void *data);
