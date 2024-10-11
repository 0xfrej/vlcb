#include "vlcb/common/can.h"

#include <assert.h>
#include <stddef.h>

#include "vlcb/common/vlcb_defs.h"

int vlcb_defs_CanPriorityFromByte(
    const uint8_t val, VlcbCanPriority *const prio) {
  assert(prio != NULL);

  if (vlcb_defs_IsCanPriorityValid(val)) {
    *prio = val;
    return 0;
  }

  return 1;
}
