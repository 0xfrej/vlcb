#pragma once

#include "vlcb/common/node.h"
#include "vlcb/module.h"
#include "vlcb/platform/time.h"

typedef enum {
  MSE_INIT,
  MSE_UI_REQ_TO_SETUP,
  MSE_UI_REQ_TO_PREV,
  MSE_MODE_REQ_TO_SETUP,
  MSE_MODE_REQ_TO_NORMAL,
  MSE_MODE_MSG_FOR_ANOTHER_MODULE,
  MSE_NNRSM_MSG,
  MSE_SNN_MSG,
  MSE_ABORT_SETUP,
  MSE_POLL,
} ModuleStateEventSignal;

typedef struct {
  VlcbNodeNumber nodeAddr;
} ModuleStateEventSnnMsgData;

typedef union {
  ModuleStateEventSnnMsgData snnMsg;
} ModuleStateEventData;

typedef struct {
  ModuleStateEventSignal sig;
  ModuleStateEventData data;
} ModuleStateEvent;

void state_Dispatch(VlcbModule *const self, const ModuleStateEvent e,
                    vlcb_clock now);
