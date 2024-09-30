#pragma once

#include <stdint.h>

#include "../shared/error.h"
#include "vlcb_defs.h"

VlcbEnumConstructErr vlcb_defs_VlcbOpcFromRaw(uint8_t val,
                                              VlcbOpCode* const opc);
