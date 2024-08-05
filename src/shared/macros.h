#pragma once

#define ARRAY_LEN(array) (sizeof(array) / sizeof((array)[0]))

#define DEFINE_ERROR_TYPE(PREFIX, TYPE, ...) \
    typedef enum { \
        PREFIX##_OK = 0, \
        __VA_ARGS__, \
        PREFIX##_COUNT \
    } TYPE;

#define DEFINE_ERROR(PREFIX, NAME) PREFIX_##NAME

