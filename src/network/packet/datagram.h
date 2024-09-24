#pragma once

#include <inttypes.h>

#include "../../vlcb_defs.h"

#define VLCB_PACKET_MAX_PAYLOAD 7

/**
 * Datagram payload buffer
 *
 * The type is supposed to function as a helper, so that
 * clients don't have to write the whole expression and
 * ensure it's correct.
 */
typedef uint8_t VlcbDatagramPacketPayload[VLCB_PACKET_MAX_PAYLOAD];

typedef struct {
  VlcbOpCode opc;
  uint8_t payload_len;
  VlcbDatagramPacketPayload payload;
} VlcbDatagramPacket;

typedef enum {
  VLCB_DGRAM_PKT_CONSTRUCT_ERR_OK = 0,

  /**
   * Given payload was too large
   *
   * VLCB packets have max payload size of 7 bytes.
   */
  VLCB_DGRAM_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE,

  /**
   * Opcode has invalid value
   */
  VLCB_DGRAM_PKT_CONSTRUCT_ERR_INVALID_OPCODE,

  /**
   * Not an actual error. Can be used to check if the given error value
   * is within the enum range.
   */
  VLCB_DGRAM_PKT_CONSTRUCT_ERR_COUNT,
} VlcbDatagramPacketConstructErr;

const char* vlcb_pkt_VlcbDatagramPacketConstructErrToStr(
    VlcbDatagramPacketConstructErr err);

VlcbDatagramPacketConstructErr vlcb_pkt_NewDatagramPacketUnchecked(
    VlcbOpCode opc, uint8_t payload_len,
    const VlcbDatagramPacketPayload* const payload,
    VlcbDatagramPacket* const packet);
VlcbDatagramPacketConstructErr vlcb_pkt_NewDatagramPacket(
    VlcbOpCode opc, uint8_t payload_len,
    const VlcbDatagramPacketPayload* const payload,
    VlcbDatagramPacket* const packet);
