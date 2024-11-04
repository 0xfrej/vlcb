
#pragma once

#include "vlcb/common/event.h"
#include "vlcb/common/node.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"
#include <stdint.h>

#define NS vlcb_net_pkt_dgram_event
#define S Dgram
#define P VlcbNetPacketDatagram

DEFINE_PACKET_DATA(NS, S, P, PutNodeIntoLearnMode, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ReleaseNodeFromLearnMode,
                   VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ForgetAllLearnedEvents, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, QueryAvailableEventSlots,
                   VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, QueryAllLearnedEvents, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, QueryLearnedEventCount, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, AvailableEventSlots, VlcbNodeNumber nodeNumber;
                   uint8_t availableSlots;)
DEFINE_PACKET_DATA(NS, S, P, QueryLearnedEventByIndex,
                   VlcbNodeNumber nodeNumber;
                   uint8_t index;)
DEFINE_PACKET_DATA(NS, S, P, LearnedEventCount, VlcbNodeNumber nodeNumber;
                   uint8_t eventCount;)

DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryOn0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryOff0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, QueryLongEventAccessoryState, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryStateOn0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryStateOff0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, ForgetLearnedEvent, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, ShortEventAccessoryOn0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, ShortEventAccessoryOff0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, QueryShortEventAccessoryState, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, QueryEventVariable, VlcbNodeNumber nodeNumber;
                   uint8_t eventIndex; uint8_t eventVariableIndex;)
DEFINE_PACKET_DATA(NS, S, P, ShortEventAccessoryStateOn0, VlcbEvent event;)
DEFINE_PACKET_DATA(NS, S, P, ShortEventAccessoryStateOff0, VlcbEvent event;)

DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryOn1, VlcbEvent event;
                   uint8_t payload[1];)
DEFINE_PACKET_DATA(NS, S, P, LongEventAccessoryOff1, VlcbEvent event;
                   uint8_t payload[1];)
DEFINE_PACKET_DATA(
    NS, S, P,
    QueryEventVariableByIndex, ) // finished on REQEV, can't find out if i made
                                 // a mistake with QueryEventVariable above
#undef NS
#undef S
#undef P
