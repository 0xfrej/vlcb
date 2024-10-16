#include "vlcb/net/packet/datagram/module.h"

#include <memory.h>
#include <assert.h>
#include <stddef.h>

#include "vlcb/platform/endian.h"


inline void vlcb_net_pkt_dgram_module_ReleaseNodeNumber_serialize(
  VlcbPacketDatagram *const packet,
  VlcbNetDgramReleaseNodeNumber data
) {
  assert(packet != NULL);
  data.addr = htons(data.addr);
  packet->opc = VLCB_OPC_NODE_NUMBER_RELEASED;
  packet->payload_len = sizeof(data.addr);
  memcpy(&packet->payload, &data.addr, sizeof(data.addr));
}