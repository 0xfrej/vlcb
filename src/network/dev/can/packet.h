#pragma once

#include <stdbool.h>

typedef struct {
  bool is_rtr;
} VlcbNetDevPacketCanMeta;

#include "../dev.h"

#define VLCB_NET_DEV_CAN_MTU 8
