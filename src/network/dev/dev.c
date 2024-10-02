#include "dev.h"

#include <assert.h>

#include "../../defs/can.h"

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
