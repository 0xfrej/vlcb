#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include "vlcb/common/can.h"
#include "vlcb/platform/interface.h"
#include "vlcb/platform/error.h"

#define VLCB_NET_ADPT_MAX_PAYLOAD 8

typedef uint8_t VlcbNetAdptPayload[VLCB_NET_ADPT_MAX_PAYLOAD];

#include "adapter/can/packet.h"
#include "vlcb/net/addr.h"

typedef union {
  VlcbNetAdptCanPktMeta can;
} VlcbNetAdptPktMeta;

/**
 * Abstract physical device packet
 *
 * Used to transfer data between the stack and the driver itself.
 * In cases like CAN self-enumeration it's used also for handling
 * the raw CAN packets since they can contain RTR frames.
 */
typedef struct {
  VlcbNetMedium medium;
  VlcbNetHwAddr src_addr;
  VlcbNetAdptPktMeta meta;
  uint8_t payload_len;
  VlcbNetAdptPayload payload;
} VlcbNetAdptPkt;

typedef struct {
  VlcbNetMedium medium;
} VlcbNetAdptCaps;

typedef enum {
  VLCB_NET_ADPT_ERR_OK = 0,

  /**
   * Device is busy or has nothing to transfer.
   *
   * Not an error state, can be used by device drivers
   * to signal that it cannot receive at the moment. The library
   * will do other tasks instead of waiting to do them until next
   * packet will get delivered.
   *
   * It is advisable to use this non-blockking functionality.
   */
  VLCB_NET_ADPT_ERR_WOULD_BLOCK,

  /**
   * Passed in packet for transmission contains unsupported medium by this
   * network device.
   */
  VLCB_NET_ADPT_ERR_UNSUPPORTED_MEDIUM,

  /**
   * Passed in payload had length that was above the limit
   * that the device can transfer.
   */
  VLCB_NET_ADPT_ERR_PAYLOAD_TOO_LARGE,

  VLCB_NET_ADPT_ERR_INVALID_CANID,

  /**
   * Not an actual error, can be used to ensure the returned codes are within
   * valid range.
   */
  VLCB_NET_ADPT_ERR_COUNT,
} VlcbNetAdptErr;

vlcb_error vlcb_net_adpt_ErrToStr(VlcbNetAdptErr err);

_INTERFACE_DECLARE(
  VlcbNetAdpt,

  /**
   * Receive a VLCB packet using this device
   *
   * Returns `VLCB_NET_DEV_ERR_WOULD_BLOCK` when there is nothing
   * in the reception buffer.
   */
  _INTERFACE_METHOD_DECLARE(VlcbNetAdptErr, RecvPkt, _INTERFACE_SELF_PTR_MUT, VlcbNetAdptPkt *const pkt)

  /**
   * Transfer a VLCB packet using this device
   */
  _INTERFACE_METHOD_DECLARE(VlcbNetAdptErr, SendPkt, _INTERFACE_SELF_PTR_MUT, const VlcbNetAdptPkt *const pkt)

  /**
   * Get the device capabilities
   */
  _INTERFACE_METHOD_DECLARE(VlcbNetAdptCaps, Caps, _INTERFACE_SELF_PTR)
)

#define vlcb_net_adpt_impl(T, Name, send_f, receive_f, caps_f)              \
  VlcbNetAdpt Name##_Upcast(T *x) {                                          \
    _TYPE_UPCAST_METHOD_PTR_SIG(send_f, VlcbNetAdptErr, T *const,            \
                                const VlcbNetAdptPkt *const)              \
    _TYPE_UPCAST_METHOD_PTR_SIG(receive_f, VlcbNetAdptErr, T *const,         \
                                VlcbNetAdptPkt *const)                    \
    _TYPE_UPCAST_METHOD_PTR_SIG(caps_f, VlcbNetAdptCaps, const T *const)     \
    _TYPE_UPCAST_VTABLE_DEF(                                                \
        tc, VlcbNetAdptTrait,                                                \
        _TYPE_UPCAST_VTABLE_METHOD_ENTRY(RecvPkt, receive_f, VlcbNetAdptErr, \
                                         void *const,                       \
                                         VlcbNetAdptPkt *const),          \
        _TYPE_UPCAST_VTABLE_METHOD_ENTRY(SendPkt, send_f, VlcbNetAdptErr,       \
                                         void *const,                       \
                                         const VlcbNetAdptPkt *const),    \
        _TYPE_UPCAST_VTABLE_METHOD_ENTRY(Caps, caps_f, VlcbNetAdptCaps,      \
                                         const void *const))                \
    return (VlcbNetAdpt){.tc = &tc, .self = x};               \
  }
