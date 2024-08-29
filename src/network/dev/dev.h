#pragma once

#include <inttypes.h>
#include <stdbool.h>

#include "can/packet.h"

typedef union {
  VlcbNetDevPacketCanMeta can;
} VlcbNetDevPacketMeta;

typedef union {
  CanId can_id;
} VlcbNetDevHwAddr;

#define VLCB_NET_DEV_PACKET_MAX_PAYLOAD 8

typedef uint8_t VlcbNetDevPacketPayload[VLCB_NET_DEV_PACKET_MAX_PAYLOAD];

typedef enum {
  VLCB_MEDIUM_CAN,
} VlcbMedium;

/**
 * Abstract physical device packet
 *
 * Used to transfer data between the stack and the driver itself.
 * In cases like CAN self-enumeration it's used also for handling
 * the raw CAN packets since they can contain RTR frames.
 */
typedef struct {
  VlcbMedium medium;
  VlcbNetDevHwAddr src_addr;
  VlcbNetDevPacketMeta meta;
  uint8_t payload_len;
  VlcbNetDevPacketPayload payload;
} VlcbNetDevPacket;

typedef struct {
  VlcbMedium medium;
} VlcbNetDevCaps;

typedef enum {
  VLCB_NET_DEV_ERR_OK = 0,

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
  VLCB_NET_DEV_ERR_WOULD_BLOCK,

  /**
   * Passed in packet for transmission contains unsupported medium by this
   * network device.
   */
  VLCB_NET_DEV_ERR_UNSUPPORTED_MEDIUM,

  /**
   * Passed in payload had length that was above the limit
   * that the device can transfer.
   */
  VLCB_NET_DEV_ERR_PAYLOAD_TOO_LARGE,

  /**
   * Not an actual error, can be used to ensure the returned codes are within
   * valid range.
   */
  VLCB_NET_DEV_ERR_COUNT,
} VlcbNetDevErr;

const char *vlcb_dev_VlcbNetDevErrToStr(VlcbNetDevErr err);

typedef struct Dev {
  /**
   * Receive a VLCB packet using this device
   *
   * Returns `VLCB_NET_DEV_ERR_WOULD_BLOCK` when there is nothing
   * in the receive buffer.
   */
  VlcbNetDevErr (*const Receive)(void *const self,
                                 VlcbNetDevPacket *const packet);

  /**
   * Transfer a VLCB packet using this device
   */
  VlcbNetDevErr (*const Send)(void *const self,
                              const VlcbNetDevPacket *const packet);

  /**
   * Get the device capabilities
   */
  const VlcbNetDevCaps *(*const Caps)(const void *const self);
} VlcbNetDevTrait;

typedef struct {
  void *self;
  VlcbNetDevTrait const *tc;
} VlcbNetDev;

// TODO: change this to more of style I wrote socket stuff -> have reusable
// trait implementation to save bytes
#define vlcb_impl_net_dev(T, Name, send_f, receive_f, caps_f)               \
  VlcbNetDev Name##_upcast(T *x) {                                          \
    VlcbNetDevErr (*const send_)(T *const, const VlcbNetDevPacket *const) = \
        (send_f);                                                           \
    (void)send_;                                                            \
    VlcbNetDevErr (*const receive_)(T *const, VlcbNetDevPacket *const) =    \
        (receive_f);                                                        \
    (void)receive_;                                                         \
    const VlcbNetDevErr *(*const caps)(const T *const) = (caps_f);          \
    (void)caps_;                                                            \
    static VlcbNetDevTrait const tc = {                                     \
        .Receive = (VlcbNetDevErr(*const)(                                  \
            void *const, VlcbNetDevPacket *const))(receive_f),              \
        .Send = (VlcbNetDevErr(*const)(                                     \
            void *const, const VlcbNetDevPacket *const))(send_f),           \
        .Caps = (const VlcbNetDevCaps *(*const)(void *))(caps_f)};          \
    return (VlcbNetDev){.tc = &tc, .self = x};                              \
  }
