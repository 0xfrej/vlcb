#include "can.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "vlcb_defs.h"

bool vlcb_defs_IsCanIdValid(CanId id) { return id > 0 && id < 128; }

bool vlcb_defs_NewCanId(uint8_t value, CanId *const id) {
  assert(id);

  CanId _id = (CanId)value;

  if (vlcb_defs_IsCanIdValid(_id)) {
    *id = _id;
    return true;
  }

  return false;
}

VlcbCanPriority vlcb_defs_VlcbCanPriorityFromOpcode(VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    default:
      return VLCB_CAN_PRIO_DEFAULT;
  }
}

bool vlcb_defs_IsVlcbCanPriorityValid(VlcbCanPriority prio) {
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

VlcbEnumConstructErr vlcb_defs_VlcbCanPriorityFromByte(
    uint8_t val, VlcbCanPriority *const prio) {
  assert(prio);

  val = 0xf & val;
  if (vlcb_defs_IsVlcbCanPriorityValid(val)) {
    *prio = val;
    return VLCB_ENUM_ERR_OK;
  }

  return VLCB_ENUM_ERR_INVALID_VALUE;
}
