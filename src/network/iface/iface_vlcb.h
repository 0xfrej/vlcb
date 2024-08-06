#pragma once 

#include "iface.h"
#include "../socket/socket.h"
#include "../packet/vlcb.h"

void ProcessVlcbPacket(VlcbNetIface* const iface, VlcbNetSocketList* const sockets, VlcbPacket* const packet);
