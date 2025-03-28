#pragma once

#include "vlcb/common/can.h"
#include "vlcb/platform/time.h"
#include <stdint.h>

typedef enum {
  VLCB_MEDIUM_CAN,
} VlcbNetMedium;

typedef enum {
  VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED = 0,
  VLCB_NET_WIRE_CAN_STATE_ENUMERATING,
  VLCB_NET_WIRE_CAN_STATE_INITIALIZED,
  VLCB_NET_WIRE_CAN_STATE_RESPONDING,
} VlcbNetWireCanState;

typedef union {
  VlcbCanId can;
} VlcbNetWireAddr;

// TODO: refactor from anonym types - non C99

typedef struct {
  union {
    struct {
      vlcb_clock lastTimestamp;
      VlcbNetWireCanState state;
      uint8_t occupiedIdCache[16];
    } can;
  } meta;
  VlcbNetWireAddr addr;
} VlcbNetWireEndpoint;

typedef VlcbNetWireEndpoint *const VlcbNetWireEndpointHandle;

bool vlcb_net_IsWireEndpointValid(VlcbNetWireEndpointHandle endpoint);

bool vlcb_net_IsWireAddrValid(VlcbNetMedium medium, VlcbNetWireAddr addr);

VlcbNetWireAddr vlcb_net_NewCanWireAddr(VlcbCanId id);
