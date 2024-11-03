#pragma once

#include <stddef.h>

#define _INTERFACE_DECLARE(T, ...)                                             \
  typedef struct T {                                                           \
    __VA_ARGS__                                                                \
  } T

#define _INTERFACE_METHOD_DECLARE(retT, name, ...)                             \
  retT (*const name)(__VA_ARGS__)

#define _INTERFACE_SELF(T) const struct T self
#define _INTERFACE_SELF_MUT(T) struct T
#define _INTERFACE_SELF_PTR(T) const struct T *const self
#define _INTERFACE_SELF_PTR_MUT(T) struct T *const self

#define _INTERFACE_IMPLEMENT(T) T _iface

#define _INTERFACE_VTABLE_DEFINE(T, ...) static T iface##T = {__VA_ARGS__}
#define _INTERFACE_VTABLE_METHOD(m, ptr, retT, ...)                            \
  .m = (retT(*const)(__VA_ARGS__))(ptr)

#define _INTERFACE_ASSIGN_VTABLE(T) ._iface = iface##T

#define _INTERFACE_PTR_STATIC_CALL(o, m, ...) o->m(__VA_ARGS__)
#define _INTERFACE_STATIC_CALL(o, m, ...) o.m(__VA_ARGS__)
#define _INTERFACE_PTR_CALL(o, m, ...) o->m(o, ##__VA_ARGS__)
#define _INTERFACE_CALL(o, m, ...) o.m(&o, ##__VA_ARGS__)
