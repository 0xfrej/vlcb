#include "vlcb/net/addr.h"

#include <assert.h>
#include <stdbool.h>

#include "vlcb/common/can.h"

bool vlcb_net_IsHwAddrValid(const VlcbNetMedium medium,
                            const VlcbNetHwAddr addr) {
  switch (medium) {
  case VLCB_MEDIUM_CAN:
    return vlcb_defs_IsCanIdValid(addr.can_id);
  }
  assert(false /* unimplemented case guard */);
}

VlcbNetHwAddr vlcb_net_NewCanIdHwAddr(const VlcbCanId id) {
  return (VlcbNetHwAddr){.can_id = id};
}
