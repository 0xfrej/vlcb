#include "vlcb/common/node.h"

VlcbNodeAddr vlcb_defs_NewNodeAddrFromBytesUnchecked(const uint8_t hi, const uint8_t lo) {
  const VlcbNodeAddr addr = (hi << 8) | lo;
  return addr;
}