#include "vlcb/net/packet/datagram.h"

#include <assert.h>
#include <stdbool.h>

vlcb_error
vlcb_net_pkt_dgram_ConstructErrToStr(VlcbNetPacketDatagramConstructErr err) {
  assert(err > VLCB_DGRAM_PKT_CONSTRUCT_ERR_OK &&
         err < VLCB_DGRAM_PKT_CONSTRUCT_ERR_COUNT);

  switch (err) {
  case VLCB_DGRAM_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE:
    return "datagram payload too large";
  case VLCB_DGRAM_PKT_CONSTRUCT_ERR_INVALID_OPCODE:
    return "datagram invalid opcode";
  }
  assert(false /* unhandled case guard */);
}

VlcbNetPacketDatagramConstructErr
vlcb_net_pkt_dgram_NewUnchecked(VlcbOpCode opc, uint8_t payload_len,
                                const VlcbNetMsggramPayload *const payload,
                                VlcbNetPacketDatagram *const packet) {
  // TODO: implement
}

VlcbNetPacketDatagramConstructErr
vlcb_net_pkt_dgram_New(VlcbOpCode opc, uint8_t payload_len,
                       const VlcbNetMsggramPayload *const payload,
                       VlcbNetPacketDatagram *const packet) {
  // TODO: implement
}
