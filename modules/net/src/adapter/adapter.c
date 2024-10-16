#include "vlcb/net/adapter.h"

#include <assert.h>

#include "vlcb/common/can.h"

vlcb_error vlcb_net_adpt_ErrToStr(const VlcbNetAdptErr err) {
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
