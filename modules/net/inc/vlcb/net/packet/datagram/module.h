#pragma once

#include "vlcb/common/node.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"

DEFINE_PACKET_DATA(vlcb_net_pkt_dgram_module, Dgram, ReleaseNodeNumber,
                   VlcbPacketDatagram, VlcbNodeAddr addr;)

DEFINE_PACKET_DATA(vlcb_net_pkt_dgram_module, Dgram, QueryNodeInfo,
                   VlcbPacketDatagram, VlcbNodeAddr addr;)

DEFINE_PACKET_DATA(vlcb_net_pkt_dgram_module, Dgram, RequestNodeNumber,
                   VlcbPacketDatagram, VlcbNodeAddr addr;)

DEFINE_PACKET_DATA(vlcb_net_pkt_dgram_module, Dgram, NodeNumberAck,
                   VlcbPacketDatagram, VlcbNodeAddr addr;)
