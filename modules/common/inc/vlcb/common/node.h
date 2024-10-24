#pragma once

#include <inttypes.h>

/**
 * VLCB node address (11 bit wide)
 */
typedef uint16_t VlcbNodeAddr;

#define VLCB_NODE_ADDR_UNINITIALIZED (VlcbNodeAddr)0

VlcbNodeAddr vlcb_defs_NewNodeAddrFromBytesUnchecked(uint8_t hi, uint8_t lo);
int vlcb_defs_NewNodeAddr(uint16_t val, VlcbNodeAddr *const addr);
int vlcb_defs_NewNodeAddrFromBytes(uint8_t hi, uint8_t lo, VlcbNodeAddr *const addr);
