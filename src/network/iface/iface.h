#pragma once

#include "../dev/dev.h"
#include "../packet/vlcb.h"

typedef struct {
  VlcbNetDevCaps caps;
  VlcbNetDevHwAddr hw_addr;
  VlcbNodeAddr node_addr;
} VlcbNetIface;

VlcbNetIface vlcb_new_net_iface(VlcbNetDev *dev, )
