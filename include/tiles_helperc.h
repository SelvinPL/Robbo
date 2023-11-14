#pragma once

#include <stdint.h>

#ifdef SET_BKG_TILE_ASM
void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) STANDARD_CALL;
#endif

void repaint();
void repaintAll();