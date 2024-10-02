#include "dev.h"

#include <assert.h>
#include <stddef.h>

#include "../../defs/can.h"

int vlcb_net_dev_Bind(VlcbNetDev *const dev, const void *const owner) {
  assert(dev != NULL && owner != NULL);

  if (dev->owner != NULL) {
    return 1;  // device is already bound to something
  }

  dev->owner = owner;
  return 0;
}

bool vlcb_net_dev_IsHwAddrValid(VlcbMedium medium, VlcbNetDevHwAddr addr) {
  switch (medium) {
    case VLCB_MEDIUM_CAN:
      return vlcb_defs_IsCanIdValid(addr.can_id);
    default:
      assert(false /* unimplemented case guard */);
  }
}

VlcbNetDevHwAddr vlcb_net_dev_NewCanIdHwAddr(CanId id) {
  return (VlcbNetDevHwAddr){.can_id = id};
}

vlcb_error vlcb_net_dev_VlcbNetDevErrToStr(VlcbNetDevErr err) {
  assert(err > VLCB_NET_DEV_ERR_OK && err < VLCB_NET_DEV_ERR_COUNT);
  switch (err) {
    case VLCB_NET_DEV_ERR_WOULD_BLOCK:
      return "call would block";
    case VLCB_NET_DEV_ERR_UNSUPPORTED_MEDIUM:
      return "unsupported medium";
    case VLCB_NET_DEV_ERR_PAYLOAD_TOO_LARGE:
      return "payload is too large";
    case VLCB_NET_DEV_ERR_INVALID_CANID:
      return "invalid CAN id";
  }
}
