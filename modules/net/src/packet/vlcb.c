#include "vlcb/net/packet/vlcb.h"

#include <assert.h>
#include <stdbool.h>

VlcbNetProtocol vlcb_net_pkt_DetectProtocol(VlcbOpCode opc) {
  switch (opc) {
  case VLCB_OPC_STREAM_PACKET:
    return VLCB_NET_PROTO_STREAM;
  default:
    return VLCB_NET_PROTO_DATAGRAM;
  }
}

vlcb_error vlcb_net_pkt_ConstructErrToStr(VlcbNetPacketConstructErr err) {
  assert(err > VLCB_NET_PKT_CONSTRUCT_ERR_OK &&
         err < VLCB_NET_PKT_CONSTRUCT_ERR_COUNT);

  switch (err) {
  case VLCB_NET_PKT_CONSTRUCT_ERR_PAYLOAD_TOO_LARGE:
    return "vlcb payload too large";
  case VLCB_NET_PKT_CONSTRUCT_ERR_INVALID_OPCODE:
    return "vlcb invalid opcode";
  }
  assert(false /* unhandled case guard */);
}

void vlcb_net_pkt_NewUnchecked(VlcbNetProtocol proto, VlcbOpCode opc,
                               uint8_t payload_len,
                               const VlcbNetPayload *const payload,
                               VlcbNetPacket *const packet) {
  // TODO: implement
}

VlcbNetPacketConstructErr vlcb_net_pkt_New(VlcbOpCode opc, uint8_t payload_len,
                                           const VlcbNetPayload *const payload,
                                           VlcbNetPacket *const packet) {
  // TODO: implement
  return VLCB_NET_PKT_CONSTRUCT_ERR_OK;
}
