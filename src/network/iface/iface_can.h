#pragma once

#include "iface.h"
#include "../dev/dev.h"
#include "../socket/socket.h"

void ProcessCanPacket(VlcbNetIface* const iface, VlcbNetSocketList* const sockets, VlcbNetDevPacket *packet);

