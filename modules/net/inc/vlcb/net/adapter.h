#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include "vlcb/platform/error.h"
#include "vlcb/platform/interface.h"

#define VLCB_NET_ADPT_MAX_PAYLOAD 8

typedef uint8_t VlcbNetAdptPayload[VLCB_NET_ADPT_MAX_PAYLOAD];

#include "adapter/can/packet.h"
#include "vlcb/net/wire.h"

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
  // TODO: remove this as we can assume this being always right (adapter is
  // bound to interface)
  VlcbNetMedium medium;
  VlcbNetWireAddr srcAddr;
  VlcbNetAdptPktMeta meta;
  uint8_t payloadLen;
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
    IVlcbNetAdpt,

    /**
     * Receive a VLCB packet using this device
     *
     * Returns `VLCB_NET_DEV_ERR_WOULD_BLOCK` when there is nothing
     * in the reception buffer.
     */
    _INTERFACE_METHOD_DECLARE(VlcbNetAdptErr, RecvPkt,
                              _INTERFACE_SELF_PTR_MUT(IVlcbNetAdpt),
                              VlcbNetAdptPkt *const pkt);

    /**
     * Transfer a VLCB packet using this device
     */
    _INTERFACE_METHOD_DECLARE(VlcbNetAdptErr, SendPkt,
                              _INTERFACE_SELF_PTR_MUT(IVlcbNetAdpt),
                              const VlcbNetAdptPkt *const pkt);

    /**
     * Get the device capabilities
     */
    _INTERFACE_METHOD_DECLARE(VlcbNetAdptCaps, Caps,
                              _INTERFACE_SELF_PTR(IVlcbNetAdpt)););
;
