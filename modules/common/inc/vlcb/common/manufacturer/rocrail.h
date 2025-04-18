#pragma once

#include <stdint.h>

/**
 * Rocrail Module types
 */
typedef enum {
  /**
   * RS232 PC interface
   */
  VLCB_ROCRAIL_MODULE_CANGC1 = 1,

  /**
   * 16 I/O
   */
  VLCB_ROCRAIL_MODULE_CANGC2 = 2,

  /**
   * Command station (derived from cancmd)
   */
  VLCB_ROCRAIL_MODULE_CANGC3 = 3,

  /**
   * 8 channel RFID reader
   */
  VLCB_ROCRAIL_MODULE_CANGC4 = 4,

  /**
   * Cab for fixed panels (derived from cancab)
   */
  VLCB_ROCRAIL_MODULE_CANGC5 = 5,

  /**
   * 4 channel servo controller
   */
  VLCB_ROCRAIL_MODULE_CANGC6 = 6,

  /**
   * Fast clock module
   */
  VLCB_ROCRAIL_MODULE_CANGC7 = 7,

  /**
   * CAN<->Ethernet interface
   */
  VLCB_ROCRAIL_MODULE_CANGC1E = 11,
} VlcbRocRailModuleType;
