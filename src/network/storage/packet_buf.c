#include "packet_buf.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

struct VlcbPacketBuf {
  void *const buffer;
  size_t head;
  size_t tail;
  const size_t maxlen;
  const size_t bucket_size;
};

VlcbPacketBuf vlcb_net_packetbuf_New(void *const buf, size_t maxlen,
                                     size_t bucket_size) {
  assert(buf && maxlen);

  return (VlcbPacketBuf){.buffer = buf,
                         .tail = 0,
                         .head = 0,
                         .bucket_size = bucket_size,
                         .maxlen = maxlen};
}

void vlcb_net_packetbuf_Reset(VlcbPacketBuf *c) {
  assert(c);

  c->head = 0;
  c->tail = 0;
}

bool vlcb_net_packetbuf_IsEmpty(VlcbPacketBuf *c) {
  assert(c);

  return c->head == c->tail;
}

bool vlcb_net_packetbuf_IsFull(VlcbPacketBuf *c) {
  assert(c);

  size_t head = c->head + 1;
  if (head == c->maxlen) {
    head = 0;
  }

  return head == c->tail;
}

size_t vlcb_net_packetbuf_Capacity(VlcbPacketBuf *c) {
  assert(c);

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

size_t vlcb_net_packetbuf_BucketSize(VlcbPacketBuf *c) {
  assert(c);

  return c->bucket_size;
}

int vlcb_net_packetbuf_Push(VlcbPacketBuf *c, void *data) {
  assert(c && c->buffer && data);

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

int vlcb_net_packetbuf_Pop(VlcbPacketBuf *c, void *data) {
  assert(c && c->buffer && data);
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
