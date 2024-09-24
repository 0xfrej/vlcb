#pragma once

#include <inttypes.h>

#include "vlcb_defs.h"

typedef uint16_t CanId;

CanId vlcb_defs_NewCanId(uint16_t id);
CanId vlcb_defs_NewCanIdFromBytes(uint8_t hi, uint8_t lo);

typedef enum {
  VLCB_CAN_PRIO_SELF_ENUM = 0b0000,
  VLCB_CAN_PRIO_HIGH = 0b0100,
  VLCB_CAN_PRIO_ABOVE = 0b0101,
  VLCB_CAN_PRIO_NORMAL = 0b0110,
  VLCB_CAN_PRIO_LOW = 0b0111,
  VLCB_CAN_PRIO_LOWEST = 0b1111,
} VlcbCanPriority;

VlcbCanPriority vlcb_defs_VlcbCanPriorityForOpcode(VlcbOpCode opc);
