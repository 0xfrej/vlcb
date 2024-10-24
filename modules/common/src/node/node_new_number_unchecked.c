#include "vlcb/common/node.h"

VlcbNodeNumber vlcb_defs_NewNodeNumberFromBytesUnchecked(const uint8_t hi,
                                                         const uint8_t lo) {
  const VlcbNodeNumber addr = (hi << 8) | lo;
  return addr;
}
