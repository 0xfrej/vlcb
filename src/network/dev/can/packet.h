#pragma once

#include <inttypes.h>
#include <stdbool.h>

#define VLCB_NET_DEV_CAN_MTU 8

typedef struct {
  bool is_rtr;
} VlcbNetDevPacketCanMeta;
