#include "dev.h"

VlcbNetDevHwAddr vlcb_net_dev_hw_addr_NewCanId(CanId id) {
  return (VlcbNetDevHwAddr){.can_id = id};
}
