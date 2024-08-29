#pragma once

#include <stdbool.h>
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

typedef struct VlcbNetSocketList VlcbNetSocketList;
typedef VlcbNetSocket *VlcbNetSocketHandle;

VlcbNetSocketList vlcb_net_sock_list_New();
void vlcb_net_sock_list_Insert(VlcbNetSocketList *list,
                               VlcbNetSocketHandle sock);
void vlcb_net_sock_list_Remove(VlcbNetSocketList *list,
                               VlcbNetSocketHandle sock);

typedef struct VlcbNetSocketListIter VlcbNetSocketListIter;

VlcbNetSocketListIter vlcb_net_sock_list_GetIterator(VlcbNetSocketList *list);

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *iter);
bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *iter);
VlcbNetSocketHandle vlcb_net_sock_list_iter_Next(VlcbNetSocketListIter *iter);
