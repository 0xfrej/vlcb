#include <stdint.h>
#include <string.h>
#include "vlcb/common/can.h"
#include "vlcb/net/adapter.h"
#include "vlcb/net/iface.h"
#include "vlcb/net/socket.h"
#include "vlcb/net/wire.h"
#include "vlcb/net/wire/can.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/time.h"

static inline VlcbCanId ResolveFreeId(VlcbNetIfaceMediumMetaCan* canMeta) {
  for (uint8_t i = 0; i < 16; i++) {
    for (uint8_t j = 0; j < 8 && (i * 8 + j) < 128; j++) {
      if (!(canMeta->canIdAliasOccupationCache[i] & ((uint8_t)(1 << j)))) {
        return i * 8 + j;
      } // TODO: fix these two fnctions
    }
  }
  return VLCB_CAN_ID_EMPTY;
}

static inline void MarkUsedId(VlcbNetIfaceMediumMetaCan *canMeta, VlcbCanId id) {}

static inline void RefreshCache(VlcbNetIfaceMediumMetaCan *canMeta, VlcbNetIface* iface)
{
  memset(&canMeta->canIdAliasOccupationCache, 0, sizeof(canMeta->canIdAliasOccupationCache));

  // hydrate cache with endpoint aliases registered on this interface as they
  // have no other way of communicating the enumeration
  VlcbNetSocketListIter iter = vlcb_net_sock_list_GetIterator(iface->sockets);
  while (vlcb_net_sock_list_iter_HasNext(&iter)) {
    VlcbNetSocketHandle sock = vlcb_net_sock_list_iter_Next(&iter);
    VlcbNetWireEndpointHandle endpoint = sock->WireEndpoint(sock);

    if (endpoint->addr.can != VLCB_CAN_ID_EMPTY) {
      MarkUsedId(canMeta, endpoint->addr.can);
    }
  }
}


static inline void SM_CollisionDetected(VlcbNetWireEndpointHandle endpoint,
                                        VlcbNetWireCanStateMachine *sm) {
  sm->state = VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED;
  endpoint->addr.can = VLCB_CAN_ID_EMPTY;
}

static inline void SM_RespondToEnumeration() {
  endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_RESPONDING;
}

static inline void
SM_ProcessEnumerationResponse(VlcbNetIface *iface,
                              const VlcbNetAdptPkt *const pkt) {
  MarkUsedId(&iface->canIdAliasOccupationCache, pkt->srcAddr.can);
}

inline void CanSvcPktIngest(VlcbNetIface *iface,
                            VlcbNetWireEndpointHandle endpoint,
                            const VlcbNetAdptPkt *const pkt) {
  VlcbNetWireCanStateMachine *sm = &endpoint->meta.can;
  VlcbNetWireCanState state = sm->state;

  if (state == VLCB_NET_WIRE_CAN_STATE_INITIALIZED ||
      state == VLCB_NET_WIRE_CAN_STATE_RESPONDING) {
    if (endpoint->addr.can == pkt->srcAddr.can) {
      SM_CollisionDetected(endpoint, sm);
    } else if (pkt->meta.can.isRtr) {
      SM_RespondToEnumeration();
    }
  } else if (sm->state == VLCB_NET_WIRE_CAN_STATE_ENUMERATING) {
    SM_ProcessEnumerationResponse(iface, pkt);
  }
}

inline void CanSvcPoll(VlcbNetIface *iface,
                       VlcbNetWireEndpointHandle endpoint) {
  VlcbNetWireCanStateMachine *sm = &endpoint->meta.can;
  VlcbNetWireCanState state = sm->state;
}

// TODO:
// how to make sure cache can work with ids assumed by endpoints registered on
// this interface ? clean that cache when the endpoint gets removed ? we should
// make the state allow only one enumeration at a time
//  this allows us to write code that will allow better support of multiple
//  sockets and prohibits flooding network with requests when this lib is used
//  by a gateway which spawns a bunch of stuff
// we should clean the cache as soon as we detect enumeration to ensure it's
// always fresh
//  only endpoints registered on this interface should be prefilled in the cache
//  before the enumeration starts as they cannot respond to the requests

inline int CanSvcInitialize(VlcbNetIface *iface,
                            VlcbNetWireEndpointHandle endpoint,
                            vlcb_clock now) {
  VlcbNetWireCanStateMachine *sm = &endpoint->meta.can;

  if (sm->state == VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED) {
    VlcbNetAdptPkt pkt = (VlcbNetAdptPkt){
        .medium = VLCB_MEDIUM_CAN,
        .srcAddr = {.can = VLCB_CAN_ID_EMPTY},
        .payloadLen = 0,
        .meta = {.can = {.prio = VLCB_CAN_PRIO_SELF_ENUM, .isRtr = true}}};
    VlcbNetAdptErr err = _INTERFACE_PTR_CALL(iface->adpt, SendPkt, &pkt);
    if (err != VLCB_NET_ADPT_ERR_OK) {
      if (err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
        return 1;
      }
      return -1;
    }
    endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_ENUMERATING;
    endpoint->meta.can.lastTimestamp = now;
    return 0;
  }

  return -1;
}

inline void CanSvcProcess(VlcbNetIface *const iface,
                          VlcbNetWireEndpointHandle endpoint, vlcb_clock now) {
  VlcbNetAdptPkt pkt;
  VlcbNetAdptErr err;
  switch (endpoint->meta.can.state) {
  case VLCB_NET_WIRE_CAN_STATE_ENUMERATING:
    if (vlcb_platform_time_DiffInMs(endpoint->meta.can.lastTimestamp, now) >
        100) {
      endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_INITIALIZED;
      VlcbCanId newId = ResolveFreeId(&endpoint->meta.can.occupiedIdCache);
      MarkUsedId(&endpoint->meta.can.occupiedIdCache, newId);
      endpoint->addr.can = newId;
    }
    break;
  case VLCB_NET_WIRE_CAN_STATE_RESPONDING:;
    pkt = (VlcbNetAdptPkt){
        .medium = VLCB_MEDIUM_CAN,
        .srcAddr = endpoint->addr,
        .payloadLen = 0,
        .meta = {.can = {.prio = VLCB_CAN_PRIO_SELF_ENUM, .isRtr = true}}};
    err = _INTERFACE_PTR_CALL(iface->adpt, SendPkt, &pkt);
    if (err != VLCB_NET_ADPT_ERR_OK) {
      if (err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
        break;
      }
      // TODO: log error
    }
    endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_INITIALIZED;
    break;
  default:
    break;
  }
}
