#pragma once

#include "vlcb/net/adapter.h"
#include "vlcb/net/iface.h"

void ProcessCanPacket(VlcbNetIface *const iface, VlcbNetAdptPkt *packet,
                      vlcb_clock now);

VlcbNetAdptErr DispatchCanPacket(VlcbNetIface *const iface,
                                 const VlcbNetPacket *const packet);
