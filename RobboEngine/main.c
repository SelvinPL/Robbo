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

extern uint8_t changes[];

#if defined(GAMEBOY)
#define maxPosX 6
#define maxPosY 23
#define visibleY 8
#define fixX 0
#define fixY 0
#define fixTileX 0
#define fixTileY 0
#elif defined(GAMEGEAR)
#define maxPosX 6
#define maxPosY 22
#define visibleY 9
#define fixX 48
#define fixY 56
#define fixTileX 6
#define fixTileY 3
#else
#define maxPosX 0
#define maxPosY 19
#define visibleY 12
#define fixX 0
#define fixY 0
#define fixTileX 0
#define fixTileY 0
#endif 


#define BETWEEN(n, start, end) (((n)>=((uint8_t)(start))) && ((n)<((uint8_t)(end))))

#ifdef GAMEBOY
extern void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t) OLDCALL;
#else
inline void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t)
{
	uint8_t tiles[] = { t, t + 1, t + 2, t + 3 };
	set_bkg_tiles(2 * x - fixTileX, 2 * y - fixTileY, 2, 2, tiles);
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
		nextYTilesPtr = nextYTiles - 1;
		for (iterX = 0; iterX < 16; iterX++)
		{
			nextYTilesPtr++;
			if (*++mapPtr == FIELD_WALL || *mapPtr == FIELD_BLACK_WALL)
			{
				continue;
			}
			else  if (*nextYTilesPtr != FIELD_NONE)
			{
				*mapPtr = *nextYTilesPtr;
				*nextYTilesPtr = FIELD_NONE;
				if (doChanege)
				{
					*changesPtr++ = iterX;
					*changesPtr++ = iterY;
				}
			}
			else if (nextXTile != FIELD_NONE)
			{
				*mapPtr = nextXTile;
				nextXTile = FIELD_NONE;
				if (doChanege)
				{
					*changesPtr++ = iterX;
					*changesPtr++ = iterY;
				}
			}
			else if (*mapPtr == FIELD_EMPTY)
			{
				continue;
			}
			else
			{
				function function = functions_map[*mapPtr];
				uint8_t hi = (((uint16_t)function) >> 8) && 0xff;
				if (hi == 0)
				{
					uint8_t low = ((uint8_t)function);
					if (low == 0)
					{
						continue;
					}
					else if (low == 2)
					{
						if (!(animCounter & 1) && doChanege)
						{
							*changesPtr++ = iterX;
							*changesPtr++ = iterY;
						}
					}
					else
					{
						if (doChanege)
						{
							*changesPtr++ = iterX;
							*changesPtr++ = iterY;
						}
					}
				}
				else
				{
					if (function() && doChanege)
					{
						*changesPtr++ = iterX;
						*changesPtr++ = iterY;
					}
				}
			}
		}
	}
	*changesPtr = 0xff;
}

void repaint()
{
	uint8_t* change = changes;
	while (*change != 0xff)
	{
		uint8_t ux = *change++;
		uint8_t uy = *change++;
		set_bkg_tile_xy_2(ux, uy, map_to_tiles[map[ux + uy * 16]]);
	}
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
#ifdef GAMEBOY
	uint8_t current = _current_bank;
	SWITCH_ROM(BANK(levels_data));
#endif
	gb_decompress(levels[lvl], map);
#ifdef GAMEBOY
	SWITCH_ROM(current);
#endif
	for (uint8_t y = map_pos_y == 0 ? 0 : map_pos_y - 1; y < map_pos_y + visibleY + 1; y++)
	{
		for (uint8_t x = 0; x < 16; x++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[map[x + y * 16]]);
		}
	}
#ifdef GAMEBOY
	uint8_t wait = 40;
	while (wait--)
		wait_vbl_done();
#endif
	nextFunction = &setupLevelFinished;
	startSlideOut();
	return true;
}

void incrementCounter()
{
	counter++;
	if (counter == 1)
	{
		changeYstart = 6;
		changeYend = 12;
		if (slideX)
			scroll_bkg(slideX, 0);
		if (slideY)
			scroll_bkg(0, slideY);
	}
	else if (counter == 2)
	{
		changeYstart = 12;
		changeYend = 18;
		if(slideX)
			scroll_bkg(slideX, 0);
		if (slideY)
		{
			scroll_bkg(0, slideY);
			if (slideY > 0)
			{
				uint8_t y = map_pos_y + visibleY;
				if (y < 32)
				{
					for (uint8_t x = 0; x < 16; x++)
					{
						*changesPtr++ = x;
						*changesPtr++ = y;
					}
					*changesPtr = 0xff;
				}
			}
			else if (map_pos_y != 0)
			{
				uint8_t y = map_pos_y - 1;
				for (uint8_t x = 0; x < 16; x++)
				{
					*changesPtr++ = x;
					*changesPtr++ = y;
				}
				*changesPtr = 0xff;
			}
		}
	}
	else if (counter == 3)
	{
		changeYstart = 18;
		changeYend = 24;
		if (slideX)
		{
			scroll_bkg(slideX, 0);
			slideX = (int8_t)((((uint8_t)slideX) + 1) & 0b11111100); //works only fo 3 to 4 and -3 to - 4
		}
		if (slideY)
		{
			scroll_bkg(0, slideY);
			slideY = (int8_t)((((uint8_t)slideY) + 1) & 0b11111100);
		}
	}
	else if (counter == 4)
	{
		changeYstart = 24;
		changeYend = 32;
		if (slideX)
		{
			scroll_bkg(slideX, 0);
			slideX = 0;
		}
		if (slideY)
		{
			scroll_bkg(0, slideY);
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
		}
		else  if (animCounter == 4)
		{
			map_to_tiles = map_to_tiles3;
		}
		else  if (animCounter == 6)
		{
			map_to_tiles = map_to_tiles4;
		}
		else  if (animCounter == 8)
		{
			map_to_tiles = map_to_tiles1;
			animCounter = 0;
		}
		if (padEnabled)
		{
			if ((padState & J_LEFT) && map_pos_x > 0)
			{
				map_pos_x--;
				slideX = -3;
				scroll_bkg(slideX, 0);
			}
			else if ((padState & J_RIGHT) && map_pos_x < maxPosX)
			{
				map_pos_x++;
				slideX = 3;
				scroll_bkg(slideX, 0);
			}
			else if ((padState & J_UP) && map_pos_y > 0)
			{
				slideY = -3;
				scroll_bkg(0, slideY);
				map_pos_y--;

			}
			else if ((padState & J_DOWN) && map_pos_y < maxPosY)
			{
				slideY = 3;
				scroll_bkg(0, slideY);
				map_pos_y++;
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
#define palette1c2 RGBHTML(0xBF7A19)
#define palette1c3 RGBHTML(0x1E7400)
#define palette1c4 RGBHTML(0x000000)
#else
#define palette1c1 RGBHTML(0xe8e8e8)
#define palette1c2 RGBHTML(0xefaa49)
#define palette1c3 RGBHTML(0x4ea430)
#define palette1c4 RGBHTML(0x000000)
#endif

const palette_color_t cgb_palettes[] =
{
	palette1c1, palette1c2, palette1c3, palette1c4,
};
void main()
{
	level = 1;
	DISPLAY_OFF;
	winSlideX = 0;
	winSlideToX = 0;
	padEnabled = false;
	set_bkg_palette(0, 1, cgb_palettes);
	//set_2bpp_palette(COMPAT_PALETTE(1, 2, 3, 4));
#ifdef GAMEBOY
	init_win(tiles_trans_black_wall);
	WX_REG = 7;
	WY_REG = 0;
	SHOW_WIN;
	uint8_t current = _current_bank;
	SWITCH_ROM(BANK(tiles_data));
#endif
	set_bkg_data(0, 172, map_tiles);
	set_bkg_data(tiles_trans_mob_bird2, 32, map_tiles + (tiles_trans_mob_bird2 + 0x10) * 0x10);
	set_bkg_data(tiles_trans_robbo, 4u, map_tiles + tiles_trans_robbo_d * 0x10);
#ifdef GAMEBOY
	SWITCH_ROM(current);
#endif
	memset(nextYTiles, FIELD_NONE, 16);
	uint8_t* mapLastRow = map + 496;
	for (uint8_t i = 0; i < 16; i++)
		*mapLastRow++ = FIELD_BLACK_WALL;
	map_to_tiles = map_to_tiles1;
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
	*changes = 0xff;
	move_bkg(map_pos_x * 16 - fixX, map_pos_y * 16 - fixY);
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
		incrementCounter();
		repaint();
	}
}