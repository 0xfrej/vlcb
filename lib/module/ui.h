#pragma once

#include "module_types.h"
#include "platform/time.h"

typedef struct {
  void (*const Poll)(void *const self, const time_t now);
  void (*const Draw)(void *const self, const VlcbModuleState);
  // void (*const IndicateActivity)(void *const self);
  // void (*const IsResetRequested)(const void *const self);
} VlcbModuleUiTrait;

typedef struct {
  void *const self;
  const VlcbModuleUiTrait *const tc;
} VlcbModuleUi;

