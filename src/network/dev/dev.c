#include "dev.h"

#include "../../defs/can.h"

VlcbNetDevHwAddr vlcb_net_dev_NewCanIdHwAddr(CanId id) {
  return (VlcbNetDevHwAddr){.can_id = id};
}
