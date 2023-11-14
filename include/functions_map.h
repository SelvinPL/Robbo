#pragma once

#include <stdint.h>

typedef uint8_t (*function)();
typedef void (*void_function)();

extern const void_function functions_map[];