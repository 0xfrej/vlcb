#include "vlcb/net/socket.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

inline VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *const list,
                                                size_t size) {
  assert(list != NULL);

  return (VlcbNetSocketList){
      .capacity = size,
      .buf = list,
      .len = 0,
  };
}

int vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                              VlcbNetSocketHandle sock) {
  assert(list != NULL);

  if (list->len < list->capacity - 1) {
    return 1;
  }

  list->buf[list->len++] = sock;
  return 0;
}

int vlcb_net_sock_list_Remove(VlcbNetSocketList *const list,
                              VlcbNetSocketHandle sock) {
  assert(list != NULL);

  size_t i = 0;
  size_t len = list->len;
  VlcbNetSocketHandle *const buf = list->buf;
  for (; i < len; i++) {
    if (buf[i] == sock) {
      break;
    }
  }

  for (size_t y = i + 1; y < len; y++) {
    buf[y - 1] = buf[y];
  }
  return 0;
}

VlcbNetSocketListIter
vlcb_net_sock_list_GetIterator(const VlcbNetSocketList *const list) {
  assert(list != NULL);
  return (VlcbNetSocketListIter){
      .list = list,
      .pointer = 0,
  };
}

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *const iter) {
  assert(iter != NULL);
  iter->pointer = 0;
}

bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *const iter) {
  assert(iter != NULL);

  return iter->pointer < (iter->list->len - 1);
}

VlcbNetSocketHandle
vlcb_net_sock_list_iter_Next(VlcbNetSocketListIter *const iter) {
  assert(iter != NULL && vlcb_net_sock_list_iter_HasNext(iter));

  return iter->list->buf[iter->pointer++];
}

vlcb_error vlcb_net_sock_ProcessErrToStr(VlcbNetSocketProcessErr err) {
  assert(err > VLCB_NET_SOCK_PROC_ERR_OK && err < VLCB_NET_SOCK_PROC_ERR_COUNT);

  switch (err) {
  case VLCB_NET_SOCK_PROC_ERR_RX_BUF_FULL:
    return "socket rx buffer is full, dropping packet";
  }
  assert(false /* unhandled case guard */);
}
