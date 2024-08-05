#pragma once

#include <inttypes.h>
#include <stdbool.h>

#define VLCB_NET_DEV_CAN_MTU 8

typedef uint16_t CanId;
#define CAN_ID_FROM_BYTES(hi, lo) ((((CanId)(hi) << 8) | (CanId)(lo)) & 0x7ff)

typedef struct {
  bool is_rtr;
} VlcbNetDevPacketCanMeta;
