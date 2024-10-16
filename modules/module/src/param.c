#include "vlcb/module/param.h"

#include <assert.h>
#include <stddef.h>

#include "vlcb/common/vlcb_defs.h"

inline uint8_t ModuleParamGetByte(const VlcbModuleParams *const params, const uint8_t index) {
  assert(params != NULL && index < VLCB_MODULE_PARAM_BYTE_COUNT);
  return params->buf[index];
}

inline VlcbModuleParams vlcb_module_params_New(
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
) {
  VlcbModuleParams params = {};

  params.buf[VLCB_MODULE_PARAM_MODULE_PARAMETER_COUNT] =  - 1;
  params.buf[VLCB_MODULE_PARAM_MODULE_MANUFACTURER] = moduleManu;
  params.buf[VLCB_MODULE_PARAM_MINOR_VERSION] = version.minor;
  params.buf[VLCB_MODULE_PARAM_MODULE_TYPE] = moduleType;
  params.buf[VLCB_MODULE_PARAM_MAX_EVENT_COUNT] = eventCount;
  params.buf[VLCB_MODULE_PARAM_EVENT_VARIABLE_COUNT] = eventVariableCount;
  params.buf[VLCB_MODULE_PARAM_NODE_VARIABLE_COUNT] = nodeVariableCount;
  params.buf[VLCB_MODULE_PARAM_MAJOR_VERSION] = version.major;
  params.buf[VLCB_MODULE_PARAM_NODE_FLAGS] = moduleFlags;
  params.buf[VLCB_MODULE_PARAM_CPU_ID] = cpuId;
  params.buf[VLCB_MODULE_PARAM_BUS_TYPE] = busType;
  params.buf[VLCB_MODULE_PARAM_LOAD_ADDRESS] = loadAddr[0];
  params.buf[VLCB_MODULE_PARAM_LOAD_ADDRESS + 1] = loadAddr[1];
  params.buf[VLCB_MODULE_PARAM_LOAD_ADDRESS + 2] = loadAddr[2];
  params.buf[VLCB_MODULE_PARAM_LOAD_ADDRESS + 3] = loadAddr[3];
  params.buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID] = cpuManuId[0];
  params.buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID + 1] = cpuManuId[1];
  params.buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID + 2] = cpuManuId[2];
  params.buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID + 3] = cpuManuId[3];
  params.buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER] = cpuManu;
  params.buf[VLCB_MODULE_PARAM_BETA_VERSION] = version.beta;

  return params;
};