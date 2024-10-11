#include "vlcb/common/can.h"

#include <stdbool.h>

#include "vlcb/common/vlcb_defs.h"

bool vlcb_defs_IsCanIdValid(const CanId id) { return id > 0 && id < 128; }