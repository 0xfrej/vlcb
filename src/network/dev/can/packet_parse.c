#include "packet_parse.h"

#include <stdbool.h>
#include <string.h>

#include "packet.h"

VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    CanId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet) {
  if (payload_len > VLCB_NET_DEV_PACKET_MAX_PAYLOAD) {
    return VLCB_NET_DEV_ERR_PAYLOAD_TOO_LARGE;
  }
  memcpy(&packet->payload_len, packet, payload_len);
  packet->payload_len = payload_len;
  packet->medium = VLCB_MEDIUM_CAN;
  packet->src_addr.can_id = id;
  packet->meta.can.is_rtr = is_rtr;

  return VLCB_NET_DEV_ERR_OK;
}
