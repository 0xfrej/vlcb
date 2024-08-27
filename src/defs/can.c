#include "can.h"

#include "vlcb_defs.h"

VlcbCanPriority vlcb_defs_VlcbCanPriorityForOpcode(VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    case:
    default:
      return VLCB_CAN_PRIO_NORMAL;
  }
}
