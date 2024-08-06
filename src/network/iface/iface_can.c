#include "iface_can.h"
#include "iface_vlcb.h"
#include "iface.h"
#include "../dev/dev.h"
#include "../dev/can/packet_parse.h"
#include "../socket/socket.h"
#include "../packet/vlcb.h"

void ProcessCanPacket(VlcbNetIface* const iface, VlcbNetSocketList* const sockets, VlcbNetDevPacket *packet) {

  VlcbPacket vlcb_packet = 
}
