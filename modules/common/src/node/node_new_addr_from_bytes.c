#include "vlcb/common/node.h"

#include <stdint.h>

int vlcb_defs_NewNodeAddrFromBytes(const uint8_t hi, const uint8_t lo, VlcbNodeAddr *const addr) {
  const uint16_t _addr = vlcb_defs_NewNodeAddrFromBytesUnchecked(hi, lo);
  return vlcb_defs_NewNodeAddr(_addr, addr);
}
