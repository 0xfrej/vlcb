#include "vlcb/platform/time.h"

#include <stdint.h>
#include "vlcb/platform/time.h"

// TODO: refactor
vlcb_clock vlcb_time_Milis() {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  return ts.tv_sec * 1000U + ts.tv_nsec / 1000000;
}
