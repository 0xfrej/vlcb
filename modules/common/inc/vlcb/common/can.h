#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include "vlcb_defs.h"

typedef uint8_t CanId;

int vlcb_defs_NewCanId(uint8_t value, CanId *const id);
bool vlcb_defs_IsCanIdValid(CanId id);

typedef enum {
  VLCB_CAN_PRIO_SELF_ENUM = 0x0,
  VLCB_CAN_PRIO_HIGH = 0x4,
  VLCB_CAN_PRIO_ABOVE = 0x5,
  VLCB_CAN_PRIO_NORMAL = 0x6,
  VLCB_CAN_PRIO_LOW = 0x7,
  VLCB_CAN_PRIO_LOWEST = 0xF,
} VlcbCanPriority;

#define VLCB_CAN_PRIO_DEFAULT VLCB_CAN_PRIO_NORMAL

bool vlcb_defs_IsCanPriorityValid(VlcbCanPriority prio);
VlcbCanPriority vlcb_defs_CanPriorityFromOpcode(VlcbOpCode opc);
int vlcb_defs_CanPriorityFromByte(
    uint8_t val, VlcbCanPriority *const prio);