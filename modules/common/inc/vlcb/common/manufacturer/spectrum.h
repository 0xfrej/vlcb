#pragma once

#include <stdint.h>

/**
 * Spectrum Engineering Animated Modeller module types
 */
typedef enum {
  /**
   * Animation controller (firmware derived from cancmd)
   */
  VLCB_SPECTRUM_MODULE_AMCTRLR = 1,

  /**
   * Dual cab based on cancab
   */
  VLCB_SPECTRUM_MODULE_DUALCAB = 2,
} VlcbSpectrumModuleType;
