#pragma once

#include "vlcb/common/can.h"
#include "vlcb/net/wire/can.h"
#include <stdint.h>

typedef enum {
  VLCB_MEDIUM_CAN,
} VlcbNetMedium;

typedef union {
  VlcbCanId can;
} VlcbNetWireAddr;

typedef union {
  VlcbNetWireCanStateMachine can;
} VlcbNetWireEndpointMeta;

typedef struct {
  VlcbNetMedium medium;
  VlcbNetWireAddr addr;
  VlcbNetWireEndpointMeta meta;
} VlcbNetWireEndpoint;

typedef VlcbNetWireEndpoint *const VlcbNetWireEndpointHandle;

bool vlcb_net_IsWireEndpointReady(VlcbNetWireEndpointHandle endpoint);

bool vlcb_net_IsWireAddrValid(VlcbNetMedium medium, VlcbNetWireAddr addr);

VlcbNetWireAddr vlcb_net_NewCanWireAddr(VlcbCanId id);
