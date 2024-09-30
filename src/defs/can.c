#include "can.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "vlcb_defs.h"

vlcb_error err_invalid_val = "can id value is invalid";

bool IsCanIdValid(CanId id) { return id > 0 && id < 128; }

vlcb_error vlcb_defs_NewCanId(uint8_t value, CanId *const id) {
  assert(id);

  CanId _id = (CanId)value;

  if (IsCanIdValid(_id)) {
    *id = _id;
    return NULL;
  }

  return err_invalid_val;
}

VlcbCanPriority vlcb_defs_VlcbCanPriorityForOpcode(VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    default:
      return VLCB_CAN_PRIO_NORMAL;
  }
}
