#pragma once

#include <stdint.h>

typedef uint8_t VlcbDccSessionNr;
typedef uint16_t VlcbDccDecoderAddr;
typedef uint8_t VlcbDccConsistId;

typedef uint8_t VlcbDccLocoState;
enum VlcbDccLocoState {
  VLCB_DCC_LOCO_STATE_ACTIVE = 0,
  VLCB_DCC_LOCO_STATE_CONSISTED = 1,
  VLCB_DCC_LOCO_STATE_CONSIST_MASTER = 2,
  VLCB_DCC_LOCO_STATE_INACTIVE = 4,
};

typedef uint8_t VlcbDccLocoFunctionRange;
enum VlcbDccLocoFunctionRange {
  VLCB_DCC_LOCO_FUNC_RANGE_F0_F4 = 1,
  VLCB_DCC_LOCLO_FUNC_RANGE_F5_F8 = 2,
  VLCB_DCC_LOCLO_FUNC_RANGE_F9_F12 = 3,
  VLCB_DCC_LOCLO_FUNC_RANGE_F13_F20 = 4,
  VLCB_DCC_LOCLO_FUNC_RANGE_F21_F28 = 5,
};

typedef uint8_t VlcbDccSessionQueryMode;
enum VlcbDccSessionQueryMode {
  VLCB_DCC_SESSION_QUERY_MODE_DEFAULT = 0x00,
  VLCB_DCC_SESSION_QUERY_MODE_STEAL = 0x01,
  VLCB_DCC_SESSION_QUERY_MODE_SHARE = 0x02,
};
