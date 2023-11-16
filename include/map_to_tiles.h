#pragma once
#include <stdint.h>
#include <globals.h>
#include <platform.h>

BANKREF_EXTERN(map_to_tiles_data)
void loadMapToTilesData();

extern uint8_t map_to_tiles0[];
extern uint8_t map_to_tiles1[];
extern uint8_t map_to_tiles2[];
extern uint8_t map_to_tiles3[];

inline void setupMapToTiles(uint8_t set)
{
    switch (set)
    {
    case 0:
    #ifdef SET_BKG_TILE_ASM
        map_to_tiles_lo = MAP_TO_TILES0_LO;
        map_to_tiles_hi = MAP_TO_TILES0_HI;
    #else
        map_to_tiles = map_to_tiles0;
    #endif
        return;
    case 1:
    #ifdef SET_BKG_TILE_ASM
        map_to_tiles_lo = MAP_TO_TILES1_LO;
        map_to_tiles_hi = MAP_TO_TILES1_HI;
    #else
        map_to_tiles = map_to_tiles1;
    #endif
        return;
    case 2:
    #ifdef SET_BKG_TILE_ASM
        map_to_tiles_lo = MAP_TO_TILES2_LO;
        map_to_tiles_hi = MAP_TO_TILES2_HI;
    #else
        map_to_tiles = map_to_tiles2;
    #endif
        return;
    case 3:
    #ifdef SET_BKG_TILE_ASM
        map_to_tiles_lo = MAP_TO_TILES3_LO;
        map_to_tiles_hi = MAP_TO_TILES3_HI;
    #else
        map_to_tiles = map_to_tiles3;
    #endif
        return;
    }

}