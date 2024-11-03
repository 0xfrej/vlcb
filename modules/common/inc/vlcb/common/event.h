#pragma once

#include "vlcb/common/node.h"
#include <stdint.h>

typedef uint16_t VlcbEventId;
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbEventId eventId;
} VlcbEvent;

typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbEventId eventId;
} VlcbShortEvent;
