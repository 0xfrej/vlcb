#pragma once

#include "vlcb/module.h"

typedef enum {
  MSE_MODE_CHANGE_TO_SETUP,
  MSE_MODE_CHANGE_TO_NORMAL,

} ModuleStateEvent;

void ModuleStatePoll(
  VlcbModule *const module,
  VlcbPacketDatagram *const packet
);

void ModuleStateEvent() {

}