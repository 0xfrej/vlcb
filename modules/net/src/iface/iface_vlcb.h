#pragma once

#include "vlcb/net/iface.h"
#include "vlcb/net/packet/vlcb.h"
#include "vlcb/net/socket.h"

void ProcessVlcbPacket(VlcbNetIface* const iface,
                       VlcbPacket* const packet);

VlcbNetAdptErr DispatchVlcbPacket(VlcbNetIface* const iface,
                                  VlcbNetAdptCaps caps,
                                  const VlcbPacket* const packet);
