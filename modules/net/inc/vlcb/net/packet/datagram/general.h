#pragma once

#include "vlcb/common/can.h"
#include "vlcb/common/node.h"
#include "vlcb/common/vlcb_defs.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"
#include <stdint.h>

#define NS vlcb_net_pkt_dgram_general
#define S Dgram
#define P VlcbNetPacketDatagram

DEFINE_PACKET_WO_DATA(NS, S, P, GeneralAck)
DEFINE_PACKET_WO_DATA(NS, S, P, GeneralNack)
DEFINE_PACKET_WO_DATA(NS, S, P, BusHalt)
DEFINE_PACKET_WO_DATA(NS, S, P, BusResume)
DEFINE_PACKET_WO_DATA(NS, S, P, RestartAllNodes)

DEFINE_PACKET_DATA(NS, S, P, DebugMsg1, uint8_t byte;)
DEFINE_PACKET_DATA(NS, S, P, ExtOpc0, uint8_t extOpc;)

DEFINE_PACKET_DATA(NS, S, P, WriteAck, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, QueryNodeData, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, QueryNodeDataShort, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, RebootIntoBootloader, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ForceCanEnumeration, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, RestartNode, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ExtOpc1, uint8_t extOpc; uint8_t payload[1];)

DEFINE_PACKET_DATA(NS, S, P, CommandError, VlcbNodeNumber nodeNumber;
                   VlcbCommandError error;)
DEFINE_PACKET_DATA(NS, S, P, SetCanId, VlcbNodeNumber nodeNumber; VlcbCanId id;)
DEFINE_PACKET_DATA(NS, S, P, ExtOpc2, uint8_t extOpc; uint8_t payload[2];)

DEFINE_PACKET_DATA(NS, S, P, ExtOpc3, uint8_t extOpc; uint8_t payload[3];)
#undef NS
#undef S
#undef P
