#pragma once

#define _TYPE_UPCAST_METHOD_PTR_SIG(fPtr, retT, ...) \
  retT (*const fPtr##_)(__VA_ARGS__) = (fPtr);       \
  (void)fPtr##_;

#define _TYPE_UPCAST_VTABLE_METHOD_ENTRY(field, fPtr, retT, ...) \
  .field = (retT(*const)(__VA_ARGS__))(fPtr)

#define _TYPE_UPCAST_VTABLE_DEF(name, T, ...) \
  static T const name = {__VA_ARGS__};
