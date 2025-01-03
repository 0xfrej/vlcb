#pragma once

#include <stdint.h>

/**
 * @brief Processor manufacturer codes
 */
typedef uint8_t VlcbProcessorManufacturer;
enum VlcbProcessorManufacturer {
  VLCB_PM_MICROCHIP =
      1, /**< Microchip PIC @see VlcbMicrochipProcessor for possible values */
  VLCB_PM_ATMEL = 2, /**< At the moment there is no value enum */
  VLCB_PM_ARM =
      3, /**< ARM type codes @see VlcbArmProcessor for possible values */
};

/**
 * @brief ARM Processor type codes
 *
 * Used by FCU to identify correct bootloader compatibility
 */
typedef uint8_t VlcbArmProcessor;
enum VlcbArmProcessor {
  VLCB_PM_ARM_ARM1176JZFS = 1,
  VLCB_PM_ARM_CORTEXA7 = 2,
  VLCB_PM_ARM_CORTEXA53 = 3,
};

/**
 * @brief Microchip Processor type codes
 *
 * Used by FCU to identify correct bootloader compatibility
 */
typedef uint8_t VlcbMicrochipProcessor;
enum VlcbMicrochipProcessor {
  VLCB_PM_MICROCHIP_P18F2480 = 1,
  VLCB_PM_MICROCHIP_P18F4480 = 2,
  VLCB_PM_MICROCHIP_P18F2580 = 3,
  VLCB_PM_MICROCHIP_P18F4580 = 4,
  VLCB_PM_MICROCHIP_P18F2585 = 5,
  VLCB_PM_MICROCHIP_P18F4585 = 6,
  VLCB_PM_MICROCHIP_P18F2680 = 7,
  VLCB_PM_MICROCHIP_P18F4680 = 8,
  VLCB_PM_MICROCHIP_P18F2682 = 9,
  VLCB_PM_MICROCHIP_P18F4682 = 10,
  VLCB_PM_MICROCHIP_P18F2685 = 11,
  VLCB_PM_MICROCHIP_P18F4685 = 12,
  VLCB_PM_MICROCHIP_P18F25K80 = 13,
  VLCB_PM_MICROCHIP_P18F45K80 = 14,
  VLCB_PM_MICROCHIP_P18F26K80 = 15,
  VLCB_PM_MICROCHIP_P18F46K80 = 16,
  VLCB_PM_MICROCHIP_P18F65K80 = 17,
  VLCB_PM_MICROCHIP_P18F66K80 = 18,
  VLCB_PM_MICROCHIP_P18F25K83 = 19,
  VLCB_PM_MICROCHIP_P18F26K83 = 20,
  VLCB_PM_MICROCHIP_P18F27Q84 = 21,
  VLCB_PM_MICROCHIP_P18F47Q84 = 22,
  VLCB_PM_MICROCHIP_P18F27Q83 = 23,
  VLCB_PM_MICROCHIP_P18F14K22 = 25,
  VLCB_PM_MICROCHIP_P32MX534F064 = 30,
  VLCB_PM_MICROCHIP_P32MX564F064 = 31,
  VLCB_PM_MICROCHIP_P32MX564F128 = 32,
  VLCB_PM_MICROCHIP_P32MX575F256 = 33,
  VLCB_PM_MICROCHIP_P32MX575F512 = 34,
  VLCB_PM_MICROCHIP_P32MX764F128 = 35,
  VLCB_PM_MICROCHIP_P32MX775F256 = 36,
  VLCB_PM_MICROCHIP_P32MX775F512 = 37,
  VLCB_PM_MICROCHIP_P32MX795F512 = 38,
};
