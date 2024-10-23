#pragma once

#include "vlcb/common/node.h"
#include <stdint.h>

typedef uint8_t VlcbModuleState;
enum VlcbModuleState {
  VLCB_MODULE_STATE_UNINITIALIZED = 0,
  VLCB_MODULE_STATE_SETUP,
  VLCB_MODULE_STATE_NORMAL,
};

typedef struct {
  VlcbModuleState prevState;
  VlcbNodeAddr nodeAddr;
} VlcbModuleStateMachineSetupData;

typedef union {
  VlcbModuleStateMachineSetupData setup;
} VlcbModuleStateMachineData;

typedef struct {
  VlcbModuleState state;
  VlcbModuleStateMachineData data;
} VlcbModuleStateMachine;
