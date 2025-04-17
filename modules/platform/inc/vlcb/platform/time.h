#pragma once

#include <stdint.h>

#define VLCB_TIME_CLOCK_MAX UINT16_MAX

/**
 * Vlcb time representation in millisecond resolution
 *
 * This abstraction is crucial as different platforms
 * use different (or none) implementations of `time.h`
 * and are therefore unreliable.
 */
typedef uint16_t vlcb_clock;

vlcb_clock vlcb_time_GetClock();

static inline vlcb_clock vlcb_time_ClockDiff(const vlcb_clock start,
                                             const vlcb_clock end) {
  if (end < start) {
    return (VLCB_TIME_CLOCK_MAX - start) + end;
  }
  return (end - start);
}
