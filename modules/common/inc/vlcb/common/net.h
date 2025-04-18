#pragma once

#include <stdint.h>

/**
 * @brief Transport medium type that node is connected to
 */
typedef enum {
  VLCB_BUS_CAN = 1,
  VLCB_BUS_ETHERNET = 2,
  VLCB_BUS_MIWI = 3,
  VLCB_BUS_USB = 4,
} VlcbBusType;
