#pragma once

#include <stdbool.h>

#include "../../../defs/can.h"

/**
 * VLCB network device packet metadata for CAN adapter
 */
typedef struct {
  bool is_rtr;
  VlcbCanPriority prio;
} VlcbNetDevPacketCanMeta;

#include "../dev.h"

#define VLCB_NET_DEV_CAN_MTU 8
