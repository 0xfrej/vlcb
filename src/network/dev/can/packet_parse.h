#pragma once

#include "../dev.h"
#include "packet.h"

/**
 * Parse the CAN packet data into the inner format
 */
VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    CanId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet);
