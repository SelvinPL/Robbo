#include <stdint.h>
#include <platform.h>
#include <changes.h>
#include <globals.h>
#include <map.h>
#include <fields_definition.h>
#include <map_to_tiles.h>
#include <tiles_definition.h>
#include <directions.h>

#ifdef SET_BKG_TILE_ASM
void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) STANDARD_CALL;
#endif

#define MIN(A,B)					((A)<(B)?(A):(B))

const uint8_t robboTiles[] =
{
	TILE_ROBBO_LEFT, TILE_ROBBO_LEFT2,
	TILE_ROBBO_UP, TILE_ROBBO_UP2,
	TILE_ROBBO_RIGHT, TILE_ROBBO_RIGHT2,
	TILE_ROBBO_DOWN, TILE_ROBBO_DOWN2,
	TILE_EMPTY, TILE_EMPTY
};

void setupRooboTiles(directions direction)
{
	map_to_tiles0[FIELD_ROBBO] = robboTiles[2*direction];
	map_to_tiles2[FIELD_ROBBO] = robboTiles[2*direction];
	map_to_tiles1[FIELD_ROBBO] = robboTiles[2*direction + 1];
	map_to_tiles3[FIELD_ROBBO] = robboTiles[2*direction + 1];
}


#ifdef SET_BKG_TILE_ASM
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
	uint8_t lines = (map_pos_y == 0 ? (visibleY + 1) : MIN(32U - startY, visibleY + 2)) * 16;
	uint8_t* mapIterator = map + 16 * startY;
	do
	{
		set_bkg_tile_xy_2_map_to_tiles_with_translation(mapIterator++);
	}while(--lines > 0);
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
		set_bkg_tile_xy_2(ux, uy, map_to_tiles[**change & FIELD_TYPES_MAX]);
	}
}

void repaintAll()
{
	uint8_t startY = map_pos_y == 0 ? 0 : map_pos_y - 1;
	uint8_t endY = startY + (map_pos_y == 0 ? (visibleY + 1) : MIN(32U - startY, visibleY + 2));
	uint8_t* mapIterator = map + 16 * startY;
	for (uint8_t y = startY; y < endY; y++)
	{
		for (uint8_t x = 0; x < 16; x++, mapIterator++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[*mapIterator]);
		}
	}
}
#endif

