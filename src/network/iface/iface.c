#include "iface.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#include "iface_can.h"

VlcbNetIface vlcb_iface_New(VlcbNetDevHwAddr hw_addr, VlcbNodeAddr node_addr) {
  VlcbNetIface iface = {
      .hw_addr = hw_addr,
      .node_addr = node_addr,
      .dev = NULL,
  };

  return iface;
}

int vlcb_iface_Bind(VlcbNetIface *const iface, VlcbNetDev *const dev) {
  assert(iface != NULL && dev != NULL);
  // TODO: check if the device is valid
  iface->dev = dev;
  return 0;
}

bool IngressPackets(VlcbNetIface *const iface,
                    VlcbNetSocketList *const sockets) {
  bool processed_any = false;

  const VlcbNetDev *dev = iface->dev;
  const VlcbNetDevCaps *caps = dev->tc->Caps(dev->self);

  do {
    VlcbNetDevPacket *phy_packet;
    VlcbNetDevErr err = dev->tc->Receive(dev->self, phy_packet);
    if (err == VLCB_NET_DEV_ERR_OK) {
      switch (caps->medium) {
        case VLCB_MEDIUM_CAN:
          ProcessCanPacket(iface, sockets, phy_packet);
        default:
          return false;
          // TODO: throw in debug? this would be a bug
      }
    }
    // TODO: how to handle errors?
  } while (1);

  return processed_any;
}

bool EgressPackets(VlcbNetIface *const iface,
                   VlcbNetSocketList *const sockets) {
  bool emitted_any = false;

  const VlcbNetDev *dev = iface->dev;

  return emitted_any;
}

bool vlcb_iface_Poll(VlcbNetIface *const iface,
                     VlcbNetSocketList *const sockets) {
  assert(iface != NULL && sockets != NULL && iface->dev != NULL);

  bool readiness_may_have_changed = false;

  // TODO: (probably return just an error?) create panic of sorts? when the
  // passed in device is not matching caps of this

  do {
    bool did_something = false;

    did_something |= IngressPackets(iface, sockets);
    did_something |= EgressPackets(iface, sockets);

    if (did_something) {
      readiness_may_have_changed = true;
    } else {
      break;
    }
  } while (1);

  return readiness_may_have_changed;
}
