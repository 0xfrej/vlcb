#include "iface.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "../../shared/log.h"
#include "iface_can.h"
#include "iface_vlcb.h"

VlcbNetIface vlcb_net_iface_New(VlcbNetDevHwAddr hw_addr,
                                VlcbNodeAddr node_addr) {
  VlcbNetIface iface = {
      .hw_addr = hw_addr,
      .node_addr = node_addr,
      .dev = NULL,
      .interceptors = {.net_dev = NULL},
  };

  return iface;
}

int vlcb_net_iface_Bind(VlcbNetIface *const iface, VlcbNetDev *const dev) {
  assert(iface != NULL && dev != NULL && dev->self &&
         dev->tc /* iface and device need to be valid pointers */);

  assert(iface->dev != NULL /* disallow rebinding */);

  iface->dev = dev;
  iface->interceptors.net_dev = NULL;
  return 0;
}

bool IngressPackets(VlcbNetIface *const iface,
                    const VlcbNetSocketList *const sockets) {
  bool processed_any = false;

  const VlcbNetDev *dev = iface->dev;
  const VlcbNetDevCaps caps = dev->tc->Caps(dev->self);

  do {
    VlcbNetDevPacket *phy_packet;
    VlcbNetDevErr dev_err = dev->tc->Receive(dev->self, phy_packet);

    // device has nothing in buffer and would block execution while waiting
    // for new packets
    if (dev_err == VLCB_NET_DEV_ERR_WOULD_BLOCK) {
      break;
    }

    if (dev_err != VLCB_NET_DEV_ERR_OK) {
      VLCBLOG_ERROR(vlcb_dev_VlcbNetDevErrToStr(dev_err));
    }

    switch (caps.medium) {
      case VLCB_MEDIUM_CAN:
        ProcessCanPacket(iface, sockets, phy_packet);
      default:
        assert(false /* unsupported medium */);
    }

    processed_any = true;
  } while (1);

  return processed_any;
}

bool EgressPackets(VlcbNetIface *const iface,
                   const VlcbNetSocketList *const sockets) {
  bool emitted_any = false;

  const VlcbNetDevCaps caps = iface->dev->tc->Caps(iface->dev->self);
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(sockets);

  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);

    VlcbPacket packet;  // TODO: ensure clean packet

    bool emitted_packet = sock->tc->DispatchPacket(sock->self, &packet);
    // TODO: reject invalid packets -> for example when the packet wasn't filled
    emitted_any |= emitted_packet;
    if (emitted_packet) {
      DispatchVlcbPacket(iface, caps, &packet);
    }
  }

  return emitted_any;
}

VlcbNetIfacePollResult vlcb_net_iface_Poll(
    VlcbNetIface *const iface, const VlcbNetSocketList *const sockets) {
  assert(iface != NULL && sockets != NULL && iface->dev != NULL /* iface, sockets need to be valid pointers and device needs to be initialized */);

  bool readiness_may_have_changed = false;

  do {
    bool did_something = false;

    did_something = IngressPackets(iface, sockets);
    did_something = EgressPackets(iface, sockets);

    if (did_something) {
      readiness_may_have_changed = true;
    } else {
      break;
    }
  } while (1);

  return (VlcbNetIfacePollResult){
      .readiness_may_have_changed = readiness_may_have_changed,
  };
}

void vlcb_net_iface_RegisterNetDevListener(
    VlcbNetIface *const iface, VlcbIfaceNetDevInterceptor listener) {
  assert(iface != NULL &&
         listener != NULL /* iface and listener need to be valid poitners */);

  iface->interceptors.net_dev = listener;
}
