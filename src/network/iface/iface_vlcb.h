#pragma once

#include "../packet/vlcb.h"
#include "../socket/socket.h"
#include "iface.h"

void ProcessVlcbPacket(VlcbNetIface* const iface,
                       const VlcbNetSocketList* const sockets,
                       VlcbPacket* const packet);

VlcbNetDevErr DispatchVlcbPacket(VlcbNetIface* const iface, VlcbNetDevCaps caps,
                                 const VlcbPacket* const packet);
