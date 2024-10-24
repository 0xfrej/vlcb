#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "packet/vlcb.h"
#include "vlcb/platform/interface.h"
#include "vlcb/net/addr.h"

typedef enum {
  VLCB_NET_SOCK_ERR_OK = 0,

  VLCB_NET_SOCK_ERR_WOULD_BLOCK,

  VLCB_NET_SOCK_ERR_RX_BUF_FULL,
  VLCB_NET_SOCK_ERR_TX_BUF_FULL,

  VLCB_NET_SOCK_ERR_COUNT,
} VlcbNetSocketErr;

vlcb_error vlcb_net_sock_ErrToStr(VlcbNetSocketErr err);

_INTERFACE_DECLARE(VlcbNetSocket,
  _INTERFACE_METHOD_DECLARE(bool, SupportsProtocol, VlcbProtocol protocol)
  _INTERFACE_METHOD_DECLARE(VlcbNetSocketErr, ProcessPacket, _INTERFACE_SELF_PTR_MUT, const VlcbPacket *const packet)
  _INTERFACE_METHOD_DECLARE(bool, DispatchPacket, _INTERFACE_SELF_PTR_MUT, VlcbPacket *const packet)
  _INTERFACE_METHOD_DECLARE(int, Bind, _INTERFACE_SELF_PTR_MUT, const VlcbNetHwAddr *const addr)
)

typedef VlcbNetSocket *VlcbNetSocketHandle;
typedef struct {
  const size_t size;
  VlcbNetSocketHandle *const ptr;
  size_t len;
} VlcbNetSocketList;

VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *const list,
                                         size_t size);

#define VLCB_NET_SOCK_LIST(name, size)   \
  VlcbNetSocketHandle data_##name[size]; \
  VlcbNetSocketList name = vlcb_net_sock_list_New(data_##name, size);

void vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                               VlcbNetSocketHandle sock);

typedef struct {
  size_t pointer;
  const VlcbNetSocketList *const list;
} VlcbNetSocketListIter;

VlcbNetSocketListIter vlcb_net_sock_list_GetIterator(
    const VlcbNetSocketList *const list);

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *const iter);
bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *const iter);
VlcbNetSocketHandle vlcb_net_sock_list_iter_Next(
    VlcbNetSocketListIter *const iter);
