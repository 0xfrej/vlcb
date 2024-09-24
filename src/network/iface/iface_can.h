#pragma once

#include "../dev/dev.h"
#include "../socket/socket.h"
#include "iface.h"

void ProcessCanPacket(VlcbNetIface* const iface,
                      const VlcbNetSocketList* const sockets,
                      VlcbNetDevPacket* packet);

VlcbNetDevErr DispatchCanPacket(VlcbNetIface* const iface,
                                const VlcbPacket* const packet);
