#pragma once

#include "vlcb/common/can.h"

typedef enum {
  VLCB_MEDIUM_CAN,
} VlcbNetMedium;

typedef union {
  VlcbCanId can_id;
} VlcbNetHwAddr;

bool vlcb_net_IsHwAddrValid(VlcbNetMedium medium, VlcbNetHwAddr addr);

VlcbNetHwAddr vlcb_net_NewCanIdHwAddr(VlcbCanId id);
