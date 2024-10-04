#include "../../../net/iface/iface.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "../../../../shared/log.h"
#include "../../../net/adapter/adapter.h"
#include "iface_can.h"
#include "iface_vlcb.h"

VlcbNetIface vlcb_net_iface_New(VlcbNetAdpt *const adpt, VlcbNetSocketList *const sockets) {
  assert(adpt != NULL && sockets != NULL);

  VlcbNetIface iface = {
      .adpt = adpt,
      .sockets = sockets
  };

  return iface;
}

bool IngressPackets(VlcbNetIface *const iface) {
  bool processed_any = false;

  const VlcbNetAdpt *adpt = iface->adpt;
  const VlcbNetAdptCaps caps = adpt->tc->Caps(adpt->self);

  do {
    VlcbNetAdptPkt *phy_packet;
    VlcbNetAdptErr dev_err = adpt->tc->RecvPkt(adpt->self, phy_packet);

    // device has nothing in buffer and would block execution while waiting
    // for new packets
    if (dev_err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
      break;
    }

    if (dev_err != VLCB_NET_ADPT_ERR_OK) {
      VLCBLOG_ERROR(vlcb_net_adpt_ErrToStr(dev_err));
    }

    switch (caps.medium) {
      case VLCB_MEDIUM_CAN:
        ProcessCanPacket(iface, phy_packet);
      default:
        assert(false /* unsupported medium */);
    }

    processed_any = true;
  } while (1);

  return processed_any;
}

bool EgressPackets(VlcbNetIface *const iface) {
  bool emitted_any = false;

  const VlcbNetAdptCaps caps = iface->adpt->tc->Caps(iface->adpt->self);
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);

  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    const VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);

    VlcbPacket packet;  // TODO: ensure clean packet

    const bool emitted_packet = sock->tc->DispatchPacket(sock->self, &packet);
    // TODO: reject invalid packets -> for example when the packet wasn't filled
    emitted_any |= emitted_packet;
    if (emitted_packet) {
      const VlcbNetAdptErr err = DispatchVlcbPacket(iface, caps, &packet);
       if (err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
      //todo: handle this somehow
    }

      if (err != VLCB_NET_ADPT_ERR_OK) {
        VLCBLOG_ERROR(vlcb_net_adpt_ErrToStr(err));
      }
    }
  }

  return emitted_any;
}

VlcbNetIfacePollResult vlcb_net_iface_Poll(
    VlcbNetIface *const iface) {
  assert(iface != NULL && iface->adpt != NULL /* iface, sockets need to be valid pointers and device needs to be initialized */);

  bool readiness_may_have_changed = false;

  do {
    bool did_something = false;

    did_something = IngressPackets(iface);
    did_something = EgressPackets(iface);

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

// void vlcb_net_iface_RegisterNetDevListener(
//     VlcbNetIface *const iface, VlcbIfaceNetDevInterceptor listener) {
//   assert(iface != NULL &&
//          listener != NULL /* iface and listener need to be valid poitners
//          */);
//
//   iface->interceptors.net_dev = listener;
// }
