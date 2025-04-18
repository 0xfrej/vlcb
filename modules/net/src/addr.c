#include "vlcb/net/wire.h"

#include <assert.h>
#include <stdbool.h>

#include "vlcb/common/can.h"

bool vlcb_net_IsWireAddrValid(const VlcbNetMedium medium,
                              const VlcbNetWireAddr addr) {
  switch (medium) {
  case VLCB_MEDIUM_CAN:
    return vlcb_defs_IsCanIdValid(addr.can);
  }
  assert(false /* unimplemented case guard */);
}

VlcbNetWireAddr vlcb_net_NewCanWireAddr(const VlcbCanId id) {
  return (VlcbNetWireAddr){.can = id};
}
