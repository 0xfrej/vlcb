#include "packet_parse.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../../../shared/log.h"

VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    VlcbCanFrameId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet) {
  assert(payload && packet);
  assert(is_rtr == false ||
         payload_len == 0 /* when rtr is set, no payload can be sent */);

  if (payload_len > VLCB_NET_DEV_PACKET_MAX_PAYLOAD) {
    return VLCB_NET_DEV_ERR_PAYLOAD_TOO_LARGE;
  }

  memcpy(&packet->payload, payload, payload_len);
  packet->payload_len = payload_len;
  packet->medium = VLCB_MEDIUM_CAN;

  {
    CanId can_id;
    bool valid = vlcb_defs_NewCanId(((uint8_t)id) & 0x7f, &can_id);
    if (valid == false) {
      return VLCB_NET_DEV_ERR_INVALID_CANID;
    }
    packet->src_addr = vlcb_net_dev_NewCanIdHwAddr(can_id);
  }

  VlcbCanPriority prio;
  VlcbEnumConstructErr err = vlcb_defs_VlcbCanPriorityFromByte(id >> 7, &prio);
  if (err != VLCB_ENUM_ERR_OK) {
    VLCBLOG_DEBUG("invalid priority received. aliasing to default");
    prio = VLCB_CAN_PRIO_DEFAULT;
  }

  packet->meta.can = (VlcbNetDevPacketCanMeta){
      .is_rtr = is_rtr,
      .prio = prio,
  };

  return VLCB_NET_DEV_ERR_OK;
}

bool vlcb_net_dev_can_NewCanDevIdFromPacket(
    const VlcbNetDevPacket *const packet, VlcbCanFrameId *const id) {
  assert(packet && id);
  if (vlcb_defs_IsCanIdValid(packet->src_addr.can_id)) {
    return false;
  }

  VlcbCanFrameId _id;

  _id |= packet->src_addr.can_id;

  VlcbCanPriority prio = VLCB_CAN_PRIO_DEFAULT;  // init with default priority
  if (packet->payload > 0) {
    prio = vlcb_defs_VlcbCanPriorityFromOpcode(packet->payload[0]);
  }

  _id |= prio << 7;

  return _id;
}

bool vlcb_net_dev_can_IsPacketValid(const VlcbNetDevPacket *const packet) {
  assert(packet);
  /**
   * Valid packet needs to have:
   * CAN medium flag
   * Payload must be smaller or equal to the MTU of the CAN device
   * Payload must have size 0 if rtr flag is set
   * CAN ID of this device must be in a valid range
   * CAN Priority must be in range of known values
   */
  return packet->medium == VLCB_MEDIUM_CAN &&
         (packet->meta.can.is_rtr && packet->payload_len == 0 ||
          packet->payload_len <= VLCB_NET_DEV_CAN_MTU) &&
         vlcb_defs_IsCanIdValid(packet->src_addr.can_id) &&
         vlcb_defs_IsVlcbCanPriorityValid(packet->meta.can.prio);
}
