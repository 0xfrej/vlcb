#pragma once

#include <stdint.h>

/**
 * Manufacturer definitions
 *
 * Here are definitions for all known MERG registered manufacturers.
 */
typedef uint8_t VlcbManufacturer;
enum VlcbManufacturer {

  /**
   * Develoment mode manufacturer
   *
   * For manufacturers who don't have a manufacturer id yet or
   * for lib developers during testing.
   *
   * Do not use in production!
   */
  VLCB_MANU_DEVELOPMENT = 13,

  /**
   * https://www.merg.co.uk
   */
  VLCB_MANU_MERG = 165,

  /**
   * https://www.sprog-dcc.co.uk/
   */
  VLCB_MANU_SPROG = 44,

  /**
   * http://www.rocrail.net
   */
  VLCB_MANU_ROCRAIL = 70,

  /**
   * http://animatedmodeler.com  (Spectrum Engineering)
   */
  VLCB_MANU_SPECTRUM = 80,

  /**
   * range of MERG VLCB modules
   */
  VLCB_MANU_MERG_VLCB = 250,

  /**
   * Konrad Orlowski
   */
  VLCB_MANU_SYSPIXIE = 249,

  /**
   * http://rmeuk.com  (Railway Modelling Experts Limited)
   */
  VLCB_MANU_RME = 248,
};
