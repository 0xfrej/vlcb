#include "vlcb/net/packet/datagram/module.h"

#include <assert.h>

#include "vlcb/common/vlcb_defs.h"
#include "vlcb/platform/endian.h"

#include <string.h>

inline VlcbNetDgramReleaseNodeNumber
vlcb_net_pkt_dgram_module_ReleaseNodeNumber_deserialize(
    const VlcbPacketDatagram *const packet) {
  VlcbNetDgramReleaseNodeNumber data;
  assert(packet != NULL && packet->opc == VLCB_OPC_NODE_NUMBER_RELEASED && packet->payload_len == sizeof(data.addr));
  memcpy(&data.addr, &packet->payload, sizeof(data.addr));
  data.addr = ntohs(data.addr);
  return data;
}