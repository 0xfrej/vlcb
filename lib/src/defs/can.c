#include "../../defs/can.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "../../defs/vlcb_defs.h"

bool vlcb_defs_IsCanIdValid(const CanId id) { return id > 0 && id < 128; }

int vlcb_defs_NewCanId(const uint8_t value, CanId *const id) {
  assert(id != NULL);

  const CanId _id = value;

  if (vlcb_defs_IsCanIdValid(_id)) {
    *id = _id;
    return 0;
  }

  return 1;
}

VlcbCanPriority vlcb_defs_CanPriorityFromOpcode(const VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    default:
      return VLCB_CAN_PRIO_DEFAULT;
  }
}

bool vlcb_defs_IsCanPriorityValid(const VlcbCanPriority prio) {
  switch (prio) {
    case VLCB_CAN_PRIO_SELF_ENUM:
    case VLCB_CAN_PRIO_HIGH:
    case VLCB_CAN_PRIO_ABOVE:
    case VLCB_CAN_PRIO_NORMAL:
    case VLCB_CAN_PRIO_LOW:
    case VLCB_CAN_PRIO_LOWEST:
      return true;
    default:
      return false;
  }
}

int vlcb_defs_CanPriorityFromByte(
    const uint8_t val, VlcbCanPriority *const prio) {
  assert(prio != NULL);

  if (vlcb_defs_IsCanPriorityValid(val)) {
    *prio = val;
    return 0;
  }

  return 1;
}
