#include "vlcb/common/can.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "vlcb/common/vlcb_defs.h"

int vlcb_defs_NewCanId(const uint8_t value, CanId *const id) {
  assert(id != NULL);

  const CanId _id = value;

  if (vlcb_defs_IsCanIdValid(_id)) {
    *id = _id;
    return 0;
  }

  return 1;
}
