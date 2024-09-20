#include "../../src/vlcb.h"

typedef struct {
} CanDevice;

VlcbNetDevErr can_dev_receive(CanDevice *self, VlcbPacket *packet) {
  return VLCB_NET_DEV_ERR_OK;
}

VlcbNetDevErr can_dev_send(CanDevice *self, VlcbPacket packet) {
  return VLCB_NET_DEV_ERR_OK;
}

impl_vlcb_net_dev(CanDevice, avr_can, can_dev_send, can_dev_receive);

int main(void) {
  CanDevice candev = {};
  VlcbNetDev netdev = downcast_avr_can(&candev);

  return 0;
}
