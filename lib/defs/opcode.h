#pragma once

#include <stdint.h>

#include "vlcb_defs.h"

int vlcb_defs_OpcodeFromByte(uint8_t val,
                                              VlcbOpCode* const opc);
