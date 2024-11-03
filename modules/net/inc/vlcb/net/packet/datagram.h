#pragma once

#include <inttypes.h>

#include "vlcb/common/vlcb_defs.h"
#include "vlcb/platform/error.h"

#define VLCB_DGRAM_PKT_MAX_PAYLOAD 7

/**
 * Datagram payload buffer
 *
 * The type is supposed to function as a helper, so that
 * clients don't have to write the whole expression and
 * ensure it's correct.
 */
typedef uint8_t VlcbNetDatagramPayload[VLCB_DGRAM_PKT_MAX_PAYLOAD];

typedef struct {
  VlcbOpCode opc;
  uint8_t payload_len;
  VlcbNetDatagramPayload payload;
} VlcbNetPacketDatagram;

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
} VlcbNetPacketDatagramConstructErr;

vlcb_error
vlcb_net_pkt_dgram_ConstructErrToStr(VlcbNetPacketDatagramConstructErr err);

VlcbNetPacketDatagramConstructErr
vlcb_net_pkt_dgram_NewUnchecked(VlcbOpCode opc, uint8_t payload_len,
                                const VlcbNetDatagramPayload *const payload,
                                VlcbNetPacketDatagram *const packet);
VlcbNetPacketDatagramConstructErr
vlcb_net_pkt_dgram_New(VlcbOpCode opc, uint8_t payload_len,
                       const VlcbNetDatagramPayload *const payload,
                       VlcbNetPacketDatagram *const packet);
