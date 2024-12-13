#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "vlcb/platform/time.h"

typedef enum {
  VLCB_PLATFORM_LED_FX_BLINK,
  VLCB_PLATFORM_LED_FX_PULSE
} VlcbPlatformLedEffectType;

typedef struct {
  uint16_t hz;
} VlcbPlatformLedEffectDataBlink;

typedef struct {
  uint32_t durationMs;
} VlcbPlatformLedEffectDataPulse;

typedef union {
  VlcbPlatformLedEffectDataPulse pulse;
  VlcbPlatformLedEffectDataBlink blink;
} VlcbPlatformLedEffectData;

typedef struct {
  bool hasStarted;
  VlcbPlatformLedEffectType type;
  VlcbPlatformLedEffectData data;
  vlcb_milis currentCycleStartedAt;
  vlcb_milis startedAt;
  uint32_t duration;
} VlcbPlatformLedEffect;

VlcbPlatformLedEffect vlcb_platform_led_fx_Blink(uint16_t hz);
VlcbPlatformLedEffect vlcb_platform_led_fx_Pulse(uint32_t duration_ms);

typedef enum {
  VLCB_PLATFORM_LED_OFF,
  VLCB_PLATFORM_LED_ON,
} VlcbPlatformLedState;

typedef VlcbPlatformLedState (*VlcbPlatformLedStatusResolver)(void);
typedef void (*VlcbPlatformLedStatusChangeHandler)(void);

typedef struct {
  VlcbPlatformLedState state;
  bool hasEffect;
  VlcbPlatformLedEffect effect;
  VlcbPlatformLedStatusResolver statusResolver;
  VlcbPlatformLedStatusChangeHandler statusChangeHandler;
} VlcbPlatformLedDriver;

VlcbPlatformLedDriver
vlcb_platform_led_New(VlcbPlatformLedStatusResolver resolver,
                      VlcbPlatformLedStatusChangeHandler changeHandler);
