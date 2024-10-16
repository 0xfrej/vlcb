#pragma once

#include <stddef.h>

// #define _INTERFACE_TRAIT_TYPEDEF_START(iT) typedef struct iT {
// #define _INTERFACE_TRAIT_METHOD(retT, name, ...) retT (*const name)(__VA_ARGS__);
// #define _INTERFACE_TRAIT_TYPEDEF_END(T) } T;
//
// #define _INTERFACE_TYPEDEF(T, trait) \
// typedef struct { \
//   void *const self; \
//   const trait *const tc; \
// } T;

#define _INTERFACE_DECLARE(T, ...) \
  typedef struct T##Trait { \
    __VA_ARGS__ \
  } T##Trait; \
  typedef struct { \
    void *const self; \
    const T##Trait *const tc; \
  } T;
#define _INTERFACE_METHOD_DECLARE(retT, name, ...) retT (*const name)(__VA_ARGS__);

#define _INTERFACE_SELF_PTR const void *const self
#define _INTERFACE_SELF_PTR_MUT void *const self

#define _INTERFACE_NULL(T) (T){.self=NULL, .tc=NULL}
#define _INTERFACE_NEW(T, selfPtr, traitPtr) (T){.self=selfPtr, .tc=traitPtr}
#define _INTERFACE_IS_VALID(i) i.self != NULL && i.tc != NULL
#define _INTERFACE_PTR_IS_VALID(i) i != NULL && i->self != NULL && i->tc != NULL

#define _TYPE_UPCAST_METHOD_PTR_SIG(fPtr, retT, ...) \
  retT (*const fPtr##_)(__VA_ARGS__) = (fPtr);       \
  (void)fPtr##_;

#define _TYPE_UPCAST_VTABLE_METHOD_ENTRY(field, fPtr, retT, ...) \
  .field = (retT(*const)(__VA_ARGS__))(fPtr)

#define _TYPE_UPCAST_VTABLE_DEF(name, T, ...) \
  static T const name = {__VA_ARGS__};

#define _INTERFACE_PTR_STATIC_CALL(o, m, ...) o->tc->m(__VA_ARGS__)
#define _INTERFACE_STATIC_CALL(o, m, ...) o.tc->m(__VA_ARGS__)
#define _INTERFACE_PTR_CALL(o, m, ...) o->tc->m(o->self, ##__VA_ARGS__)
#define _INTERFACE_CALL(o, m, ...) o.tc->m(o.self, ##__VA_ARGS__)