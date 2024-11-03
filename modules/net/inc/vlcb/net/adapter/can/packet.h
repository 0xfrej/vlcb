#pragma once

#include <stdbool.h>

#include "vlcb/common/can.h"

/**
 * VLCB network device packet metadata for CAN adapter
 */
typedef struct {
  bool is_rtr;
  VlcbCanPriority prio;
} VlcbNetAdptCanPktMeta;

#define VLCB_NET_ADPT_CAN_MAX_PAYLOAD 8
