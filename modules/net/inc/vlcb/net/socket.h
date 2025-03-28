#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "packet/vlcb.h"
#include "vlcb/net/addr.h"
#include "vlcb/net/storage/packet_buf.h"
#include "vlcb/platform/interface.h"

typedef enum {
  VLCB_NET_SOCK_PROC_ERR_OK = 0,

  VLCB_NET_SOCK_PROC_ERR_RX_BUF_FULL,
  VLCB_NET_SOCK_PROC_ERR_PAYLOAD_TOO_LARGE,
  VLCB_NET_SOCK_PROC_ERR_UNKNOWN,

  VLCB_NET_SOCK_PROC_ERR_COUNT,
} VlcbNetSocketProcessErr;
vlcb_error vlcb_net_sock_ProcessErrToStr(VlcbNetSocketProcessErr err);

typedef enum {
  VLCB_NET_SOCK_DISP_ERR_OK = 0,

  VLCB_NET_SOCK_DISP_ERR_WOULD_BLOCK,

  VLCB_NET_SOCK_DISP_ERR_COUNT,
} VlcbNetSocketDispatchErr;
vlcb_error vlcb_net_sock_DispatchErrToStr(VlcbNetSocketDispatchErr err);

typedef struct {
  VlcbPacketBufToken _t;
  VlcbNetPacket packet;
} VlcbNetSocketPacketToken;

static inline void
vlcb_net_sock_packet_token_Accept(VlcbNetSocketPacketToken tok) {
  vlcb_net_packetbuf_PopDeferredAccept(tok._t);
}

static inline void
vlcb_net_sock_packet_token_Refuse(VlcbNetSocketPacketToken tok) {
  vlcb_net_packetbuf_PopDeferredRefuse(tok._t);
}

_INTERFACE_DECLARE(
    IVlcbNetSocket,
    _INTERFACE_METHOD_DECLARE(VlcbNetSocketProcessErr, ProcessPacket,
                              _INTERFACE_SELF_PTR_MUT(IVlcbNetSocket),
                              const VlcbNetPacket *const packet);
    _INTERFACE_METHOD_DECLARE(VlcbNetSocketDispatchErr, DispatchPacket,
                              _INTERFACE_SELF_PTR_MUT(IVlcbNetSocket),
                              VlcbNetSocketPacketToken *const tok);
    _INTERFACE_METHOD_DECLARE(const VlcbNetWireEndpointHandle, WireEndpoint,
                              _INTERFACE_SELF_PTR(IVlcbNetSocket)););
;

typedef IVlcbNetSocket *VlcbNetSocketHandle;

typedef struct {
  size_t capacity;
  size_t len;
  VlcbNetSocketHandle *const buf;
} VlcbNetSocketList;

inline VlcbNetSocketList vlcb_net_sock_list_New(VlcbNetSocketHandle *const buf,
                                                size_t size);

#define VLCB_NET_SOCK_LIST(name, size)                                         \
  VlcbNetSocketHandle name##_data[size];                                       \
  VlcbNetSocketList name = vlcb_net_sock_list_New(data_##name, size);

int vlcb_net_sock_list_Insert(VlcbNetSocketList *const list,
                              VlcbNetSocketHandle sock);
int vlcb_net_sock_list_Remove(VlcbNetSocketList *const list,
                              VlcbNetSocketHandle sock);

typedef struct {
  size_t pointer;
  const VlcbNetSocketList *const list;
} VlcbNetSocketListIter;

VlcbNetSocketListIter
vlcb_net_sock_list_GetIterator(const VlcbNetSocketList *const list);

void vlcb_net_sock_list_iter_Reset(VlcbNetSocketListIter *const iter);
bool vlcb_net_sock_list_iter_HasNext(VlcbNetSocketListIter *const iter);
VlcbNetSocketHandle
vlcb_net_sock_list_iter_Next(VlcbNetSocketListIter *const iter);
