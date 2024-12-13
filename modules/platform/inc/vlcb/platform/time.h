#pragma once

#include <stdint.h>

typedef uint32_t vlcb_milis;

vlcb_milis vlcb_time_Milis();

#define VLCB_MILIS_MAX UINT32_MAX

static inline vlcb_milis vlcb_time_DiffMilis(const vlcb_milis start,
                                             const vlcb_milis end) {
  if (end < start) {
    return (VLCB_MILIS_MAX - start) + end;
  }
  return (end - start);
}
