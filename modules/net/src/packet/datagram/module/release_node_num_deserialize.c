#include "vlcb/net/packet/datagram/module.h"

#include <assert.h>

#include "vlcb/platform/endian.h"
#include <string.h>

inline VlcbNetDgramReleaseNodeNumber
vlcb_net_pkt_dgram_module_ReleaseNodeNumber_deserialize(
    const VlcbNetPacketDatagram *const packet) {
  VlcbNetDgramReleaseNodeNumber data;
  assert(packet != NULL && packet->opc == VLCB_OPC_NODE_NUMBER_RELEASED &&
         packet->payloadLen == sizeof(data.nodeNumber));
  memcpy(&data.nodeNumber, &packet->payload, sizeof(data.nodeNumber));
  data.nodeNumber = vlcb_ntohs(data.nodeNumber);
  return data;
}
