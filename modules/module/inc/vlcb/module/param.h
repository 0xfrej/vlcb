#pragma once

#include <stdint.h>

#include "vlcb/common/module.h"
#include "vlcb/common/vlcb_defs.h"

#define VLCB_MODULE_PARAMS_MIN_LEN 20

#define VLCB_MODULE_PARAMS(name, len)                                          \
  uint8_t name##_data[sizeof(VlcbModuleParams) + sizeof(uint8_t) * len];       \
  VlcbModuleParams *const name = (VlcbModuleParams *const)name##_data;

#define VLCB_MODULE_PARAMS_STD(name)                                           \
  VLCB_MODULE_PARAMS(name, VLCB_MODULE_PARAMS_MIN_LEN)

typedef struct {
  uint8_t len;
  uint8_t buf[];
} VlcbModuleParams;

void vlcb_module_params_Init(
    VlcbModuleParams *const params, const VlcbModuleVersion version,
    const VlcbManufacturer moduleManu, const VlcbBusType busType,
    const uint8_t moduleType, const uint8_t cpuId,
    const VlcbProcessorManufacturer cpuManu,
    const VlcbModuleParamCpuManuId cpuManuId,
    const VlcbModuleParamLoadAddr loadAddr, const VlcbModuleFlags moduleFlags,
    const uint8_t nodeVariableCount, const uint8_t eventCount,
    const uint8_t eventVariableCount);
