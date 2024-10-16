#pragma once

#include "vlcb/platform/time.h"
#include "vlcb/platform/interface.h"

_INTERFACE_DECLARE(VlcbModuleUi,
  _INTERFACE_METHOD_DECLARE(void, IndicateState, _INTERFACE_SELF_PTR_MUT, const VlcbModuleState state)
  _INTERFACE_METHOD_DECLARE(void, Poll, _INTERFACE_SELF_PTR_MUT, const clock_t now)
)

#define VLCB_MODULE_UI_NULL _INTERFACE_NULL(VlcbModuleUi)