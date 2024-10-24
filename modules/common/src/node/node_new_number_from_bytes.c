#include "vlcb/common/node.h"

#include <stdint.h>

int vlcb_defs_NewNodeNumberFromBytes(const uint8_t hi, const uint8_t lo,
                                     VlcbNodeNumber *const addr) {
  const uint16_t _addr = vlcb_defs_NewNodeNumberFromBytesUnchecked(hi, lo);
  return vlcb_defs_NewNodeNumber(_addr, addr);
}
