#include "packet_parse.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    VlcbCanDevId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet) {
  if (payload_len > VLCB_NET_DEV_CAN_MTU) {
    return VLCB_NET_DEV_ERR_PAYLOAD_TOO_LARGE;
  }
  memcpy(&packet->payload_len, packet, payload_len);
  packet->payload_len = payload_len;
  packet->medium = VLCB_MEDIUM_CAN;

  CanId can_id;
  vlcb_error err = vlcb_defs_NewCanId(((uint8_t)id) & 0x7f, &can_id);
  if (err != NULL) {
    return VLCB_NET_DEV_ERR_INVALID_CANID;
  }

  packet->src_addr = vlcb_net_dev_NewCanIdHwAddr(can_id);
  packet->meta.can.is_rtr = is_rtr;

  return VLCB_NET_DEV_ERR_OK;
}

VlcbCanDevId vlcb_net_dev_can_NewCanDevIdFromPacket(
    const VlcbNetDevPacket *const packet) {
  assert(packet);  // TODO: validate canid here? - the packet could be
                   // incorrectly constructed or passed into a wrong codepath

  VlcbCanDevId id;

  id |= packet->src_addr.can_id;

  VlcbCanPriority prio = VLCB_CAN_PRIO_DEFAULT;  // init with default priority
  if (packet->payload > 0) {
    prio = vlcb_defs_VlcbCanPriorityForOpcode(packet->payload[0]);
  }

  id |= prio << 7;

  return id;
}
