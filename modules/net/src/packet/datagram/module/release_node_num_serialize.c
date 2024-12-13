#include "vlcb/net/packet/datagram/module.h"

#include <assert.h>
#include <memory.h>
#include <stddef.h>

#include "vlcb/platform/endian.h"

inline void vlcb_net_pkt_dgram_module_ReleaseNodeNumber_serialize(
    VlcbNetPacketDatagram *const packet, VlcbNetDgramReleaseNodeNumber data) {
  assert(packet != NULL);
  data.nodeNumber = vlcb_htons(data.nodeNumber);
  packet->opc = VLCB_OPC_NODE_NUMBER_RELEASED;
  packet->payloadLen = sizeof(data.nodeNumber);
  memcpy(&packet->payload, &data.nodeNumber, sizeof(data.nodeNumber));
}
