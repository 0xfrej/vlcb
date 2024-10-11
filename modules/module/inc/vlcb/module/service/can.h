#pragma once

//#include "../config.h"

// TODO: include mention to docs -> this uses the force enumeration and random delay strategy
// this lib atm does not support strategy "before first transmission"

typedef struct {
//  VlcbModuleConfig *const config;
} VlcbModuleServiceCan;

VlcbModuleServiceCan vlcb_module_svc_New();
