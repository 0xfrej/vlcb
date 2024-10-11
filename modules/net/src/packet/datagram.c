#include "vlcb/net/packet/datagram.h"

#include <assert.h>
#include <stdbool.h>

vlcb_error vlcb_net_pkt_dgram_ConstructErrToStr(VlcbPacketDatagramConstructErr err) {
  assert(err > VLCB_DGRAM_PKT_CONSTRUCT_ERR_OK && err < VLCB_DGRAM_PKT_CONSTRUCT_ERR_COUNT);

  switch (err) {
    case VLCB_DGRAM_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE:
      return "datagram payload too large";
    case VLCB_DGRAM_PKT_CONSTRUCT_ERR_INVALID_OPCODE:
      return "datagram invalid opcode";
  }
  assert(false /* unhandled case guard */);
}

VlcbPacketDatagramConstructErr vlcb_net_pkt_dgram_NewUnchecked(
    VlcbOpCode opc, uint8_t payload_len,
    const VlcbDatagramPayload* const payload,
    VlcbPacketDatagram* const packet) {
}

VlcbPacketDatagramConstructErr vlcb_net_pkt_dgram_New(
    VlcbOpCode opc, uint8_t payload_len,
    const VlcbDatagramPayload* const payload,
    VlcbPacketDatagram* const packet) {

}
