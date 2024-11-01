#pragma once

#include "vlcb/module/state.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/time.h"

_INTERFACE_DECLARE(
    IVlcbModuleUi,
    _INTERFACE_METHOD_DECLARE(void, IndicateState,
                              _INTERFACE_SELF_PTR_MUT(IVlcbModuleUi),
                              const VlcbModuleState state);
    _INTERFACE_METHOD_DECLARE(void, Poll,
                              _INTERFACE_SELF_PTR_MUT(IVlcbModuleUi),
                              const clock_t now););
