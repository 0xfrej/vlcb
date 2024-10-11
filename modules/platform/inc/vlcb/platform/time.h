#pragma once

// Alias to libc time.h, used by this SDK to provide easy to shim entry point
// should we need to implement shims for certain platforms. The idea is not to
// reinvent the "time" wheel by introducing custom functions and types.
// this should also keep the footprint as minimal as possible

#include <time.h>

static inline double vlcb_platform_time_DiffInMs(const clock_t start, const clock_t end) {
  return ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
}