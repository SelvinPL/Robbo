#pragma once

#include <stdint.h>
#include "platform.h"

void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) STANDARD_CALL(iyh, iyl);
void repaint();
void repaintAll();

