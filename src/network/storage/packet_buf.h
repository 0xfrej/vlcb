#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct VlcbPacketBuf VlcbPacketBuf;

VlcbPacketBuf vlcb_net_packetbuf_New(void *const buf, size_t maxlen,
                                     size_t bucket_size);
void vlcb_net_packetbuf_Reset(VlcbPacketBuf *c);
bool vlcb_net_packetbuf_IsEmpty(VlcbPacketBuf *c);
bool vlcb_net_packetbuf_IsFull(VlcbPacketBuf *c);
size_t vlcb_net_packetbuf_Capacity(VlcbPacketBuf *c);
size_t vlcb_net_packetbuf_BucketSize(VlcbPacketBuf *c);
int vlcb_net_packetbuf_Push(VlcbPacketBuf *c, void *data);
int vlcb_net_packetbuf_Pop(VlcbPacketBuf *c, void *data);
