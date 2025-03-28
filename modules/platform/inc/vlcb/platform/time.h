#pragma once

#include <stdint.h>

typedef uint32_t vlcb_clock;

// TODO: implement resolvers, diff, constants or other mechanisms? to resolve
// ns/ms/s from clock
//  implement an overflow count that can be used in-library to accurately detect
//  time spans (only if needed honestly - depends on how fast the overflow
//  happens)
vlcb_clock vlcb_time_Milis();

#define VLCB_MILIS_MAX UINT32_MAX

static inline vlcb_clock vlcb_time_DiffMilis(const vlcb_clock start,
                                             const vlcb_clock end) {
  if (end < start) {
    return (VLCB_MILIS_MAX - start) + end;
  }
  return (end - start);
}
