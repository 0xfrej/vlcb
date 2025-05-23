#pragma once

#include <stdbool.h>

#include "adapter.h"
#include "socket.h"

typedef struct VlcbNetIface VlcbNetIface;

typedef struct {
  bool endpointIsEnumerating;
  uint8_t canIdAliasOccupationCache[16];
} VlcbNetIfaceMediumMetaCan;
typedef union {
  VlcbNetIfaceMediumMetaCan can;
} VlcbNetIfaceMediumMeta;

struct VlcbNetIface {
  IVlcbNetAdpt *const adpt;
  VlcbNetSocketList *const sockets;
};

VlcbNetIface vlcb_net_iface_New(IVlcbNetAdpt *const adpt,
                                VlcbNetSocketList *const sockets);

typedef struct {
  bool readiness_may_have_changed;
} VlcbNetIfacePollResult;

VlcbNetIfacePollResult vlcb_net_iface_Poll(VlcbNetIface *const iface,
                                           vlcb_clock now);
VlcbNetMedium vlcb_net_iface_Medium(const VlcbNetIface *const iface);
bool vlcb_net_iface_BindSock(VlcbNetIface *const iface,
                             VlcbNetSocketHandle sock);
void vlcb_net_iface_FreeSock(VlcbNetIface *const iface,
                             VlcbNetSocketHandle sock);
