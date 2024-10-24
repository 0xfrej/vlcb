#include "vlcb/common/node.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

bool IsNodeNumberValid(const VlcbNodeNumber addr) { return addr > 0; }

int vlcb_defs_NewNodeNumber(const uint16_t val, VlcbNodeNumber *const addr) {
  assert(addr != NULL);
  const VlcbNodeNumber _addr = val;
  if (IsNodeNumberValid(_addr)) {
    *addr = _addr;
    return 0;
  }
  return 1;
}

int vlcb_defs_NewNodeNumberFromBytes(const uint8_t hi, const uint8_t lo,
                                     VlcbNodeNumber *const addr) {
  const VlcbNodeNumber _addr =
      vlcb_defs_NewNodeNumberFromBytesUnchecked(hi, lo);
  if (IsNodeNumberValid(_addr)) {
    *addr = _addr;
    return 0;
  }
  return 1;
}
