#pragma once

#ifndef VLCB_NOLOGGING

typedef enum {
  VLCB_LOG_INFO,
  VLCB_LOG_ERROR,
#ifdef DEBUG
  VLCB_LOG_DEBUG,
#endif  // DEBUG
} VlcbLogMessageType;

typedef struct {
  VlcbLogMessageType type;
  const char* const message;
} VlcbLogMessage;

void VlcbLogInfo(const char* const message);
void VlcbLogError(const char* const message);
#ifdef DEBUG
void VlcbLogDebug(const char* const message);
#endif  // DEBUG

typedef void VlcbLogMessageHandler(VlcbLogMessage msg);

void vlcb_log_RegisterMessageHandler(VlcbLogMessageHandler handler);

#define VLCBLOG_INFO(msg) VlcbLogInfo(msg);
#define VLCBLOG_ERROR(msg) VlcbLogError(msg);
#ifdef DEBUG
#define VLCBLOG_DEBUG(msg) VlcbLogDebug(msg);
#else
#define VLCBLOG_DEBUG(msg) ;
#endif  // DEBUG

#else

#define VLCBLOG_INFO(msg) ;
#define VLCBLOG_ERROR(msg) ;
#define VLCBLOG_DEBUG(msg) ;

#endif  // !VLCB_NOLOGGING
