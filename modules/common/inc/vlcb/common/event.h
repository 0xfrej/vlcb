#pragma once

#include "vlcb/common/node.h"
#include <stdint.h>

/**
 * @brief VLCB event ID (2 octets)
 *
 * This is not the full event signature (4 bytes), just the event "code".
 * For representing the whole signature see @ref VlcbEvent
 */
typedef uint16_t VlcbEventId;

/**
 * @brief VLCB event signature
 *
 * This is the full event signature, containing both the
 * node number and the even "code"
 */
typedef struct {
  VlcbNodeNumber nodeNumber;
  VlcbEventId eventId;
} VlcbEvent;
