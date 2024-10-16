#pragma once

#include <stdint.h>

typedef uint8_t VlcbModuleParamLoadAddr[4];
#define VLCB_MODULE_LOAD_ADDR_EMPTY (VlcbModuleParamLoadAddr){0x00, 0x00, 0x00, 0x00}

typedef char VlcbModuleParamCpuManuId[4];
#define VLCB_MODULE_CPU_MANUID_UNKNOWN (VlcbModuleParamCpuManuId){'?', '?', '?', '?'}

#define VLCB_VERSION(major, minor) (VlcbModuleVersion){.major = major, .minor = minor .beta = 0}
#define VLCB_VERSION_BETA(major, minor, beta) (VlcbModuleVersion){.major = major, .minor = minor .beta = beta}

typedef struct {
  uint8_t major;
  char minor;
  uint8_t beta;
} VlcbModuleVersion;