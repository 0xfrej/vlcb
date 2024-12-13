#include "vlcb/net/iface.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include "iface_can.h"
#include "iface_vlcb.h"
#include "vlcb/net/adapter.h"
#include "vlcb/net/socket.h"
#include "vlcb/platform/log.h"

VlcbNetIface vlcb_net_iface_New(IVlcbNetAdpt *const adpt,
                                VlcbNetSocketList *const sockets) {
  assert(adpt != NULL && sockets != NULL);

  VlcbNetIface iface = {.adpt = adpt, .sockets = sockets};

  return iface;
}

bool IngressPackets(VlcbNetIface *const iface, clock_t now) {
  bool processed_any = false;

  IVlcbNetAdpt *adpt = iface->adpt;
  const VlcbNetAdptCaps caps = _INTERFACE_PTR_CALL(adpt, Caps);

  do {
    VlcbNetAdptPkt *phy_packet;
    VlcbNetAdptErr dev_err = _INTERFACE_PTR_CALL(adpt, RecvPkt, phy_packet);

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
      ProcessCanPacket(iface, phy_packet, now);
    default:
      assert(false /* unsupported medium */);
    }

    processed_any = true;
  } while (1);

  return processed_any;
}

bool EgressPackets(VlcbNetIface *const iface, clock_t now) {
  bool emitted_any = false;

  const VlcbNetAdptCaps caps = _INTERFACE_PTR_CALL(iface->adpt, Caps);
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);

  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    const VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);

    VlcbNetSocketPacketToken packetTok;
    {
      VlcbNetSocketDispatchErr err =
          _INTERFACE_PTR_CALL(sock, DispatchPacket, &packetTok);
      if (err != VLCB_NET_SOCK_DISP_ERR_OK) {
        if (err == VLCB_NET_SOCK_DISP_ERR_WOULD_BLOCK) {
          continue;
        }
        VLCBLOG_ERROR(vlcb_net_sock_DispatchErrToStr(err));
        vlcb_net_sock_packet_token_Refuse(packetTok);
      }
    }

    const VlcbNetAdptErr err =
        DispatchVlcbPacket(iface, caps, &packetTok.packet);

    if (err != VLCB_NET_ADPT_ERR_OK) {
      vlcb_net_sock_packet_token_Refuse(packetTok);
      if (err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
        continue;
      }
      VLCBLOG_ERROR(vlcb_net_adpt_ErrToStr(err));
    }
    emitted_any = true;
  }

  return emitted_any;
}

VlcbNetIfacePollResult vlcb_net_iface_Poll(VlcbNetIface *const iface,
                                           clock_t now) {
  assert(iface != NULL && iface->adpt != NULL /* iface, sockets need to be valid pointers and device needs to be initialized */);

  bool readiness_may_have_changed = false;

  do {
    bool did_something = false;

    did_something |= IngressPackets(iface, now);
    did_something |= EgressPackets(iface, now);

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

bool vlcb_net_iface_BindSock(VlcbNetIface *const iface,
                             VlcbNetSocketHandle sock) {
  assert(iface != NULL && sock != NULL);
  int res = vlcb_net_sock_list_Insert(iface->sockets, sock);
  if (res == -1) {
    return false;
  }
  return true;
}

void vlcb_net_iface_FreeSock(VlcbNetIface *const iface,
                             VlcbNetSocketHandle sock) {
  assert(iface != NULL && sock != NULL);
  vlcb_net_sock_list_Remove(iface->sockets, sock);
}
