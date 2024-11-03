#pragma once

#include <inttypes.h>

/**
 * VLCB node address (11 bit wide)
 */
typedef uint16_t VlcbNodeNumber;

#define VLCB_NODE_NUMBER_UNINITIALIZED (VlcbNodeNumber)0

VlcbNodeNumber vlcb_defs_NewNodeNumberFromBytesUnchecked(uint8_t hi,
                                                         uint8_t lo);
int vlcb_defs_NewNodeNumber(uint16_t val, VlcbNodeNumber *const addr);
int vlcb_defs_NewNodeNumberFromBytes(uint8_t hi, uint8_t lo,
                                     VlcbNodeNumber *const addr);
