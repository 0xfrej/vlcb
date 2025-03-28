#pragma once

#include "vlcb/module/state.h"
#include "vlcb/platform/interface.h"

_INTERFACE_DECLARE(
    IVlcbModuleUi,
    _INTERFACE_METHOD_DECLARE(void, IndicateState,
                              _INTERFACE_SELF_PTR_MUT(IVlcbModuleUi),
                              const VlcbModuleState state);
    _INTERFACE_METHOD_DECLARE(void, Poll,
                              _INTERFACE_SELF_PTR_MUT(IVlcbModuleUi),
                              const vlcb_clock now););
