#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../packet/vlcb.h"

typedef enum {
  VLCB_NET_SOCK_ERR_OK = 0,

  VLCB_NET_SOCK_ERR_RX_BUF_FULL,

  VLCB_NET_SOCK_ERR_COUNT,
} VlcbNetSocketErr;

typedef struct {
  bool (*SupportsProtocol)(VlcbProtocol protocol);
  VlcbNetSocketErr (*ProcessPacket)(void *, const VlcbPacket *const);
  VlcbNetSocketErr (*DispatchPacket)(void *);
} VlcbNetSocketTrait;

typedef struct {
  void *self;
  VlcbNetSocketTrait const *tc;
} VlcbNetSocket;

typedef VlcbNetSocket *VlcbNetSocketHandle;
typedef struct {
  const size_t size;
  VlcbNetSocketHandle *const ptr;
  size_t len;
} VlcbNetSocketList;

VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *list,
                                         size_t size);
void vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                               VlcbNetSocketHandle sock);

typedef struct {
  size_t pointer;
  VlcbNetSocketList *const list;
} VlcbNetSocketListIter;

VlcbNetSocketListIter vlcb_net_sock_list_GetIterator(
    VlcbNetSocketList *const list);

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *const iter);
bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *const iter);
VlcbNetSocketHandle vlcb_net_sock_list_iter_Next(
    VlcbNetSocketListIter *const iter);
