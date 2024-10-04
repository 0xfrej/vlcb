#include "../../../net/storage/packet_buf.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

VlcbPacketBuf vlcb_net_packetbuf_New(void *const buf, size_t maxlen,
                                     size_t bucket_size) {
  assert(buf != NULL && maxlen > 0 && bucket_size > 0);

  return (VlcbPacketBuf){.buffer = buf,
                         .tail = 0,
                         .head = 0,
                         .bucket_size = bucket_size,
                         .maxlen = maxlen};
}

void vlcb_net_packetbuf_Reset(VlcbPacketBuf *const c) {
  assert(c != NULL);

  c->head = 0;
  c->tail = 0;
}

bool vlcb_net_packetbuf_IsEmpty(VlcbPacketBuf *const c) {
  assert(c != NULL);

  return c->head == c->tail;
}

bool vlcb_net_packetbuf_IsFull(VlcbPacketBuf *const c) {
  assert(c != NULL);

  size_t head = c->head + 1;
  if (head == c->maxlen) {
    head = 0;
  }

  return head == c->tail;
}

size_t vlcb_net_packetbuf_Capacity(VlcbPacketBuf *const c) {
  assert(c != NULL);

  size_t size = c->maxlen;

  if (!vlcb_net_packetbuf_IsFull(c)) {
    if (c->head >= c->tail) {
      size = c->head - c->tail;
    } else {
      size = c->maxlen + c->head - c->tail;
    }
  }

  return size;
}

size_t vlcb_net_packetbuf_BucketSize(VlcbPacketBuf *const c) {
  assert(c != NULL);

  return c->bucket_size;
}

int vlcb_net_packetbuf_Push(VlcbPacketBuf *const c, const void *data) {
  assert(c != NULL && data != NULL);

  int next;

  next = c->head + 1;

  if (next >= c->maxlen) {
    next = 0;
  }

  if (next == c->tail) {
    return -1;
  }

  memcpy(&c->buffer[c->head], data, c->bucket_size);
  c->head = next;
  return 0;
}

int vlcb_net_packetbuf_Pop(VlcbPacketBuf *const c, void *data) {
  assert(c != NULL && data != NULL);
  int next;

  if (vlcb_net_packetbuf_IsEmpty(c)) {
    return -1;
  }

  next = c->tail + 1;
  if (next >= c->maxlen) {
    next = 0;
  }

  memcpy(data, &c->buffer[c->tail], c->bucket_size);
  c->tail = next;
  return 0;
}
