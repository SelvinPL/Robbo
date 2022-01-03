#include "platform.h"
#include "stdbool.h"
#include <string.h>
#include <gbdk/gbdecompress.h>
#include "fields.h"
#include "functions_map.h"
#include "map.h"
#include "globals.h"
#include "levels_data.h"
#include "tiles.h"
#include "win_slide.h"
#include "changes.h"

#define BETWEEN(n, start, end) ((((uint8_t)n)>=((uint8_t)(start))) && (((uint8_t)n)<((uint8_t)(end))))

#define ASM_TILES

#ifdef ASM_TILES
#ifdef GAMEBOY
extern void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) OLDCALL;
#else
extern void set_bkg_tile_xy_2_map_to_tiles_with_translation(uint8_t* map) __z88dk_callee __preserves_regs(iyh, iyl);
#endif
void repaint()
{
	uint8_t** change = changes - 1;
	while (*++change != CHANGES_TERMINATOR)
	{
		set_bkg_tile_xy_2_map_to_tiles_with_translation(*change);
	}
}
#else
inline void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t)
{
	uint8_t tiles[] = { t, t + 1, t + 2, t + 3 };
	set_bkg_tiles(2 * x - fixTileX, 2 * y - fixTileY, 2, 2, tiles);
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
#endif

inline uint8_t bcdIncerement(uint8_t i)
{
	uint8_t ni = i + 1;
	if ((ni & 0xf) == 0xa)
	{
		ni += 6;
	}
	return ni;
}

inline uint8_t bcdDecerement(uint8_t i)
{
	uint8_t ni = i - 1;
	if ((ni & 0xf) == 0xf)
	{
		ni -= 6;
	}
	return ni;
}

void mapIteration()
{
	changesPtr = changes;
	for (iterY = changeYstart; iterY < changeYend; iterY++)
	{
		doChanege = BETWEEN(iterY, map_pos_y == 0 ? 0 : map_pos_y - 1,  map_pos_y + visibleY + 1);
		if (iterY & 1)
		{
			nextYTilesPtr = nextYTiles - 1;
			currentYTilesPtr = nextYTiles + 15;
		}
		else
		{
			currentYTilesPtr = nextYTiles - 1;
			nextYTilesPtr = nextYTiles + 15;
		}
		for (iterX = 0; iterX < 16; iterX++)
		{
			nextYTilesPtr++;
			currentYTilesPtr++;
			if (*++mapPtr == FIELD_WALL || *mapPtr == FIELD_BLACK_WALL)
			{
				continue;
			}
			else  if (*currentYTilesPtr != FIELD_NONE)
			{
				*mapPtr = *currentYTilesPtr;
				*currentYTilesPtr = FIELD_NONE;
				if (doChanege)
				{
					PUT_CHANGES(mapPtr);
				}
			}
			else if (nextXTile != FIELD_NONE)
			{
				*mapPtr = nextXTile;
				nextXTile = FIELD_NONE;
				if (doChanege)
				{
					PUT_CHANGES(mapPtr);
				}
			}
			else if (*mapPtr == FIELD_EMPTY)
			{
				continue;
			}
			else
			{
				function function = functions_map[*mapPtr];
				uint8_t hi = (((uint16_t)function) >> 8);
				if (hi == 0)
				{
					uint8_t low = ((uint8_t)function);
					if (low == 0)
					{
						continue;
					}
					else if (low == 2)
					{
						if ((animCounter & 1) && doChanege)
						{
							PUT_CHANGES(mapPtr);
						}
					}
					else
					{
						if (doChanege)
						{
							PUT_CHANGES(mapPtr);
						}
					}
				}
				else
				{
					if (function() && doChanege)
					{
						PUT_CHANGES(mapPtr);
					}
				}
			}
		}
	}
	PUT_CHANGES_TERMINATOR();
}

bool setupLevelFinished()
{
	padEnabled = true;
#ifdef GAMEBOY
	move_win(7, 128);
#endif
	return true;
}

const uint8_t numbersTiles[10][2] =
{
	{ 0x10, 0x11 }, //0
	{ 0x12, 0x13 }, //1
	{ 0x1b, 0x15 }, //2
	{ 0x1b, 0x16 }, //3
	{ 0x17, 0x18 }, //4
	{ 0x19, 0x16 }, //5
	{ 0x19, 0x1a }, //6
	{ 0x14, 0x13 }, //7
	{ 0x1c, 0x1a }, //8
	{ 0x1c, 0x16 }, //9
};

void drawNumber(uint8_t x, uint8_t y, uint8_t number)
{
	set_win_tiles(x, y, 1, 2, numbersTiles[(number >> 4) & 0xf]);
	set_win_tiles(x + 1, y, 1, 2, numbersTiles[number & 0xf]);
}

bool setupLevel()
{
	const uint8_t lvl = (0xf & level) + (level >> 4 & 0xf) * 10 - 1;

	uint8_t current = _current_bank;
	SWITCH_ROM_EX(BANK(levels_data));
	gb_decompress(levels[lvl], map);
	SWITCH_ROM_EX(current);

	uint8_t startY = map_pos_y == 0 ? 0 : map_pos_y - 1;
	uint8_t* mapIterator = map + 16 * startY;
#ifdef ASM_TILES
	for (uint8_t y = 0; y < visibleY + 2; y++)
	{
		for (uint8_t x = 0; x < 16; x++, mapIterator++)
		{
			set_bkg_tile_xy_2_map_to_tiles_with_translation(mapIterator);
		}
	}
#else
	for (uint8_t y = startY; y < map_pos_y + visibleY + 1; y++)
	{
		for (uint8_t x = 0; x < 16; x++, mapIterator++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[*mapIterator]);
		}
	}
#endif

	uint8_t wait = 40;
	while (wait--)
		wait_vbl_done();
	nextFunction = &setupLevelFinished;
	startSlideOut();
	return true;
}

inline uint8_t incrementCameraX()
{
	return cameraPosX += slideX;
}

#ifdef GAMEBOY
inline uint8_t incrementCameraY()
{
	return cameraPosY += slideY;
}
inline void slide_bkg_x()
{
	SCX_REG = incrementCameraX();
}
inline void slide_bkg_y()
{
	SCY_REG = incrementCameraY();
}
#else
inline uint8_t incrementCameraY()
{
	uint8_t ret = cameraPosY + slideY;
	if (ret > 240)
		ret -= 32;
	else if (ret >= 224)
		ret -= 224;
	return cameraPosY = ret;
}

inline void slide_bkg_x()
{
	__WRITE_VDP_REG(VDP_RSCX, - incrementCameraX());
}
inline void slide_bkg_y()
{
	__WRITE_VDP_REG(VDP_RSCY, incrementCameraY());
}
#endif 

uint8_t* next_line = NULL;

inline void loadNextLine()
{
	if (slideY > 0)
	{
		if (map_pos_y + visibleY < 32)
		{
			for (uint8_t x = 0; x < 4; x++)
			{
				PUT_CHANGES(next_line);
				next_line++;
			}
			PUT_CHANGES_TERMINATOR();
		}
	}
	else if (map_pos_y != 0)
	{
		for (uint8_t x = 0; x < 4; x++)
		{
			PUT_CHANGES(next_line);
			next_line++;
		}
		PUT_CHANGES_TERMINATOR();
	}
}

void incrementCounter()
{
	counter++;
	if (counter == 1)
	{
		changeYstart = 6;
		changeYend = 12;
		if (slideX)
			slide_bkg_x();
		if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
		}
	}
	else if (counter == 2)
	{
		changeYstart = 12;
		changeYend = 18;
		if(slideX)
			slide_bkg_x();
		if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
		}
	}
	else if (counter == 3)
	{
		changeYstart = 18;
		changeYend = 24;
		if (slideX)
		{
			slide_bkg_x();
			slideX = (int8_t)((((uint8_t)slideX) + 1) & 0b11111100); //works only fo 3 to 4 and -3 to - 4
		}
		if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
			slideY = (int8_t)((((uint8_t)slideY) + 1) & 0b11111100);
		}
	}
	else if (counter == 4)
	{
		changeYstart = 24;
		changeYend = 32;
		if (slideX)
		{
			slide_bkg_x();
			slideX = 0;
		}
		if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
			slideY = 0;
		}
	}
	else
	{
		changeYstart = 0;
		changeYend = 6;
		counter = 0;
		mapPtr = map - 1;

		animCounter++;
		if (animCounter == 2)
		{
			map_to_tiles = map_to_tiles2;
			map_to_tiles_hi = 0x3;
		}
		else  if (animCounter == 4)
		{
			map_to_tiles = map_to_tiles3;
			map_to_tiles_hi = 0x4;
		}
		else  if (animCounter == 6)
		{
			map_to_tiles = map_to_tiles4;
			map_to_tiles_hi = 0x5;
		}
		else  if (animCounter == 8)
		{
			map_to_tiles = map_to_tiles1;
			map_to_tiles_hi = 0x2;
			animCounter = 0;
		}
		if (padEnabled)
		{
			if ((padState & J_LEFT) && map_pos_x > 0)
			{
				map_pos_x--;
				slideX = -3;
				slide_bkg_x();
			}
			else if ((padState & J_RIGHT) && map_pos_x < maxPosX)
			{
				map_pos_x++;
				slideX = 3;
				slide_bkg_x();
			}
			else if ((padState & J_UP) && map_pos_y > 0)
			{
				slideY = -3;
				slide_bkg_y();
				map_pos_y--;
				if (map_pos_y != 0)
				{
					next_line = map + 16 * (map_pos_y - 1);
				}
			}
			else if ((padState & J_DOWN) && map_pos_y < maxPosY)
			{
				slideY = 3;
				slide_bkg_y();
				map_pos_y++;
				if (map_pos_y + visibleY < 32)
				{
					next_line = map + 16 * (map_pos_y + visibleY);
				}
			}
			if (padState & J_B)
			{
				padEnabled = false;
				uint8_t newLevel = bcdDecerement(level);
				if (newLevel == 0)
					newLevel = 86;
				level = newLevel;
#ifdef GAMEBOY
				drawNumber(9, 8, level);
#endif
				nextFunction = &setupLevel;
				startSlideIn();
			}
			else if (padState & J_A)
			{
				padEnabled = false;
				uint8_t newLevel = bcdIncerement(level);
				if (newLevel == 87)
					newLevel = 1;
				level = newLevel;
#ifdef GAMEBOY
				drawNumber(9, 8, level);
#endif
				nextFunction = &setupLevel;
				startSlideIn();
			}
		}
	}
	slideStep();
}

#ifdef GAMEBOY
#define palette1c1 RGBHTML(0xa8a8a8)
#define palette1c2 RGBHTML(0xbf7a19)
#define palette1c3 RGBHTML(0x208020)
#define palette1c4 RGBHTML(0x000000)
#else
#define palette1c1 RGBHTML(0xffffff)
#define palette1c2 RGBHTML(0xffaa55)
#define palette1c3 RGBHTML(0x55aa55)
#define palette1c4 RGBHTML(0x000000)
#endif

const palette_color_t palettes[] =
{
	palette1c1, palette1c2, palette1c3, palette1c4,
};

#ifndef GAMEBOY
const uint8_t tile2_data[] = 
{ 
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
	tiles_trans_black_wall, 0, tiles_trans_black_wall, 0,
};
#endif

void main()
{
	DISABLE_VBL_TRANSFER;
	DISPLAY_OFF;
	level = 1;
	winSlideX = 0;
	winSlideToX = 0;
	padEnabled = false;
	set_bkg_palette(0, 1, (palette_color_t*)palettes);
	uint8_t current = _current_bank;
	SWITCH_ROM_EX(BANK(tiles_data));
	set_bkg_data(0, 172, map_tiles);
	set_bkg_data(tiles_trans_mob_bird2, 32, map_tiles + (tiles_trans_mob_bird2 + 0x10) * 0x10);
	set_bkg_data(tiles_trans_robbo, 4u, map_tiles + tiles_trans_robbo_d * 0x10);
	SWITCH_ROM_EX(current);
	cameraPosY = cameraStartPosY;
	initHUD();
	memset(nextYTiles, FIELD_NONE, 32);
	uint8_t* mapLastRow = map + 496;
	for (uint8_t i = 0; i < 16; i++)
		*mapLastRow++ = FIELD_BLACK_WALL;
	map_to_tiles = map_to_tiles1;
	map_to_tiles_hi = 0x2;
	map_pos_x = 0;
	map_pos_y = 0;
	
#ifdef GAMEBOY
	drawNumber(9, 8, level);
#endif
	animCounter = 7;
	counter = 255;
	slideX = 0;
	slideY = 0;
	changeYstart = 0;
	changeYend = 6;
	nextXTile = FIELD_NONE;
	mapPtr = map - 1;
	*changes = CHANGES_TERMINATOR;
	cameraPosX = -fixX;

	move_bkg(cameraPosX, cameraPosY);
	SHOW_BKG;
	nextFunction = &setupLevel;
	DISPLAY_ON;
	setupLevel();
	wait_vbl_done();
	while (true)
	{
		padState = joypad();
		mapIteration();
		wait_vbl_done();
		drawHUD();
		incrementCounter();
		repaint();
	}
}