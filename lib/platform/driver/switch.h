#pragma once

#include "platform/time.h"
#include <stdbool.h>
#include <stdint.h>
typedef enum {
  VLCB_PLATFORM_SWITCH_RELEASED,
  VLCB_PLATFORM_SWITCH_PRESSED,
} VlcbPlatformSwitchState;

typedef VlcbPlatformSwitchState (*VlcbPlatformSwitchStatusResolver)(void);

typedef struct {
  VlcbPlatformSwitchState state;
  bool hasChanged;
  VlcbPlatformSwitchStatusResolver resolver;
  time_t lastChangeAt;
  uint32_t prevChangeLastedForMs;
} VlcbPlatformSwitchDriver;

VlcbPlatformSwitchDriver vlcb_platform_switch_New(VlcbPlatformSwitchStatusResolver resolver);