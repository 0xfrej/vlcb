#pragma once

#include "../dev/dev.h"
#include "../socket/socket.h"
#include "iface.h"

void ProcessCanPacket(VlcbNetIface* const iface,
                      VlcbNetSocketList* const sockets,
                      VlcbNetDevPacket* packet);
