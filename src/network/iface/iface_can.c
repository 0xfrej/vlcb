#include "iface_can.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "../../shared/log.h"
#include "../dev/dev.h"
#include "../packet/vlcb.h"
#include "../socket/socket.h"
#include "iface.h"
#include "iface_vlcb.h"

void ProcessCanPacket(VlcbNetIface* const iface,
                      const VlcbNetSocketList* const sockets,
                      VlcbNetDevPacket* packet) {
  // if (iface->interceptors.net_dev != NULL) {
  //   bool should_continue = iface->interceptors.net_dev(iface, packet);
  //
  //   if (should_continue == false) {
  //     return;
  //   }
  // }

  VlcbNetDevPacketPayload* payload = &packet->payload;
  VlcbOpCode opc;
  {
    VlcbEnumConstructErr err = vlcb_defs_VlcbOpcFromRaw(*payload[0], &opc);

    if (err != VLCB_ENUM_ERR_OK) {
      VLCBLOG_ERROR(vlcb_error_VlcbEnumErrToStr(err));
      return;
    }
  }

  VlcbPacket vlcb_packet;
  {
    VlcbPacketConstructErr err;
    err = vlcb_pkt_NewPacket(opc, packet->payload_len,
                             (VlcbPacketPayload*)(payload + 1), &vlcb_packet);
    if (err != VLCB_PKT_CONSTRUCT_ERR_OK) {
      VLCBLOG_ERROR(vlcb_pkt_VlcbPacketConstructErrToStr(err));
      return;
    }
  }

  ProcessVlcbPacket(iface, sockets, &vlcb_packet);
}

VlcbNetDevErr DispatchCanPacket(VlcbNetIface* const iface,
                                const VlcbPacket* const packet) {
  VlcbNetDevPacket dev_packet;

  dev_packet.medium = VLCB_MEDIUM_CAN;
  dev_packet.meta.can.is_rtr = false;
  dev_packet.payload_len = 1 + packet->payload_len;

  if (packet->payload_len) {
    memcpy(&dev_packet.payload + 1, packet->payload, packet->payload_len);
  }

  VlcbNetDevErr err = iface->dev->tc->Send(iface->dev->self, &dev_packet);

  return err;
}
