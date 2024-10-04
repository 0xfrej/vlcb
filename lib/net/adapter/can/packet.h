#pragma once

#include <stdbool.h>

#include "../../../defs/can.h"

/**
 * VLCB network device packet metadata for CAN adapter
 */
typedef struct {
  bool is_rtr;
  VlcbCanPriority prio;
} VlcbNetAdptCanPktMeta;

#define VLCB_NET_CAN_MTU 8
