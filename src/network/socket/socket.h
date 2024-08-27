#pragma once

#include <stdint.h>

#include "../packet/vlcb.h"

typedef enum {

} VlcbNetSocketErr;

typedef struct {
  VlcbNetSocketErr (*_process_packet)(const VlcbPacket *const);
  VlcbNetSocketErr (*_dispatch_packet)();
} VlcbNetSocket;

typedef struct {
  uint8_t len;
  VlcbNetSocket *list;
} VlcbNetSocketList;
