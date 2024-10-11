#include "vlcb/common/can.h"

#include "vlcb/common/vlcb_defs.h"

VlcbCanPriority vlcb_defs_CanPriorityFromOpcode(const VlcbOpCode opc) {
  // TODO: copy the logic from rust project
  switch (opc) {
    default:
      return VLCB_CAN_PRIO_DEFAULT;
  }
}