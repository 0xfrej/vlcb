#include "vlcb.h"

// Dummy device driver
// This driver adapter is used throughout examples and is a helper.
// If you look for an actual implementation, look into other examples
// instead.

typedef struct {
} CanDevice;

VlcbNetAdptErr can_dev_receive(CanDevice *const self,
                              VlcbNetAdptPkt *const packet) {
  return VLCB_NET_ADPT_ERR_OK;  // Stubs to satisfy the compiler
}

VlcbNetAdptErr can_dev_send(CanDevice *const self,
                           const VlcbNetAdptPkt *const packet) {
  return VLCB_NET_ADPT_ERR_OK;  // Stub to satisfy the compiler
}

VlcbNetAdptCaps can_dev_caps(const CanDevice *const self) {
  return (VlcbNetAdptCaps){.medium = VLCB_MEDIUM_CAN};
}

// Implement trait and upcast to super type for CanDevice dummy driver
vlcb_net_adpt_impl(CanDevice, avr_can, can_dev_send, can_dev_receive,
                  can_dev_caps);