#pragma once

#include <stdint.h>

#include "packet.h"

/**
 * CAN Header ID used in transmission
 */
typedef uint16_t VlcbCanDevId;

/**
 * Parse the CAN packet data into the inner format
 */
VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    VlcbCanDevId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet);

/**
 * Construct new VlcbCanDevId from a packet
 *
 * This method is useful when constructing outbound packets
 */
VlcbCanDevId vlcb_net_dev_can_NewCanDevIdFromPacket(
    const VlcbNetDevPacket *const packet);
