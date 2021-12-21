#pragma once
#include "platform.h"
#include <stdint.h>

#ifdef GAMEBOY
BANKREF_EXTERN(levels_data)
#endif
extern const uint8_t* const levels[56];