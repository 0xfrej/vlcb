#pragma once

#include "vlcb/common/node.h"
#include "vlcb/common/vlcb_defs.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"
#include <stdint.h>

#define NS vlcb_net_pkt_dgram_module
#define S Dgram
#define P VlcbNetPacketDatagram

DEFINE_PACKET_WO_DATA(NS, S, P, RestartAllNodes, VLCB_OPC_RESTART_ALL_NODES)

DEFINE_PACKET_DATA(NS, S, P, Heartbeat, VlcbNodeNumber nodeNumber;
                   uint8_t sequence; uint8_t status; uint8_t statusBits;)

DEFINE_PACKET_DATA(NS, S, P, RestartNode, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, SetNodeNumber, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, ReleaseNodeNumber, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, QueryNodeInfo, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, RequestNodeNumber, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, NodeNumberAck, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_WO_DATA(NS, S, P, QueryNodeParams, VLCB_OPC_QUERY_NODE_PARAMS)

DEFINE_PACKET_DATA(NS, S, P, NodeParams, VlcbManufacturer manuId;
                   char minorVersion; uint8_t moduleType; uint8_t eventCount;
                   uint8_t eventVariableCount; uint8_t nodeVariableCount;
                   uint8_t majorVersion;)

#undef NS
#undef S
#undef P
