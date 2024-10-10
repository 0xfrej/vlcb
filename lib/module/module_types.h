#pragma once

typedef enum {
  VLCB_MODULE_STATE_UNINITIALIZED = 0,
  VLCB_MODULE_STATE_SETUP = 1,
  VLCB_MODULE_STATE_NORMAL = 2,
} VlcbModuleState;

typedef enum {
  VLCB_MODULE_FLAGS_HEARTBEAT = 0b00000001,
  VLCB_MODULE_FLAGS_EVENT_ACK = 0b00000010,
} VlcbModuleFlags;

typedef struct {
  VlcbModuleState state;
  VlcbModuleFlags flags;
  VlcbNodeAddr nodeAddr;
} VlcbModuleConfig;
