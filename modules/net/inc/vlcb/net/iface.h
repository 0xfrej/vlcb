#pragma once

#include <stdbool.h>

#include "adapter.h"
#include "socket.h"

typedef struct VlcbNetIface VlcbNetIface;

struct VlcbNetIface {
  VlcbNetAdpt *const adpt;
  VlcbNetSocketList *const sockets;
};

VlcbNetIface vlcb_net_iface_New(VlcbNetAdpt *const adpt, VlcbNetSocketList *const sockets);

typedef struct {
  bool readiness_may_have_changed;
} VlcbNetIfacePollResult;

VlcbNetIfacePollResult vlcb_net_iface_Poll(VlcbNetIface *const iface);
VlcbNetMedium vlcb_net_iface_Medium(const VlcbNetIface *const iface);
