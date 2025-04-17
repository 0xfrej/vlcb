#include "vlcb/platform/time.h"

#include <time.h>

vlcb_clock vlcb_time_GetClock() {
  return (vlcb_clock)((clock() * 1000) / CLOCKS_PER_SEC);
}
