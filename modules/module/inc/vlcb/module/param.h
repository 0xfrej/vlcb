#pragma once

#include <stdint.h>

#include "vlcb/common/module.h"
#include "vlcb/common/vlcb_defs.h"

#ifndef VLCB_MODULE_PARAM_BYTE_COUNT
#define VLCB_MODULE_PARAM_BYTE_COUNT  21
#endif

typedef uint8_t VlcbModuleParamBuf[VLCB_MODULE_PARAM_BYTE_COUNT];

typedef struct {
   VlcbModuleParamBuf buf;
} VlcbModuleParams;

VlcbModuleParams vlcb_module_params_New(
   const VlcbModuleVersion version,
   const VlcbManufacturer moduleManu,
   const VlcbBusType busType,
   const uint8_t moduleType,
   const uint8_t cpuId,
   const VlcbProcessorManufacturer cpuManu,
   const VlcbModuleParamCpuManuId cpuManuId,
   const VlcbModuleParamLoadAddr loadAddr,
   const VlcbModuleFlags moduleFlags,
   const uint8_t nodeVariableCount,
   const uint8_t eventCount,
   const uint8_t eventVariableCount
);