#pragma once

#include <stdint.h>

/**
 * @brief DCC session number
 *
 * A session ID tied to a DCC decoder. This used to talk through a DCC gateway
 * to the target decoder without having to send it's full address each time.
 */
typedef uint8_t VlcbDccSessionNr;

/**
 * @brief DCC decoder Addresss
 * TODO: i think we need costructors for both 7 and 14 bit addr version look at
 * RLOC for example or GLO
 */
typedef uint16_t VlcbDccDecoderAddr;

/**
 * @brief DCC consist ID
 *
 * Consist IDs are used to address a group of locomotives
 * and control them as one
 */
typedef uint8_t VlcbDccConsistId;

/**
 * @brief Locomotive state.
 */
typedef uint8_t VlcbDccLocoState;
enum VlcbDccLocoState {
  VLCB_DCC_LOCO_STATE_ACTIVE = 0, /**< The locomotive is active. */
  VLCB_DCC_LOCO_STATE_CONSISTED =
      1, /**< The locomotive is part of a consist. */
  VLCB_DCC_LOCO_STATE_CONSIST_MASTER =
      2, /**< The locomotive is the master in a consist. */
  VLCB_DCC_LOCO_STATE_INACTIVE = 4, /**< The locomotive is inactive. */
};

/**
 * @brief Locomotive decoder function selection range.
 */
typedef uint8_t VlcbDccLocoFunctionRange;
enum VlcbDccLocoFunctionRange {
  VLCB_DCC_LOCO_FUNC_RANGE_F0_F4 = 1,   /**< Select function 0 to 4. */
  VLCB_DCC_LOCO_FUNC_RANGE_F5_F8 = 2,   /**< Select function 5 to 8. */
  VLCB_DCC_LOCO_FUNC_RANGE_F9_F12 = 3,  /**< Select function 9 to 12 */
  VLCB_DCC_LOCO_FUNC_RANGE_F13_F20 = 4, /**< Select function 13 to 20 */
  VLCB_DCC_LOCO_FUNC_RANGE_F21_F28 = 5, /**< Select function 21 to 28 */
};

/**
 * @brief Session query mode
 */
typedef uint8_t VlcbDccSessionQueryMode;
enum VlcbDccSessionQueryMode {
  VLCB_DCC_SESSION_QUERY_MODE_DEFAULT = 0x00, /**< Default mode */
  VLCB_DCC_SESSION_QUERY_MODE_STEAL = 0x01,   /**< TODO: add docs */
  VLCB_DCC_SESSION_QUERY_MODE_SHARE = 0x02,   /**< TODO: add docs */
};

/**
 * @brief Error codes returned from DCC gateway
 */
typedef uint8_t VlcbDccError;
enum VlcbDccError {
  VLCB_DCC_ERR_LOCO_STACK_IS_FULL = 1, /**< TODO: add docs */
  VLCB_DCC_ERR_LOCO_ADDRESS_IS_TAKEN = 2,
  VLCB_DCC_ERR_SESSION_IS_NOT_PRESENT = 3,
  VLCB_DCC_ERR_EMPTY_CONSIST = 4,
  VLCB_DCC_ERR_LOCO_WAS_NOT_FOUND = 5,
  VLCB_DCC_ERR_RX_BUFFER_OVERFLOW = 6,
  VLCB_DCC_ERR_INVALID_REQUEST = 7,
  VLCB_DCC_ERR_SESSION_WAS_CANCELLED = 8,
};

/**
 * @brief DCC service mode status
 */
typedef uint8_t VlcbDccServiceModeStatus;
enum VlcbDccServiceModeStatus {
  VLCB_DCC_SVC_MODE_STAT_NO_ACK = 1, /**< TODO: Add docs */
  VLCB_DCC_SVC_MODE_STAT_OVLD = 2,
  VLCB_DCC_SVC_MODE_STAT_WRITE_ACK = 3,
  VLCB_DCC_SVC_MODE_STAT_BUSY = 4,
  VLCB_DCC_SVC_MODE_STAT_CV_ERROR = 5,
};

/**
 * @brief DCC throttle/loco speed modes
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
  VLCB_DCC_THROTTLE_MODE_STEP28_INTERLEAVED = 2,

  /**
   * 28-step speed mode
   */
  VLCB_DCC_THROTTLE_MODE_STEP28 = 3,
};
