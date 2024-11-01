#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "iface_vlcb.h"
#include "vlcb/net/adapter.h"
#include "vlcb/net/iface.h"
#include "vlcb/net/packet/vlcb.h"
#include "vlcb/platform/log.h"

void ProcessCanPacket(VlcbNetIface *const iface, VlcbNetAdptPkt *pkt) {
  VlcbNetAdptPayload *payload = &pkt->payload;
  VlcbOpCode opc;
  {
    int err = vlcb_defs_OpcodeFromByte(*payload[0], &opc);
    if (err != 0) {
      VLCBLOG_ERROR("invalid opcode, dropping packet");
      return;
    }
  }

  VlcbPacket vlcb_pkt;
  {
    VlcbPacketConstructErr err;
    err = vlcb_net_pkt_New(opc, pkt->payload_len, (VlcbPayload *)(payload + 1),
                           &vlcb_pkt);
    if (err != VLCB_PKT_CONSTRUCT_ERR_OK) {
      VLCBLOG_ERROR(vlcb_net_pkt_ConstructErrToStr(err));
      return;
    }
  }

  ProcessVlcbPacket(iface, &vlcb_pkt);
}

VlcbNetAdptErr DispatchCanPacket(VlcbNetIface *const iface,
                                 const VlcbPacket *const packet) {
  VlcbNetAdptPkt adpt_pkt;

  adpt_pkt.medium = VLCB_MEDIUM_CAN;
  adpt_pkt.meta.can.is_rtr = false;
  adpt_pkt.payload_len = 1 + packet->payload_len;

  if (packet->payload_len) {
    memcpy(&adpt_pkt.payload + 1, packet->payload, packet->payload_len);
  }

  VlcbNetAdptErr err = _INTERFACE_PTR_CALL(iface->adpt, SendPkt, &adpt_pkt);

  return err;
}
