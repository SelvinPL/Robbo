#include <stdint.h>
#include "stdbool.h"

bool winSlide;
int8_t winSlideX;
uint8_t winSlideToX;
bool callNext;

#ifndef GAMEBOY
uint8_t winPositionX;
#endif