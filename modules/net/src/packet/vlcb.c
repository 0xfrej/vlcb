#include "vlcb/net/packet/vlcb.h"

#include <assert.h>
#include <stdbool.h>

VlcbProtocol vlcb_net_pkt_DetectProtocol(VlcbOpCode opc) {
  switch (opc) {
    case VLCB_OPC_STREAM_PACKET:
      return VLCB_PROTO_STREAM;
    default:
      return VLCB_PROTO_DATAGRAM;
  }
}

vlcb_error vlcb_net_pkt_ConstructErrToStr(VlcbPacketConstructErr err) {
  assert(err > VLCB_PKT_CONSTRUCT_ERR_OK && err < VLCB_PKT_CONSTRUCT_ERR_COUNT);

  switch (err) {
    case VLCB_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE:
      return "vlcb payload too large";
    case VLCB_PKT_CONSTRUCT_ERR_INVALID_OPCODE:
      return "vlcb invalid opcode";
  }
  assert(false /* unhandled case guard */);
  }

void vlcb_net_pkt_NewUnchecked(
    VlcbProtocol proto, VlcbOpCode opc, uint8_t payload_len,
    const VlcbPayload* const payload, VlcbPacket* const packet) {
    //TODO: implement
  }

VlcbPacketConstructErr vlcb_net_pkt_New(
    VlcbOpCode opc, uint8_t payload_len, const VlcbPayload* const payload,
    VlcbPacket* const packet) {
  //TODO: implement
  return VLCB_PKT_CONSTRUCT_ERR_OK;
  }
