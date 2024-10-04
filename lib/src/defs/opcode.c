#include "../../defs/opcode.h"

#include <assert.h>
#include <stddef.h>

int vlcb_defs_OpcodeFromByte(const uint8_t val,
                                              VlcbOpCode* const opc) {
  assert(opc != NULL);
  // TODO: add checks

  *opc = val;
  return 0;
}
