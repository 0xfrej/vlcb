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

// TODO: this is not really an endpoint, how to fix?
//  i think not every socket should automatically mean a new canid but it might
//  make our life easier
//
typedef struct {
  VlcbNetWireAddr addr;
  VlcbNetWireEndpointMeta meta;
} VlcbNetWireEndpoint;

typedef VlcbNetWireEndpoint *const VlcbNetWireEndpointHandle;

// bool vlcb_net_IsWireEndpointReady(VlcbNetWireEndpointHandle endpoint);

// bool vlcb_net_IsWireAddrValid(VlcbNetMedium medium, VlcbNetWireAddr addr);

VlcbNetWireAddr vlcb_net_NewCanWireAddr(VlcbCanId id);
