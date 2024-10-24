#pragma once

#include "vlcb/common/node.h"
#include "vlcb/module/param.h"
#include "vlcb/module/state.h"
#include "vlcb/module/ui.h"
#include "vlcb/net/iface.h"
#include "vlcb/net/socket/datagram.h"
#include "vlcb/platform/time.h"
#include <stdint.h>

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

/**
 * Module state for persistent storage
 *
 * Module can enter states that should not be persisted
 */
typedef uint8_t VlcbModulePersistedState;
enum VlcbPersistedModuleState {
  VLCB_MODULE_PERSISTED_STATE_UNINITIALIZED = 1,
  VLCB_MODULE_PERSISTED_STATE_NORMAL,
};

typedef uint8_t VlcbModuleOpFlags;
enum VlcbModuleOpFlags {
  VLCB_MODULE_FLAGS_HEARTBEAT = 0x01,
  VLCB_MODULE_FLAGS_EVENT_ACK = 0x02,
};

typedef struct {
  VlcbModuleOpFlags operationFlags;
  VlcbModulePersistedState state;
  VlcbNetHwAddr hwAddr;
  VlcbNodeNumber nodeAddr;
} VlcbModuleConfig;

typedef struct {
  clock_t lastHeartbeat;
  uint8_t heartbeatCount;
  VlcbNetIface *const iface;
  VlcbNetSocketDatagram *const socket;
  VlcbModuleUi ui;
  VlcbModuleConfig config;
  VlcbModuleParams params;
  // VlcbServiceMngr services;
  VlcbModuleStateMachine sm;
} VlcbModule;

VlcbModule vlcb_module_New(VlcbNetIface *const iface,
                           VlcbNetSocketDatagram *const socket,
                           const VlcbModuleUi ui,
                           const VlcbModuleParams params);

void vlcb_module_Init(VlcbModule *const module, const clock_t now);

int vlcb_module_BindSock(const VlcbModule *const module,
                         const VlcbNetSocket *const socket);

void vlcb_module_Poll(VlcbModule *const module, const clock_t now);
