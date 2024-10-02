#pragma once

#include <stdbool.h>

#include "../dev/dev.h"
#include "../packet/vlcb.h"
#include "../socket/socket.h"

typedef struct VlcbNetIface VlcbNetIface;
// typedef struct VlcbNetInterceptors VlcbNetInterceptors;

// typedef bool (*VlcbIfaceNetDevInterceptor)(VlcbNetIface *const,
// VlcbNetDevPacket *const);

// struct VlcbNetInterceptors {
// VlcbIfaceNetDevInterceptor net_dev;
// };

struct VlcbNetIface {
  VlcbNetDev *dev;
  VlcbNetDevHwAddr hw_addr;
  VlcbNodeAddr node_addr;
  // VlcbNetInterceptors interceptors;
};

VlcbNetIface vlcb_net_iface_New(VlcbNetDevHwAddr hw_addr,
                                VlcbNodeAddr node_addr);
int vlcb_net_iface_Bind(VlcbNetIface *const iface, VlcbNetDev *const dev);

typedef struct {
  bool readiness_may_have_changed;
} VlcbNetIfacePollResult;

VlcbNetIfacePollResult vlcb_net_iface_Poll(
    VlcbNetIface *const iface, const VlcbNetSocketList *const sockets);
VlcbMedium vlcb_net_iface_Medium(const VlcbNetIface *const iface);
// void vlcb_net_iface_RegisterNetDevListener(VlcbNetIface *const iface,
// VlcbIfaceNetDevInterceptor listener);
