#pragma once

#include <inttypes.h>
#include <stddef.h>
#include <stddef.h>

typedef uint8_t ErrorCode;
typedef const char * const Error;

typedef struct ErrorTrace {
  ErrorCode code;
  Error (*getMessage)(const ErrorTrace * const);
  ErrorTrace * const prev;
} VlcbErrTrace;

const VlcbErrTrace NilError = {
  .code = 0,
  .getMessage = NULL,
  .prev = NULL,
};

bool vlcb_err_IsError(const VlcbErrTrace * const trace);
