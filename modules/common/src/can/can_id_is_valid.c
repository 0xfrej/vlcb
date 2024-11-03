#include "vlcb/common/can.h"

#include <stdbool.h>

bool vlcb_defs_IsCanIdValid(const VlcbCanId id) { return id > 0 && id < 128; }
