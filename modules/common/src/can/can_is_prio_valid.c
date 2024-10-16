#include "vlcb/common/can.h"

#include <stdbool.h>

bool vlcb_defs_IsCanPriorityValid(const VlcbCanPriority prio) {
  switch (prio) {
    case VLCB_CAN_PRIO_SELF_ENUM:
    case VLCB_CAN_PRIO_HIGH:
    case VLCB_CAN_PRIO_ABOVE:
    case VLCB_CAN_PRIO_NORMAL:
    case VLCB_CAN_PRIO_LOW:
    case VLCB_CAN_PRIO_LOWEST:
      return true;
    default:
      return false;
  }
}