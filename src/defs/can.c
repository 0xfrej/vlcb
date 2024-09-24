#include "can.h"

#include <assert.h>
#include <stdbool.h>

#include "vlcb_defs.h"

bool IsCanIdValid(CanId id) { return id > 0 && id < 128; }

CanId vlcb_defs_NewCanId(uint16_t id) {
  assert(IsCanIdValid((CanId)id));
  return (CanId)id;
}

CanId vlcb_defs_NewCanIdFromBytes(uint8_t hi, uint8_t lo) {
  CanId id = (hi << 8) | lo;
  assert(IsCanIdValid(id));
  return id;
}

VlcbCanPriority vlcb_defs_VlcbCanPriorityForOpcode(VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    default:
      return VLCB_CAN_PRIO_NORMAL;
  }
}
