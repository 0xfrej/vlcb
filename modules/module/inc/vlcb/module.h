#pragma once

#include "vlcb/module/param.h"
#include "vlcb/net/iface.h"
#include "vlcb/platform/time.h"
#include "vlcb/common/node.h"
#include "vlcb/net/socket/datagram.h"

// typedef struct {
// } VlcbServiceTrait;

// typedef struct {
//   void *const self;
//   const VlcbServiceTrait *const tc;
// } VlcbService;

// typedef VlcbService *VlcbServiceHandle;
//
// typedef struct {
//   VlcbServiceHandle can;
//   VlcbServiceHandle event_producer;
//   VlcbServiceHandle event_consumer;
//   VlcbServiceHandle event_loopback;
//   VlcbServiceHandle event_ack;
//   VlcbServiceHandle event_teach;
//   VlcbServiceHandle nv;
// } VlcbServiceMngr;

typedef enum {
  VLCB_MODULE_FLAGS_HEARTBEAT = 0x01,
  VLCB_MODULE_FLAGS_EVENT_ACK = 0x02,
} VlcbModuleOpFlags;

typedef enum {
  VLCB_MODULE_STATE_UNINITIALIZED = 0,
  VLCB_MODULE_STATE_ENTERING_SETUP,
  VLCB_MODULE_STATE_SETUP,
  VLCB_MODULE_STATE_ENTERING_NORMAL,
  VLCB_MODULE_STATE_NORMAL,
  VLCB_MODULE_STATE_ENTERING_UNINITIALIZED,
} VlcbModuleState;

typedef struct {
  VlcbModuleState currentState;
} VlcbModuleStateMachine;

typedef struct {
  VlcbModuleOpFlags operationFlags;
  VlcbModuleState state;
  VlcbNetHwAddr hwAddr;
  VlcbNodeAddr nodeAddr;
} VlcbModuleConfig;

#include "vlcb/module/ui.h"

typedef struct {
  VlcbNetIface *const iface;
  VlcbNetSocketDatagram *const socket;
  VlcbModuleUi ui;
  VlcbModuleConfig config;
  VlcbModuleParams params;
  VlcbModuleStateMachine state;
  bool canCommunicate;
  // VlcbServiceMngr services;
} VlcbModule;

VlcbModule vlcb_module_New(
  VlcbNetIface *const iface,
  VlcbNetSocketDatagram *const socket,
  const VlcbModuleUi ui,
  const VlcbModuleParams params
);

void vlcb_module_Init(
  VlcbModule *const module,
  const clock_t now
);

int vlcb_module_BindSock(
  const VlcbModule *const module,
  const VlcbNetSocket *const socket
);

void vlcb_module_Poll(
  VlcbModule *const module,
  const clock_t now
);