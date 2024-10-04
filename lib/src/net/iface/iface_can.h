#pragma once

#include "../../../net/adapter/adapter.h"
#include "../../../net/iface/iface.h"
#include "../../../net/socket/socket.h"

void ProcessCanPacket(VlcbNetIface* const iface,
                      VlcbNetAdptPkt* packet);

VlcbNetAdptErr DispatchCanPacket(VlcbNetIface* const iface,
                                 const VlcbPacket* const packet);
