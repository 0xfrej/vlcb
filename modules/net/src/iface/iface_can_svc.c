#include "vlcb/common/can.h"
#include "vlcb/net/adapter.h"
#include "vlcb/net/addr.h"
#include "vlcb/net/iface.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/time.h"
#include <stdint.h>

typedef struct {
  enum { CAN_PKT_INGEST } type;
  union {
    struct {
      const VlcbNetAdptPkt *const pkt;
    } ingest;
  } data;
} CanSvcEvent;

static inline VlcbCanId ResolveFreeId(const uint8_t (*const idCache)[16]) {
  for (uint8_t i = 0; i < 16; i++) {
    for (uint8_t j = 0; j < 8 && (i * 8 + j) < 128; j++) {
      if (!(*idCache[i] & ((uint8_t)(1 << j)))) {
        return i * 8 + j;
      } // TODO: fix these two fnctions
    }
  }
  return VLCB_CAN_ID_EMPTY;
}

static inline void ToggleUsedId(uint8_t (*const idCache)[16], VlcbCanId id) {}

inline void CanSvcEventConsume(VlcbNetWireEndpointHandle endpoint,
                               CanSvcEvent event) {
  switch (event.type) {
  case CAN_PKT_INGEST:
    if (endpoint->meta.can.state == VLCB_NET_WIRE_CAN_STATE_INITIALIZED) {
      if (endpoint->addr.can == event.data.ingest.pkt->srcAddr.can) {
        // handle collisions
        endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED;
        endpoint->addr.can = VLCB_CAN_ID_EMPTY;
      } else if (event.data.ingest.pkt->meta.can.is_rtr) {
        // handle response to enumeration of other nodes
        endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_RESPONDING;
      }
    } else if (endpoint->meta.can.state ==
               VLCB_NET_WIRE_CAN_STATE_ENUMERATING) {
      // handle enumeration
      ToggleUsedId(&endpoint->meta.can.occupiedIdCache,
                   event.data.ingest.pkt->srcAddr.can);
    }
    break;
  }
}

inline void CanSvcProcess(VlcbNetIface *const iface,
                          VlcbNetWireEndpointHandle endpoint, vlcb_clock now) {
  VlcbNetAdptPkt pkt;
  VlcbNetAdptErr err;
  switch (endpoint->meta.can.state) {
  case VLCB_NET_WIRE_CAN_STATE_UNINITIALIZED:;
    pkt = (VlcbNetAdptPkt){
        .medium = VLCB_MEDIUM_CAN,
        .srcAddr = {.can = VLCB_CAN_ID_EMPTY},
        .payloadLen = 0,
        .meta = {.can = {.prio = VLCB_CAN_PRIO_SELF_ENUM, .is_rtr = true}}};
    err = _INTERFACE_PTR_CALL(iface->adpt, SendPkt, &pkt);
    if (err != VLCB_NET_ADPT_ERR_OK) {
      if (err == VLCB_NET_ADPT_ERR_WOULD_BLOCK) {
        break;
      }
      // TODO: log error
    }
    endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_ENUMERATING;
    endpoint->meta.can.lastTimestamp = now;
    break;
  case VLCB_NET_WIRE_CAN_STATE_ENUMERATING:
    if (vlcb_platform_time_DiffInMs(endpoint->meta.can.lastTimestamp, now) >
        100) {
      endpoint->meta.can.state = VLCB_NET_WIRE_CAN_STATE_INITIALIZED;
      VlcbCanId newId = ResolveFreeId(&endpoint->meta.can.occupiedIdCache);
      ToggleUsedId(&endpoint->meta.can.occupiedIdCache, newId);
      endpoint->addr.can = newId;
    }
    break;
  case VLCB_NET_WIRE_CAN_STATE_RESPONDING:;
    pkt = (VlcbNetAdptPkt){
        .medium = VLCB_MEDIUM_CAN,
        .srcAddr = endpoint->addr,
        .payloadLen = 0,
        .meta = {.can = {.prio = VLCB_CAN_PRIO_SELF_ENUM, .is_rtr = true}}};
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
