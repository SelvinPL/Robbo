#pragma once

#include <stdint.h>
#include <globals.h>

#ifdef SET_BKG_TILE_ASM
extern void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) STANDARD_CALL;
#endif

extern void repaint();
extern void repaintAll();
extern void setupRooboTiles(directions direction);