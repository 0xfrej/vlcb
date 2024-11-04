#pragma once

#include "vlcb/net/iface.h"
#include "vlcb/net/packet/vlcb.h"

void ProcessVlcbPacket(VlcbNetIface *const iface, VlcbNetPacket *const packet);

VlcbNetAdptErr DispatchVlcbPacket(VlcbNetIface *const iface,
                                  VlcbNetAdptCaps caps,
                                  const VlcbNetPacket *const packet);
