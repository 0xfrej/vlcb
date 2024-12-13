#include "vlcb/net/storage/packet_buf.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

void vlcb_net_packetbuf_Init(VlcbPacketBuf *const c, size_t maxlen,
                             size_t bucketSize) {
  assert(c != NULL && maxlen > 0 && bucketSize > 0);
  c->tail = 0;
  c->head = 0;
  c->bucketSize = bucketSize;
  c->maxlen = maxlen;
  c->isLocked = false;
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

  return c->bucketSize;
}

int vlcb_net_packetbuf_Push(VlcbPacketBuf *const c, const void *data) {
  assert(c != NULL && data != NULL);

  if (c->isLocked) {
    return -2;
  }

  int next;

  next = c->head + 1;

  if (next >= c->maxlen) {
    next = 0;
  }

  if (next == c->tail) {
    return -1;
  }

  memcpy(&c->buffer[c->head], data, c->bucketSize);
  c->head = next;
  return 0;
}

int vlcb_net_packetbuf_Pop(VlcbPacketBuf *const c, void *data) {
  assert(c != NULL && data != NULL);
  int next;

  if (c->isLocked) {
    return -2;
  }

  if (vlcb_net_packetbuf_IsEmpty(c)) {
    return -1;
  }

  next = c->tail + 1;
  if (next >= c->maxlen) {
    next = 0;
  }

  memcpy(data, &c->buffer[c->tail], c->bucketSize);
  c->tail = next;
  return 0;
}

int vlcb_net_packetbuf_PopDeferred(VlcbPacketBuf *const c,
                                   VlcbPacketBufToken *const tok, void *data) {
  assert(c != NULL && tok != NULL && data != NULL);
  int next;

  if (c->isLocked) {
    return -2;
  }

  if (vlcb_net_packetbuf_IsEmpty(c)) {
    return -1;
  }

  tok->buf = c;
  c->isLocked = true;
  memcpy(data, &c->buffer[c->tail], c->bucketSize);
  return 0;
}

void vlcb_net_packetbuf_PopDeferredAccept(VlcbPacketBufToken tok) {
  assert(tok.buf != NULL);

  int next = tok.buf->tail + 1;
  if (next >= tok.buf->maxlen) {
    next = 0;
  }
  tok.buf->tail = next;

  tok.buf->isLocked = false;
  tok.buf = NULL;
}

void vlcb_net_packetbuf_PopDeferredRefuse(VlcbPacketBufToken tok) {
  assert(tok.buf != NULL);
  tok.buf->isLocked = false;
  tok.buf = NULL;
}
