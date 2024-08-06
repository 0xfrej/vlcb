#include "iface_can.h"

#include "../dev/can/packet_parse.h"
#include "../dev/dev.h"
#include "../packet/vlcb.h"
#include "../socket/socket.h"
#include "iface.h"
#include "iface_vlcb.h"

void ProcessCanPacket(VlcbNetIface* const iface,
                      VlcbNetSocketList* const sockets,
                      VlcbNetDevPacket* packet) {
  // TODO: handle can service stuff

  VlcbNetDevPacketPayload* payload = &packet->payload;
  VlcbOpCode opc;
  {
    VlcbOpcErr err = vlcb_defs_VlcbOpcFromRaw(*payload[0], &opc);

    if (err != VLCB_OPC_ERR_OK) {
      // TODO: handle err
    }
  }

  VlcbPacket vlcb_packet;
  {
    VlcbPacketConstructErr err;
    err = vlcb_pkt_NewPacket(opc, packet->payload_len,
                             (VlcbPacketPayload*)(payload + 1), &vlcb_packet);
    if (err != VLCB_PKT_CONSTRUCT_ERR_OK) {
      // TODO: handle err
    }
  }

  ProcessVlcbPacket(iface, sockets, &vlcb_packet);
}
