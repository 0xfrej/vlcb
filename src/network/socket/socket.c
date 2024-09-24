#include "socket.h"

#include <assert.h>
#include <stdbool.h>

VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *list,
                                         size_t size) {
  assert(list && size);

  return (VlcbNetSocketList){
      .size = size,
      .ptr = list,
      .len = 0,
  };
}

void vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                               VlcbNetSocketHandle sock) {
  assert(list && list->len < list->size);

  list->ptr[list->len++] = sock;
}

VlcbNetSocketListIter vlcb_net_sock_list_GetIterator(
    const VlcbNetSocketList *const list) {
  assert(list);
  return (VlcbNetSocketListIter){
      .list = list,
      .pointer = 0,
  };
}

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *const iter) {
  assert(iter);
  iter->pointer = 0;
}

bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *const iter) {
  assert(iter);

  return iter->pointer < (iter->list->len - 1);
}

VlcbNetSocketHandle vlcb_net_sock_list_iter_Next(
    VlcbNetSocketListIter *const iter) {
  assert(iter && vlcb_net_sock_list_iter_HasNext(iter));

  return iter->list->ptr[iter->pointer++];
}
