#include "log.h"

#ifndef VLCB_NOLOGGING

#include <stddef.h>

static VlcbLogMessageHandler *logHandler = NULL;

void LogMessage(const VlcbLogMessage message) {
  if (message.message != NULL && logHandler != NULL) {
    logHandler(message);
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
  logHandler = handler;
}

#endif  // !VLCB_NOLOGGING
