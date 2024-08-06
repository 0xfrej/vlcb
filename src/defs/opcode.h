#pragma once

#include <stdint.h>

#include "vlcb_defs.h"

typedef enum {
  VLCB_OPC_ERR_OK = 0,

  VLCB_OPC_ERR_INVALID_VALUE,

  /**
   * Not an acttual error, can be used to detect if the value is within range of
   * this enum.
   */
  VLCB_OPC_ERR_COUNT,
} VlcbOpcErr;

const char* vlcb_defs_VlcbOpcErrToStr();

VlcbOpcErr vlcb_defs_VlcbOpcFromRaw(uint8_t val, VlcbOpCode* const opc);
