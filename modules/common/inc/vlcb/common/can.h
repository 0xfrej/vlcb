#pragma once

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>

#include "opcode.h"

/**
 * @brief VLCB CAN ID aliad
 *
 * Alias ID for a node communicating on CAN bus medium
 * using the VLCB protocol.
 *
 * This is added to the CAN frame ID and functions to
 * resolve frame collisions.
 */
typedef uint8_t VlcbCanId;

#define VLCB_CAN_ID_EMPTY (VlcbCanId)0
/**
 * @brief Checked cast from raw byte
 *
 * @param[in] value the raw value to be cast into `VlcbCanId`
 * @param[out] id the destination variable for the result
 *
 * @return whether the cast was successful
 * @retval 0 The value was valid
 * @retval 1 The value passed in was not a valid `VlcbCanId`
 */
int vlcb_defs_NewCanId(uint8_t value, VlcbCanId *const id);

/**
 * @brief Check if VLCB CAN ID value is valid
 *
 * @param[in] id the value to be checked
 *
 * @return whether the passed in value was a valid `VlcbCanId`
 */
bool vlcb_defs_IsCanIdValid(VlcbCanId id);

/**
 * @brief VLCB CAN priority
 *
 * Added value to CAN frame ID to prioritize transmission
 * of some messages on the bus.
 */
typedef uint8_t VlcbCanPriority;
enum VlcbCanPriority {
  VLCB_CAN_PRIO_SELF_ENUM =
      0x0, /**< Priority used for @ref VlcbCanId resolution */
  VLCB_CAN_PRIO_HIGH = 0x4,
  VLCB_CAN_PRIO_ABOVE = 0x5,
  VLCB_CAN_PRIO_NORMAL = 0x6,
  VLCB_CAN_PRIO_LOW = 0x7,
  VLCB_CAN_PRIO_LOWEST = 0xF,
};

#define VLCB_CAN_PRIO_DEFAULT VLCB_CAN_PRIO_NORMAL

/**
 * @brief Check if CAN priority value is valid
 *
 * @param[in] prio Priority value to be checked
 *
 * @return if the priority is valid
 */
bool vlcb_defs_IsCanPriorityValid(VlcbCanPriority prio);

/**
 * @brief Get a priority for @ref VlcbOpCode
 *
 * @param[in] opc VLCB OpCode
 *
 * @return Resolved priority for given opcode
 */
VlcbCanPriority vlcb_defs_CanPriorityFromOpcode(VlcbOpCode opc);

/**
 * @brief Checked cast from raw byte
 *
 * @param[in] val the raw value to be casted
 * @param[out] prio pointer to the destination variable
 *
 * @return if the raw value is a valid priority
 * @retval 0 the passed in value was valid
 * @retval 1 the passed in value was invalid
 */
int vlcb_defs_CanPriorityFromByte(uint8_t val, VlcbCanPriority *const prio);
