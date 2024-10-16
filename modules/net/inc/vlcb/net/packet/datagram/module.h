#pragma once

#include "vlcb/net/packet/serialization.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/common/node.h"

DEFINE_PACKET_DATA(
  vlcb_net_pkt_dgram_module,
  Dgram,
  ReleaseNodeNumber,
  VlcbPacketDatagram,
  VlcbNodeAddr addr;
)

DEFINE_PACKET_DATA(
  vlcb_net_pkt_dgram_module,
  Dgram,
  QueryNodeInfo,
  VlcbPacketDatagram,
  VlcbNodeAddr addr;
)