#pragma once

#include "vlcb/common/module.h"
#include "vlcb/common/node.h"
#include "vlcb/common/vlcb_defs.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"
#include <stdint.h>

#define NS vlcb_net_pkt_dgram_module
#define S Dgram
#define P VlcbNetPacketDatagram

DEFINE_PACKET_WO_DATA(NS, S, P, QueryModuleInfo)
DEFINE_PACKET_WO_DATA(NS, S, P, QueryNodeParams)
DEFINE_PACKET_WO_DATA(NS, S, P, QueryModuleName)

DEFINE_PACKET_DATA(NS, S, P, SetNodeNumber, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ResetModuleToFactory, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, RequestNodeNumber, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, ReleaseNodeNumber, VlcbNodeNumber nodeNumber;)
DEFINE_PACKET_DATA(NS, S, P, NodeNumberAck, VlcbNodeNumber nodeNumber;)

DEFINE_PACKET_DATA(NS, S, P, QueryNodeVariable, VlcbNodeNumber nodeNumber;
                   uint8_t index;)
DEFINE_PACKET_DATA(NS, S, P, QueryNodeParamByIndex, VlcbNodeNumber nodeNumber;
                   uint8_t index;)
DEFINE_PACKET_DATA(NS, S, P, ChangeModuleMode, VlcbNodeNumber nodeNumber;
                   VlcbModuleMode mode;)
DEFINE_PACKET_DATA(NS, S, P, QueryServiceDiscovery, VlcbNodeNumber nodeNumber;
                   uint8_t index;)

DEFINE_PACKET_DATA(NS, S, P, QueryDiagnosticData, VlcbNodeNumber nodeNumber;
                   uint8_t serviceIndex; uint8_t diagnosticCode;)
DEFINE_PACKET_DATA(NS, S, P, SetNodeVariable, VlcbNodeNumber nodeNumber;
                   uint8_t index; uint8_t value;)
DEFINE_PACKET_DATA(NS, S, P, LegacySetNodeVariable, VlcbNodeNumber nodeNumber;
                   uint8_t index; uint8_t value;)
DEFINE_PACKET_DATA(NS, S, P, NodeVariableValue, VlcbNodeNumber nodeNumber;
                   uint8_t index; uint8_t value;)
DEFINE_PACKET_DATA(NS, S, P, NodeParameterValue, VlcbNodeNumber nodeNumber;
                   uint8_t index; uint8_t value;)

DEFINE_PACKET_DATA(NS, S, P, Heartbeat, VlcbNodeNumber nodeNumber;
                   uint8_t sequence; uint8_t status;)
DEFINE_PACKET_DATA(NS, S, P, ServiceDiscoveryResponse,
                   VlcbNodeNumber nodeNumber;
                   uint8_t serviceIndex; VlcbServiceType serviceType;
                   VlcbServiceVersion version;)
DEFINE_PACKET_DATA(NS, S, P, GenericResponse, VlcbNodeNumber nodeNumber;
                   VlcbOpCode requestOpcode; VlcbServiceType serviceType;
                   uint8_t result;)
//
DEFINE_PACKET_DATA(NS, S, P, NodeParams, VlcbManufacturer manuId;
                   char minorVersion; uint8_t moduleType; uint8_t eventCount;
                   uint8_t eventVariableCount; uint8_t nodeVariableCount;
                   uint8_t majorVersion;)

#undef NS
#undef S
#undef P
