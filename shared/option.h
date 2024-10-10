#pragma once

// Fun little thing, anonymous structs are not part of any standard C unitl C11
// therefore do NOT use this in core code, might be useful for tests or something
// that does not need to be super portable

#include <stdbool.h>

#define OPTION_TYPE(T) \
struct {           \
bool is_some;   \
T value;        \
}

#define SOME(value)     \
(typeof(value)){ true, value }

#define NONE(T)         \
(OPTION_TYPE(T)){ false }

#define IS_SOME(opt)    (opt.is_some)
#define IS_NONE(opt)    (!opt.is_some)