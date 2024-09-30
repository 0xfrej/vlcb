#pragma once

#define vlcb_error const char *const

typedef enum {
  VLCB_ENUM_ERR_OK = 0,

  VLCB_ENUM_ERR_INVALID_VALUE,

  /**
   * Not an actual error, can be used to detect if the value is within range of
   * this enum.
   */
  VLCB_ENUM_ERR_COUNT,
} VlcbEnumConstructErr;

vlcb_error vlcb_error_VlcbEnumErrToStr(VlcbEnumConstructErr err);
