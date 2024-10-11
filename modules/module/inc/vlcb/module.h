#pragma once

#include "vlcb/net/iface.h"
#include "vlcb/module/state.h"

typedef struct {
} VlcbServiceTrait;

typedef struct {
  void *const self;
  const VlcbServiceTrait *const tc;
} VlcbService;

typedef VlcbService *VlcbServiceHandle;

typedef struct {
  VlcbServiceHandle can;
  VlcbServiceHandle event_producer;
  VlcbServiceHandle event_consumer;
  VlcbServiceHandle event_loopback;
  VlcbServiceHandle event_ack;
  VlcbServiceHandle event_teach;
  VlcbServiceHandle nv;
} VlcbServiceMngr;

typedef struct {
  VlcbNetIface *const iface;
  VlcbModuleState state;
  VlcbServiceMngr services;
} VlcbModule;

VlcbModule vlcb_module_New(VlcbNetIface *const iface);
