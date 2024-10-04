#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include "vlcb_defs.h"

typedef uint8_t CanId;

int vlcb_defs_NewCanId(uint8_t value, CanId *const id);
bool vlcb_defs_IsCanIdValid(CanId id);

typedef enum {
  VLCB_CAN_PRIO_SELF_ENUM = 0b0000,
  VLCB_CAN_PRIO_HIGH = 0b0100,
  VLCB_CAN_PRIO_ABOVE = 0b0101,
  VLCB_CAN_PRIO_NORMAL = 0b0110,
  VLCB_CAN_PRIO_LOW = 0b0111,
  VLCB_CAN_PRIO_LOWEST = 0b1111,
} VlcbCanPriority;

#define VLCB_CAN_PRIO_DEFAULT VLCB_CAN_PRIO_NORMAL

bool vlcb_defs_IsCanPriorityValid(VlcbCanPriority prio);
VlcbCanPriority vlcb_defs_CanPriorityFromOpcode(VlcbOpCode opc);
int vlcb_defs_CanPriorityFromByte(
    uint8_t val, VlcbCanPriority *const prio);
