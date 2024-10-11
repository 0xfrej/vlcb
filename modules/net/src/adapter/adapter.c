#include "vlcb/net/adapter.h"

#include <assert.h>
#include <stddef.h>

#include "vlcb/common/can.h"

int vlcb_net_BindAdpt(VlcbNetAdpt *const dev, const void *const owner) {
  assert(dev != NULL && owner != NULL);
  if (dev->owner != NULL) {
    return 1;  // device is already bound to something
  }
  dev->owner = owner;
  return 0;
}

bool vlcb_net_IsHwAddrValid(VlcbNetMedium medium, VlcbNetHwAddr addr) {
  switch (medium) {
    case VLCB_MEDIUM_CAN:
      return vlcb_defs_IsCanIdValid(addr.can_id);
  }
  assert(false /* unimplemented case guard */);
}

VlcbNetHwAddr vlcb_net_NewCanIdHwAddr(CanId id) {
  return (VlcbNetHwAddr){.can_id = id};
}

vlcb_error vlcb_net_adpt_ErrToStr(VlcbNetAdptErr err) {
  assert(err > VLCB_NET_ADPT_ERR_OK && err < VLCB_NET_ADPT_ERR_COUNT);
  switch (err) {
    case VLCB_NET_ADPT_ERR_WOULD_BLOCK:
      return "call would block";
    case VLCB_NET_ADPT_ERR_UNSUPPORTED_MEDIUM:
      return "unsupported medium";
    case VLCB_NET_ADPT_ERR_PAYLOAD_TOO_LARGE:
      return "payload is too large";
    case VLCB_NET_ADPT_ERR_INVALID_CANID:
      return "invalid CAN id";
  }
  assert(false /* unimplemented case guard */);
}
