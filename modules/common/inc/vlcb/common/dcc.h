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

/**
 * Error codes for ERR message
 */
typedef uint8_t VlcbDccError;
enum VlcbDccError {
  VLCB_DCC_ERR_LOCO_STACK_IS_FULL = 1,
  VLCB_DCC_ERR_LOCO_ADDRESS_IS_TAKEN = 2,
  VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT = 3,
  VLCB_DCC_ERR_EMPTY_CONSIST = 4,
  VLCB_DCC_ERR_LOCO_WAS_NOT_FOUND = 5,
  VLCB_DCC_ERR_RX_BUFFER_OVERFLOW = 6,
  VLCB_DCC_ERR_INVALID_REQUEST = 7,
  VLCB_DCC_ERR_SESSION_WAS_CANCELLED = 8,
};

/**
 * DCC service mode status
 */
typedef uint8_t VlcbDccServiceModeStatus;
enum VlcbDccServiceModeStatus {
  VLCB_DCC_SVC_MODE_STAT_NO_ACK = 1,
  VLCB_DCC_SVC_MODE_STAT_OVLD = 2,
  VLCB_DCC_SVC_MODE_STAT_WRITE_ACK = 3,
  VLCB_DCC_SVC_MODE_STAT_BUSY = 4,
  VLCB_DCC_SVC_MODE_STAT_CV_ERROR = 5,
};

/**
 * DCC throttle/loco speed modes
 */
typedef uint8_t VlcbDccThrottleSpeedMode;
enum VlcbDccThrottleSpeedMode {
  /**
   * 128-step speed mode
   */
  VLCB_DCC_THROTTLE_MODE_STEP128 = 0,

  /**
   * 14-step speed mode
   */
  VLCB_DCC_THROTTLE_MODE_STEP14 = 1,

  /**
   * interleaved 28-step speed mode
   */
  VLCB_DCC_THROTTLE_MODE_STEP28INTERLEAVED = 2,

  /**
   * 28-step speed mode
   */
  VLCB_DCC_THROTTLE_MODE_STEP28 = 3,
};
