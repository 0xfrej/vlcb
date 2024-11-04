#pragma once

#include "vlcb/common/node.h"
#include <stdint.h>
#include <time.h>

typedef uint8_t VlcbModuleState;
enum VlcbModuleState {
  VLCB_MODULE_STATE_UNINITIALIZED = 0,
  VLCB_MODULE_STATE_SETUP,
  VLCB_MODULE_STATE_NORMAL,
};

typedef struct {
  VlcbModuleState prevState;
  VlcbNodeNumber nodeAddr;
  clock_t startedAt;
} VlcbModuleStateMachineSetupData;

typedef union {
  VlcbModuleStateMachineSetupData setup;
} VlcbModuleStateMachineData;

typedef struct {
  VlcbModuleState state;
  VlcbModuleStateMachineData data;
} VlcbModuleStateMachine;
