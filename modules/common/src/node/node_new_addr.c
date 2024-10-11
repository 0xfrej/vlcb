#include "vlcb/common/node.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

bool IsNodeAddrValid(const VlcbNodeAddr addr) { return addr > 0; }

int vlcb_defs_NewNodeAddr(const uint16_t val, VlcbNodeAddr *const addr) {
  assert(addr != NULL);
  const VlcbNodeAddr _addr = val;
  if (IsNodeAddrValid(_addr)) {
    *addr = _addr;
    return 0;
  }
  return 1;
}

int vlcb_defs_NewNodeAddrFromBytes(const uint8_t hi, const uint8_t lo, VlcbNodeAddr *const addr) {
  const VlcbNodeAddr _addr = vlcb_defs_NewNodeAddrFromBytesUnchecked(hi, lo);
  if (IsNodeAddrValid(_addr)) {
    *addr = _addr;
    return 0;
  }
  return 1;
}
