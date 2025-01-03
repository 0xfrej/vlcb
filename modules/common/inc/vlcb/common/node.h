#pragma once

#include <inttypes.h>

/**
 * VLCB node address (11 bit wide)
 */
typedef uint16_t VlcbNodeNumber;

#define VLCB_NODE_NUMBER_UNINITIALIZED (VlcbNodeNumber)0

/**
 * @brief Construct a node number from bytes, unchecked.
 *
 * @param[in] hi high byte of the address
 * @param[in] lo low byte of the address
 *
 * @return constructed node number
 */
VlcbNodeNumber vlcb_defs_NewNodeNumberFromBytesUnchecked(uint8_t hi,
                                                         uint8_t lo);

/**
 * @brief Cast raw value to a node number
 *
 * @param[in] val raw value to cast
 * @param[out] addr pointer to the destiantion variable for result
 *
 * @return whether the cast succeeded
 * @retval 0 successful
 * @retval 1 failure
 */
int vlcb_defs_NewNodeNumber(uint16_t val, VlcbNodeNumber *const addr);

/**
 * @brief Cast raw bytes to a node number
 *
 * @param[in] hi high byte of the address
 * @param[in] lo low byte of the address
 * @param[out] addr pointer to destination variable for the result
 *
 * @return whether the cast was succesful
 * @retval 0 successful
 * @retval 1 failure
 */
int vlcb_defs_NewNodeNumberFromBytes(uint8_t hi, uint8_t lo,
                                     VlcbNodeNumber *const addr);
