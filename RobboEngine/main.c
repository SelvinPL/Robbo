﻿#include <gb/gb.h>
#include <string.h>
#include <gb/cgb.h>
#include <stdbool.h>
#include <gb/gbdecompress.h>
#include "fields.h"
#include "functions_map.h"
#include "map.h"
#include "globals.h"
#include "levels_data.h"
#include "tiles.h"

extern uint8_t chaneges[];

#define BETWEEN(n, start, end) (((n)>=((uint8_t)(start))) && ((n)<((uint8_t)(end))))

extern void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t) OLDCALL;

void mapIteration()
{
	chanegesPtr = chaneges;
	for (iterY = changeYstart; iterY < changeYend; iterY++)
	{
		doChanege = BETWEEN(iterY, map_pos_y == 0 ? 0 : map_pos_y - 1,  map_pos_y + 10);
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
					*chanegesPtr++ = iterX;
					*chanegesPtr++ = iterY;
				}
			}
			else if (nextXTile != FIELD_NONE)
			{
				*mapPtr = nextXTile;
				nextXTile = FIELD_NONE;
				if (doChanege)
				{
					*chanegesPtr++ = iterX;
					*chanegesPtr++ = iterY;
				}
			}
			else if (*mapPtr == FIELD_EMPTY)
			{
				continue;
			}
			else
			{
				function function = functions_map[*mapPtr];
				//uint8_t hi = (((uint16_t)function) >> 8) && 0xff;
				uint8_t hi = (((uint16_t)function) >> 8) && 0xff;
				if (hi == 0)
				{
					uint8_t low = ((uint8_t)function);
					switch (low)
					{
					case 0:
						continue;
					case 1:
						if (doChanege)
						{
							*chanegesPtr++ = iterX;
							*chanegesPtr++ = iterY;
						}
						break;
					case 2:
						if (!(animCounter & 1) && doChanege)
						{
							*chanegesPtr++ = iterX;
							*chanegesPtr++ = iterY;
						}
						break;
					default:
						continue;
					}
				}
				else
				{
					if (function() && doChanege)
					{
						*chanegesPtr++ = iterX;
						*chanegesPtr++ = iterY;
					}
				}
			}
		}
	}
	*chanegesPtr = 0xff;
}

const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");	\
	__asm__("	nop");


void repaint()
{
	uint8_t* change = chaneges;
	while (*change != 0xff)
	{
		uint8_t ux = *change++;
		uint8_t uy = *change++;
		set_bkg_tile_xy_2(ux, uy, map_to_tiles[map[ux + uy * 16]]);
	}

}

void setupLevel()
{
	uint8_t current = _current_bank;
	SWITCH_ROM_MBC1((uint8_t)&__bank_levels_data);
	gb_decompress(levels[lvl - 1], map);
	SWITCH_ROM_MBC1(current);
	for (uint8_t y = map_pos_y == 0 ? 0 : map_pos_y - 1; y < map_pos_y + 10; y++)
	{
		for (uint8_t x = 0; x < 16; x++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[map[x + y * 16]]);
		}
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
			SCX_REG += slideX;
		if (slideY)
			SCY_REG += slideY;
	}
	else if (counter == 2)
	{
		changeYstart = 12;
		changeYend = 18;
		if(slideX)
			SCX_REG += slideX;
		if (slideY)
		{
			SCY_REG += slideY;
			if (slideY > 0)
			{
				uint8_t y = map_pos_y + 9;
				if (y < 32)
				{
					for (uint8_t x = 0; x < 16; x++)
					{
						*chanegesPtr++ = x;
						*chanegesPtr++ = y;
					}
					*chanegesPtr = 0xff;
				}
			}
			else if (map_pos_y != 0)
			{
				uint8_t y = map_pos_y - 1;
				for (uint8_t x = 0; x < 16; x++)
				{
					*chanegesPtr++ = x;
					*chanegesPtr++ = y;
				}
				*chanegesPtr = 0xff;
			}
		}
	}
	else if (counter == 3)
	{
		changeYstart = 18;
		changeYend = 24;
		if (slideX)
		{
			SCX_REG += slideX;
			slideX = (int8_t)((((uint8_t)slideX) + 1) & 0b11111100); //works only fo 3 to 4 and -3 to - 4
		}
		if (slideY)
		{
			SCY_REG += slideY;
			slideY = (int8_t)((((uint8_t)slideY) + 1) & 0b11111100);
		}
	}
	else if (counter == 4)
	{
		changeYstart = 24;
		changeYend = 32;
		if (slideX)
		{
			SCX_REG += slideX;
			slideX = 0;
		}
		if (slideY)
		{
			SCY_REG += slideY;
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
		if ((padState & J_LEFT) && map_pos_x > 0)
		{
			map_pos_x--;
			slideX = -3;
			SCX_REG -= 3;
		}
		else if ((padState & J_RIGHT) && map_pos_x < 6)
		{
			map_pos_x++;
			slideX = 3;
			SCX_REG += 3;
		}
		else if ((padState & J_UP) && map_pos_y > 0)
		{
			slideY = -3;
			SCY_REG -= 3;
			map_pos_y--;

		}
		else if ((padState & J_DOWN) && map_pos_y < (32 - 9))
		{
			slideY = 3;
			SCY_REG += 3;
			map_pos_y++;
		}
		if (padState & J_B)
		{
			uint8_t newLevel = lvl - 1;
			if (newLevel == 0)
				newLevel = 56;
			lvl = newLevel;
			setupLevel();
		}
		else if (padState & J_A)
		{
			uint8_t newLevel = lvl + 1;
			if (newLevel == 57)
				newLevel = 1;
			lvl = newLevel;
			setupLevel();
		}
	}
}

void main()
{
	DISPLAY_OFF;
	set_bkg_data(0, 172, map_tiles);
	set_bkg_data(tiles_trans_mob_bird2, 32, map_tiles + (tiles_trans_mob_bird2 + 0x10) * 0x10);
	set_bkg_data(tiles_trans_robbo, 4u, &map_tiles[tiles_trans_robbo_d * 0x10]);
	memset(nextYTiles, FIELD_NONE, 16);
	uint8_t* mapee = map + 496;
	for (uint8_t i = 0; i < 16; i++)
		*mapee++ = FIELD_BLACK_WALL;
	map_to_tiles = map_to_tiles1;
	map_pos_x = 0;
	map_pos_y = 8;

	lvl = 1;
	setupLevel();
	SHOW_BKG;
	animCounter = 7;
	counter = 255;
	slideX = 0;
	slideY = 0;
	changeYstart = 0;
	changeYend = 6;
	nextXTile = FIELD_NONE;
	mapPtr = map - 1;
	*chaneges = 0xff;
	SCX_REG = map_pos_x * 16;
	SCY_REG = map_pos_y * 16;
	DISPLAY_ON;
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