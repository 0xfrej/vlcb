#pragma once

#include <stdbool.h>
#include "../dev/dev.h"
#include "../packet/vlcb.h"
#include "../socket/socket.h"

typedef struct {
  VlcbNetDev *dev;
  VlcbNetDevHwAddr hw_addr;
  VlcbNodeAddr node_addr;
} VlcbNetIface;

VlcbNetIface vlcb_iface_New(VlcbNetDevHwAddr hw_addr, VlcbNodeAddr node_addr);
void vlcb_iface_Bind(VlcbNetIface * const iface, VlcbNetDev* const dev);
bool vlcb_iface_Poll(VlcbNetIface * const iface, VlcbNetSocketList * const sockets);
