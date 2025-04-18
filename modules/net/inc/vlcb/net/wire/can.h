#pragma once

#include "vlcb/platform/time.h"

typedef enum {
  VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED = 0,
  VLCB_NET_WIRE_CAN_STATE_ENUMERATING,
  VLCB_NET_WIRE_CAN_STATE_INITIALIZED,
  VLCB_NET_WIRE_CAN_STATE_RESPONDING,
} VlcbNetWireCanState;

typedef struct {
  VlcbNetWireCanState state;
  vlcb_clock lastTimestamp;
} VlcbNetWireCanStateMachine;
