#pragma once

#include <stdint.h>

#include "packet.h"

/**
 * @brief CAN frame id used in transmission
 *
 * This type is used to store the CAN ID (11 bits wide).
 * First 7 bits contain the `CAN ID` (see @ref CanId) (node alias used on CAN
 * bus). Rest of the bits contain the `priority value` (see @ref
 * VlcbCanPriority).
 */
typedef uint16_t VlcbCanFrameId;

/**
 * @brief Parse the CAN packet data into the inner format
 *
 * This function validates and constructs a new `VlcbNetDevPacket` (see @ref
 * VlcbNetDevPacket) from raw data and flags passed in from the device deriver
 * adapter. Device driver adapters should use this function instead of their own
 * implementation, unless it's desirable.
 *
 * It is worthy to note that unknown priority values get aliased to the default
 * one.
 *
 * @param[in] id The raw value of CAN ID (11 bits, does not have to be masked)
 * @param[in] is_rtr Whether the received CAN frame had RTR flag set
 * @param[in] payload_len Length of the received payload. [0, 8]
 * @param[in] payload The payload buffer containing data from received CAN frame
 * @param[out] packet Destination memory space for the constructed packets
 *
 * @return The error code (returns `VLCB_NET_DEV_ERR_OK` (see @ref
 * VlcbNetDevErr) when there is no error)
 */
VlcbNetDevErr vlcb_net_dev_can_ParseRawData(
    VlcbCanFrameId id, bool is_rtr, uint8_t payload_len,
    const VlcbNetDevPacketPayload *payload, VlcbNetDevPacket *packet);

/**
 * @brief Construct new CAN frame ID from a packet
 *
 * This method is useful when constructing outbound packets, provides
 * minimal validation to the packet and maps certain values, like priority,
 * based on the OPCODE.
 *
 * It is worthy to note that unknown priority values get alias to the default
 * one.
 *
 * @param[in] packet The device packet we're about to send out
 * @param[out] id The variable to store the constructed frame id
 *
 * @return Whether the ID was constructed successfully
 * @retval true The id is valid
 * @retval false The id is invalid
 */
bool vlcb_net_dev_can_NewCanDevIdFromPacket(
    const VlcbNetDevPacket *const packet, VlcbCanFrameId *const id);

/**
 * @brief Check if the packed passed in is correctly constructed
 *
 * Valiates the packet to check if it is a valid packet targeted for the
 * CAN bus.
 *
 * @param[in] packet The packet to be validated
 *
 * @return Whether the packet is valid CAN bus packet or not
 * @retval true The packet is valid
 * @retval false The packet is invalid
 */
bool vlcb_net_dev_can_IsPacketValid(const VlcbNetDevPacket *const packet);
