#pragma once

#include <inttypes.h>

#include "../../vlcb_defs.h"

#define VLCB_PACKET_MAX_PAYLOAD 7

/**
 * VLCB payload buffer
 *
 * The type is supposed to function as a helper, so that
 * clients don't have to write the whole expression and
 * ensure it's correct.
 */
typedef uint8_t VlcbPacketPayload[VLCB_PACKET_MAX_PAYLOAD];

/**
 * VLCB sub-protocol
 *
 * VLCB doesn't define any "sub-protocol", but this library
 * uses this as a helper for separating traffic for easier
 * handling.
 */
typedef enum {
  VLCB_PROTO_DATAGRAM,
  VLCB_PROTO_STREAM,
} VlcbProtocol;

VlcbProtocol vlcb_pkt_DetectProtocol(VlcbOpCode opc);

/**
 * VLCB node address (11 bit wide)
 */
typedef uint16_t VlcbNodeAddr;

typedef struct {
  VlcbProtocol proto;
  VlcbOpCode opc;
  uint8_t payload_len;
  VlcbPacketPayload payload;
} VlcbPacket;

typedef enum {
  VLCB_PKT_CONSTRUCT_ERR_OK = 0,

  /**
   * Given payload was too large
   *
   * VLCB packets have max payload size of 7 bytes.
   */
  VLCB_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE,

  /**
   * Opcode has invalid value
   */
  VLCB_PKT_CONSTRUCT_ERR_INVALID_OPCODE,

  /**
   * Not an actual error. Can be used to check if the given error value
   * is within the enum range.
   */
  VLCB_PKT_CONSTRUCT_ERR_COUNT,
} VlcbPacketConstructErr;

const char* vlcb_pkt_VlcbPacketConstructErrToStr(VlcbPacketConstructErr err);

VlcbPacketConstructErr vlcb_pkt_NewPacketUnchecked(
    VlcbProtocol proto, VlcbOpCode opc, uint8_t payload_len,
    const VlcbPacketPayload* const payload, VlcbPacket* const packet);
VlcbPacketConstructErr vlcb_pkt_NewPacket(
    VlcbOpCode opc, uint8_t payload_len, const VlcbPacketPayload* const payload,
    VlcbPacket* const packet);
