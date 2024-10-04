#pragma once

#include "../../../net/iface/iface.h"
#include "../../../net/packet/vlcb.h"
#include "../../../net/socket/socket.h"

void ProcessVlcbPacket(VlcbNetIface* const iface,
                       VlcbPacket* const packet);

VlcbNetAdptErr DispatchVlcbPacket(VlcbNetIface* const iface,
                                  VlcbNetAdptCaps caps,
                                  const VlcbPacket* const packet);
