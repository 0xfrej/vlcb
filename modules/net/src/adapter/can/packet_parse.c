#include "../../../../net/adapter/can/packet_parse.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../../../../../shared/log.h"

inline VlcbNetAdptErr vlcb_net_adpt_ParseRawCanData(
    const VlcbCanFrameId id, const bool is_rtr, const uint8_t payload_len,
    const VlcbNetAdptPayload *const payload, VlcbNetAdptPkt *const packet) {
  assert(payload != NULL && packet != NULL);
  assert(is_rtr == false ||
         payload_len == 0 /* when rtr is set, no payload can be sent */);

  if (payload_len > VLCB_NET_ADPT_MAX_PAYLOAD) {
    return VLCB_NET_ADPT_ERR_PAYLOAD_TOO_LARGE;
  }

  if (payload_len > 0) {
    memcpy(&packet->payload, payload, payload_len);
  }

  packet->payload_len = payload_len;
  packet->medium = VLCB_MEDIUM_CAN;

  {
    CanId can_id;
    const bool valid = vlcb_defs_NewCanId(((uint8_t)id) & 0x7f, &can_id);
    if (valid == false) {
      return VLCB_NET_ADPT_ERR_INVALID_CANID;
    }
    packet->src_addr = vlcb_net_adpt_NewCanIdHwAddr(can_id);
  }

  VlcbCanPriority prio;
  const int err = vlcb_defs_CanPriorityFromByte(id >> 7, &prio);
  if (err != 0) {
    VLCBLOG_DEBUG("invalid priority received. aliasing to default");
    prio = VLCB_CAN_PRIO_DEFAULT;
  }

  packet->meta.can = (VlcbNetAdptCanPktMeta){
      .is_rtr = is_rtr,
      .prio = prio,
  };

  return VLCB_NET_ADPT_ERR_OK;
}

inline int vlcb_net_adpt_NewCanFrameIdFromPkt(
    const VlcbNetAdptPkt *const packet, VlcbCanFrameId *const id) {
  assert(packet != NULL && id != NULL);
  if (vlcb_defs_IsCanIdValid(packet->src_addr.can_id)) {
    return 1;
  }

  *id = packet->src_addr.can_id;

  VlcbCanPriority prio = VLCB_CAN_PRIO_DEFAULT;  // init with default priority
  if (packet->payload > 0) {
    prio = vlcb_defs_CanPriorityFromOpcode(packet->payload[0]);
  }

  *id |= prio << 7;

  return 0;
}

bool vlcb_net_adpt_IsPacketValid(const VlcbNetAdptPkt *const packet) {
  assert(packet != NULL);
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
          packet->payload_len <= VLCB_NET_CAN_MTU) &&
         vlcb_defs_IsCanIdValid(packet->src_addr.can_id) &&
         vlcb_defs_IsCanPriorityValid(packet->meta.can.prio);
}
