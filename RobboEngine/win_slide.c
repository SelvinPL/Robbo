#include <stdint.h>
#include "stdbool.h"

bool winSlide;
int8_t winSlideX;
#ifndef GAMEBOY
uint8_t winPositionX;
#endif
uint8_t winSlideToX;