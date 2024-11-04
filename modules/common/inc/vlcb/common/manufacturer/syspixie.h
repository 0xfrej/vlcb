#pragma once

#include <stdint.h>

/**
 * SysPixie Module types (Konrad Orlowski)
 */
typedef uint8_t VlcbSysPixieModuleType;
enum VlcbSysPixieModuleType {
  /**
   * Motorised point motor driver with current sense
   */
  VLCB_SYSPIXIE_MODULE_CANPMSENSE = 1,
};
