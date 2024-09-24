#include "node.h"

#include <assert.h>
#include <stdbool.h>

bool IsNodeAddrValid(VlcbNodeAddr addr) { return addr > 0 && addr < 0x7ff; }

VlcbNodeAddr vlcb_defs_NewNodeAddr(uint16_t addr) {
  assert(IsNodeAddrValid((VlcbNodeAddr)addr));
  return (VlcbNodeAddr)addr;
}

VlcbNodeAddr vlcb_defs_NewNodeAddrFromBytes(uint8_t hi, uint8_t lo) {
  VlcbNodeAddr addr = (hi << 8) | lo;
  assert(IsNodeAddrValid(addr));
  return addr;
}
