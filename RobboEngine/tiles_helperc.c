#include "platform.h"
#include "changes.h"
#include "tiles_helperc.h"
#include "globals.h"
#include "map.h"

#define ASM_TILES

#ifdef ASM_TILES

void repaint()
{
	uint8_t** change = changes - 1;
	while (*++change != CHANGES_TERMINATOR)
	{
		set_bkg_tile_xy_2_map_to_tiles_with_translation(*change);
	}
}

void repaintAll()
{
	uint8_t startY = map_pos_y == 0 ? 0 : map_pos_y - 1;
	uint8_t* mapIterator = map + 16 * startY;
	for (uint8_t y = 0; y < visibleY + 2; y++)
	{
		for (uint8_t x = 0; x < 16; x++, mapIterator++)
		{
			set_bkg_tile_xy_2_map_to_tiles_with_translation(mapIterator);
		}
	}
}

#else

inline void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t)
{
	uint8_t main_tiles[] = { t, t + 1, t + 2, t + 3 };
	set_bkg_tiles(2 * x - fixTileX, 2 * y - fixTileY, 2, 2, main_tiles);
}

void repaint()
{
	uint8_t** change = changes - 1;
	while (*++change != CHANGES_TERMINATOR)
	{
		uint8_t low = (uint8_t)(*change);
		uint8_t ux = low & 0xf;
		uint8_t uy = (low >> 4) | ((uint8_t)(((uint16_t)(*change)) >> 8) << 4);
		set_bkg_tile_xy_2(ux, uy, *((uint8_t*)((map_to_tiles_hi << 8) | **change)));
	}
}

void repaintAll()
{
	uint8_t startY = map_pos_y == 0 ? 0 : map_pos_y - 1;
	uint8_t* mapIterator = map + 16 * startY;
	for (uint8_t y = startY; y < map_pos_y + visibleY + 1; y++)
	{
		for (uint8_t x = 0; x < 16; x++, mapIterator++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[*mapIterator]);
		}
	}
}

#endif