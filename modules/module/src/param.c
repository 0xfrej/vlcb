#include "vlcb/module/param.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "param.h"
#include "vlcb/common/module.h"
#include "vlcb/common/vlcb_defs.h"

inline VlcbModuleParam ModuleParamGetByte(const VlcbModuleParams *const params,
                                          const VlcbModuleParam param) {
  assert(params != NULL && param <= params->len);
  return params->buf[param - 1];
}

inline void vlcb_module_params_Init(
    VlcbModuleParams *const params, const char *const name,
    const VlcbModuleVersion version, const VlcbManufacturer moduleManu,
    const VlcbBusType busType, const uint8_t moduleType, const uint8_t cpuId,
    const VlcbProcessorManufacturer cpuManu,
    const VlcbModuleParamCpuManuId cpuManuId,
    const VlcbModuleParamLoadAddr loadAddr, const VlcbModuleFlags moduleFlags,
    const uint8_t nodeVariableCount, const uint8_t eventCount,
    const uint8_t eventVariableCount) {
  assert(params != NULL && name != NULL &&
         params->len >= VLCB_MODULE_PARAMS_MIN_LEN);

  params->buf[VLCB_MODULE_PARAM_MODULE_MANUFACTURER] = moduleManu;
  params->buf[VLCB_MODULE_PARAM_MINOR_VERSION] = version.minor;
  params->buf[VLCB_MODULE_PARAM_MODULE_TYPE] = moduleType;
  params->buf[VLCB_MODULE_PARAM_MAX_EVENT_COUNT] = eventCount;
  params->buf[VLCB_MODULE_PARAM_EVENT_VARIABLE_COUNT] = eventVariableCount;
  params->buf[VLCB_MODULE_PARAM_NODE_VARIABLE_COUNT] = nodeVariableCount;
  params->buf[VLCB_MODULE_PARAM_MAJOR_VERSION] = version.major;
  params->buf[VLCB_MODULE_PARAM_NODE_FLAGS] = moduleFlags;
  params->buf[VLCB_MODULE_PARAM_CPU_ID] = cpuId;
  params->buf[VLCB_MODULE_PARAM_BUS_TYPE] = busType;
  memcpy(&params->buf[VLCB_MODULE_PARAM_LOAD_ADDRESS], &loadAddr,
         sizeof(VlcbModuleParamLoadAddr));
  memcpy(&params->buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER_ID], &cpuManuId,
         sizeof(VlcbModuleParamCpuManuId));
  params->buf[VLCB_MODULE_PARAM_CPU_MANUFACTURER] = cpuManu;
  params->buf[VLCB_MODULE_PARAM_BETA_VERSION] = version.beta;
};
