#include "../../../net/socket/socket.h"

#include <assert.h>
#include <stdbool.h>

VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *const list,
                                         size_t size) {
  assert(list != NULL);

  return (VlcbNetSocketList){
      .size = size,
      .ptr = list,
      .len = 0,
  };
}

void vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                               VlcbNetSocketHandle sock) {
  assert(list != NULL && list->len < list->size);

  list->ptr[list->len++] = sock;
}

VlcbNetSocketListIter vlcb_net_sock_list_GetIterator(
    const VlcbNetSocketList *const list) {
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

VlcbNetSocketHandle vlcb_net_sock_list_iter_Next(
    VlcbNetSocketListIter *const iter) {
  assert(iter != NULL && vlcb_net_sock_list_iter_HasNext(iter));

  return iter->list->ptr[iter->pointer++];
}

vlcb_error vlcb_net_sock_ErrToStr(VlcbNetSocketErr err) {
  assert(err > VLCB_NET_SOCK_ERR_OK && err < VLCB_NET_SOCK_ERR_COUNT);

  switch (err) {
    case VLCB_NET_SOCK_ERR_RX_BUF_FULL:
      return "socket rx buffer is full, dropping the packet";
  }
  assert(false /* unhandled case guard */);
}
