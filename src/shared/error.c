#include "error.h"

#include <assert.h>
#include <stddef.h>

vlcb_error vlcb_error_VlcbEnumErrToStr(VlcbEnumConstructErr err) {
  assert(err > VLCB_ENUM_ERR_OK && err < VLCB_ENUM_ERR_COUNT);

  switch (err) {
    case VLCB_ENUM_ERR_INVALID_VALUE:
      return "invalid argument";
  }
}
