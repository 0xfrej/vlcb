#include "vlcb/common/can.h"

#include <assert.h>
#include <stddef.h>

int vlcb_defs_NewCanId(const uint8_t value, CanId *const id) {
  assert(id != NULL);

  const CanId _id = value;

  if (vlcb_defs_IsCanIdValid(_id)) {
    *id = _id;
    return 0;
  }

  return 1;
}
