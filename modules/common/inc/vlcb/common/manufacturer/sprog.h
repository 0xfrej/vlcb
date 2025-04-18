#pragma once

#include <stdint.h>

/**
 * Sprog Module types
 */
typedef enum {
  /**
   * Pi-SPROG 3 programmer/command station
   */
  VLCB_SPROG_MODULE_CANPI_SPRG3 = 1,

  /**
   * SPROG 3 Plus programmer/command station
   */
  VLCB_SPROG_MODULE_CANSPROG3P = 2,

  /**
   * CAN SPROG programmer/command station
   */
  VLCB_SPROG_MODULE_CANSPROG = 3,

  /**
   * System Booster
   */
  VLCB_SPROG_MODULE_CANSBOOST = 4,

  /**
   * Pi-SPROG 3 Plus programmer/command station
   */
  VLCB_SPROG_MODULE_CANPI_SPRGP = 5,

  /**
   * 8-channel (4-pairs) Solenoid I/O module
   */
  VLCB_SPROG_MODULE_CANSOLNOID = 8,

  /**
   * 8-channel Servo I/O module
   */
  VLCB_SPROG_MODULE_CANSERVOIO = 50,

  /**
   * CAN ISB Isolated CAN USB Interface
   */
  VLCB_SPROG_MODULE_CANISB = 100,

  /**
   * 8-channel (4-pairs) Solenoid I/O module
   */
  VLCB_SPROG_MODULE_CANSOLIO = 101,
} VlcbSprogModuleType;
