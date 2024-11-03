#pragma once

#include <stdint.h>

#include "vlcb/common/vlcb_defs.h"
#include "vlcb/module/param.h"

VlcbModuleParam ModuleParamGetByte(const VlcbModuleParams *const params,
                                   const VlcbModuleParam param);
