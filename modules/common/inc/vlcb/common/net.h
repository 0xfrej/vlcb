#pragma once

#include <stdint.h>

/**
 * @brief Transport medium type that node is connected to
 */
typedef uint8_t VlcbBusType;
enum VlcbBusType {
  VLCB_BUS_CAN = 1,
  VLCB_BUS_ETHERNET = 2,
  VLCB_BUS_MIWI = 3,
  VLCB_BUS_USB = 4,
};
