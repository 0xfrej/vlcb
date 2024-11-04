#pragma once

#include "vlcb/common/dcc.h"
#include "vlcb/net/packet/datagram.h"
#include "vlcb/net/packet/serialization.h"
#include <stdbool.h>
#include <stdint.h>

#define NS vlcb_net_pkt_dgram_dcc
#define S Dgram
#define P VlcbNetPacketDatagram

DEFINE_PACKET_WO_DATA(NS, S, P, TrackPoweredOff)
DEFINE_PACKET_WO_DATA(NS, S, P, TrackPoweredOn)
DEFINE_PACKET_WO_DATA(NS, S, P, EmergencyStopEngaged)
DEFINE_PACKET_WO_DATA(NS, S, P, TrackPowerOffRequest)
DEFINE_PACKET_WO_DATA(NS, S, P, TrackPowerOnRequest)
DEFINE_PACKET_WO_DATA(NS, S, P, EmergencyStopRequest)
DEFINE_PACKET_WO_DATA(NS, S, P, QueryCommandStationStatus)

DEFINE_PACKET_DATA(NS, S, P, ReleaseSession, VlcbDccSessionNr session;)
DEFINE_PACKET_DATA(NS, S, P, QueryLocoStatus, VlcbDccSessionNr session;)
DEFINE_PACKET_DATA(NS, S, P, SessionKeepAlive, VlcbDccSessionNr session;)

DEFINE_PACKET_DATA(NS, S, P, RequestSession, VlcbDccDecoderAddr decoderAddr;)
DEFINE_PACKET_DATA(NS, S, P, QueryConsist, VlcbDccConsistId consistId;
                   uint8_t index;)
DEFINE_PACKET_DATA(NS, S, P, AllocateLocotoActivity, VlcbDccSessionNr session;
                   uint8_t allocationCode;)
DEFINE_PACKET_DATA(NS, S, P, SetTrottleMode, VlcbDccSessionNr session;
                   VlcbDccThrottleSpeedMode speedMode; bool serviceMode;
                   bool soundCtrlMode;)
DEFINE_PACKET_DATA(NS, S, P, ConsistAddLoco, VlcbDccSessionNr session;
                   VlcbDccConsistId consistId;)
DEFINE_PACKET_DATA(NS, S, P, ConsistRemoveLoco, VlcbDccSessionNr session;
                   VlcbDccConsistId consistId;)
DEFINE_PACKET_DATA(NS, S, P, SetLocoThrottle, VlcbDccSessionNr session;
                   uint8_t speed; bool isReversed;)
DEFINE_PACKET_DATA(NS, S, P, SetLocoFlags, VlcbDccSessionNr session;
                   VlcbDccThrottleSpeedMode speedMode; bool lightsOn;
                   bool relativeDirection; VlcbDccLocoState state;)
DEFINE_PACKET_DATA(NS, S, P, LocoFunctionOn, VlcbDccSessionNr session;
                   uint8_t functionNr;)
DEFINE_PACKET_DATA(NS, S, P, LocoFunctionOff, VlcbDccSessionNr session;
                   uint8_t functionNr;)
DEFINE_PACKET_DATA(NS, S, P, ServiceModeStatus, VlcbDccSessionNr session;
                   uint8_t status;)

DEFINE_PACKET_DATA(NS, S, P, SetLocoFunctions, VlcbDccSessionNr session;
                   VlcbDccLocoFunctionRange range; uint8_t statusBits;)
DEFINE_PACKET_DATA(NS, S, P, QueryLocoSession, VlcbDccDecoderAddr decoderAddr;
                   VlcbDccSessionQueryMode state;)
DEFINE_PACKET_DATA(NS, S, P, err_LocoStackIsFull,
                   VlcbDccDecoderAddr decoderAddr;)
DEFINE_PACKET_DATA(NS, S, P, err_LocoAddrIsTaken,
                   VlcbDccDecoderAddr decoderAddr;)
DEFINE_PACKET_DATA(NS, S, P, err_SessionNotFound, VlcbDccSessionNr session;)
DEFINE_PACKET_DATA(NS, S, P, err_ConsistIsEmpty, VlcbDccSessionNr session;)
DEFINE_PACKET_DATA(NS, S, P, err_LocoNotFound, VlcbDccSessionNr session;)

DEFINE_PACKET_DATA(NS, S, P, SendRawPacket3, uint8_t repeat;
                   uint8_t payload[3];)
DEFINE_PACKET_DATA(NS, S, P, WriteCvInOpsMode, VlcbDccSessionNr session;
                   uint16_t cv; uint8_t value;)
DEFINE_PACKET_DATA(NS, S, P, WriteCvBitInOpsMode, VlcbDccSessionNr session;
                   uint16_t cv; uint8_t bitPosition; bool value;)
DEFINE_PACKET_DATA(NS, S, P, ReadCv, VlcbDccSessionNr session; uint16_t cv;
                   uint8_t mode;)
DEFINE_PACKET_DATA(NS, S, P, CvValue, VlcbDccSessionNr session; uint16_t cv;
                   uint8_t value;)

DEFINE_PACKET_DATA(NS, S, P, SendRawPacket4, uint8_t repeat;
                   uint8_t payload[4];)
DEFINE_PACKET_DATA(NS, S, P, WriteCvInServiceMode, VlcbDccSessionNr session;
                   uint16_t cv; uint8_t mode; uint8_t value;)

#undef NS
#undef S
#undef P
