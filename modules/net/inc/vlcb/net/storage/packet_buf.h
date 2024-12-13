#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
  size_t head;
  size_t tail;
  size_t maxlen;
  size_t bucketSize;
  bool isLocked;
  uint8_t buffer[];
} VlcbPacketBuf;

void vlcb_net_packetbuf_Init(VlcbPacketBuf *const c, size_t maxlen,
                             size_t bucketSize);
void vlcb_net_packetbuf_Reset(VlcbPacketBuf *const c);
bool vlcb_net_packetbuf_IsEmpty(VlcbPacketBuf *const c);
bool vlcb_net_packetbuf_IsFull(VlcbPacketBuf *const c);
size_t vlcb_net_packetbuf_Capacity(VlcbPacketBuf *const c);
size_t vlcb_net_packetbuf_BucketSize(VlcbPacketBuf *const c);
int vlcb_net_packetbuf_Push(VlcbPacketBuf *const c, const void *data);
int vlcb_net_packetbuf_Pop(VlcbPacketBuf *const c, void *data);

typedef struct {
  VlcbPacketBuf *buf;
} VlcbPacketBufToken;

int vlcb_net_packetbuf_PopDeferred(VlcbPacketBuf *const c,
                                   VlcbPacketBufToken *const tok, void *data);
void vlcb_net_packetbuf_PopDeferredAccept(VlcbPacketBufToken tok);
void vlcb_net_packetbuf_PopDeferredRefuse(VlcbPacketBufToken tok);
