#include "opcode.h"

VlcbOpcErr vlcb_defs_VlcbOpcFromRaw(uint8_t val, VlcbOpCode* const opc) {
  // TODO: add checks

  *opc = (VlcbOpCode)val;
  return VLCB_OPC_ERR_OK;
}
