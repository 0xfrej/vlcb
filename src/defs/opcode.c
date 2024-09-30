#include "opcode.h"

#include <assert.h>
#include <stddef.h>

VlcbEnumConstructErr vlcb_defs_VlcbOpcFromRaw(uint8_t val,
                                              VlcbOpCode* const opc) {
  assert(opc != NULL);
  // TODO: add checks

  *opc = (VlcbOpCode)val;
  return VLCB_ENUM_ERR_OK;
}
