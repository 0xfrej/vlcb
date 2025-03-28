#pragma once

#include <inttypes.h>

#include "vlcb/common/opcode.h"
#include "vlcb/platform/error.h"

#define VLCB_NET_PKT_MAX_PAYLOAD 7

/**
 * VLCB payload buffer
 *
 * The type is supposed to function as a helper, so that
 * clients don't have to write the whole expression and
 * ensure it's correct.
 */
typedef uint8_t VlcbNetPayload[VLCB_NET_PKT_MAX_PAYLOAD];

typedef struct {
  VlcbOpCode opc;
  uint8_t payloadLen;
  VlcbNetPayload payload;
} VlcbNetPacket;

typedef enum {
  VLCB_NET_PKT_CONSTRUCT_ERR_OK = 0,

  /**
   * Given payload was too large
   *
   * VLCB packets have max payload size of 7 bytes.
   */
  VLCB_NET_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE,

  /**
   * Opcode has invalid value
   */
  VLCB_NET_PKT_CONSTRUCT_ERR_INVALID_OPCODE,

  /**
   * Not an actual error. Can be used to check if the given error value
   * is within the enum range.
   */
  VLCB_NET_PKT_CONSTRUCT_ERR_COUNT,
} VlcbNetPacketConstructErr;

vlcb_error vlcb_net_pkt_ConstructErrToStr(VlcbNetPacketConstructErr err);

void vlcb_net_pkt_NewUnchecked(VlcbOpCode opc, uint8_t payload_len,
                               const VlcbNetPayload *const payload,
                               VlcbNetPacket *const packet);
VlcbNetPacketConstructErr vlcb_net_pkt_New(VlcbOpCode opc, uint8_t payload_len,
                                           const VlcbNetPayload *const payload,
                                           VlcbNetPacket *const packet);
