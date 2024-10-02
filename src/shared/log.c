#include "log.h"

#ifndef VLCB_NOLOGGING

#include <stddef.h>

static VlcbLogMessageHandler *_handler = NULL;

void LogMessage(const VlcbLogMessage message) {
  if (message.message != NULL && _handler != NULL) {
    _handler(message);
  }
}

void VlcbLogInfo(vlcb_error message) {
  LogMessage((VlcbLogMessage){.type = VLCB_LOG_INFO, .message = message});
}

void VlcbLogError(vlcb_error message) {
  LogMessage((VlcbLogMessage){.type = VLCB_LOG_ERROR, .message = message});
}

#ifdef DEBUG
void VlcbLogDebug(vlcb_error message) {
  LogMessage((VlcbLogMessage){.type = VLCB_LOG_DEBUG, .message = message});
}
#endif /* ifdef DEBUG */

void vlcb_log_RegisterMessageHandler(VlcbLogMessageHandler handler) {
  _handler = handler;
}

#endif  // !VLCB_NOLOGGING