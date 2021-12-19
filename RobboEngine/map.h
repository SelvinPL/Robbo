#pragma once
#include <stdint.h>

#define MAP_LEFT(map)		((map)-1)
#define MAP_RIGHT(map)		((map)+1)
#define MAP_UP(map)			((map)-16)
#define MAP_DOWN(map)		((map)+16)

extern uint8_t map[];
extern const uint8_t const map_tiles[];

extern const uint8_t const map_to_tiles1[];
extern const uint8_t const map_to_tiles2[];
extern const uint8_t const map_to_tiles3[];
extern const uint8_t const map_to_tiles4[];