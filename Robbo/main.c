#include "platform.h"
#include "stdbool.h"
#include <string.h>
#include "gbdecompress.h"
#include "fields.h"
#include "functions_map.h"
#include "map.h"
#include "globals.h"
#include "levels_data.h"
#include "tiles.h"
#include "win_slide.h"
#include "changes.h"
#include "others.h"
#include "hud.h"
#include "camera.h"
#include "palettes.h"
#include "tiles_helperc.h"
#include "robbo_state.h"
#include "BCD8.h"
#include "sound_engine.h"

#define BETWEEN(n, start, end) ((((uint8_t)n)>=((uint8_t)(start))) && (((uint8_t)n)<((uint8_t)(end))))

inline void resetCounters()
{
	animCounter = 7;
	counter = 255;
}

const int8_t currentPtrOffests[] = { -1, 15, 31, 47 };

void mapIteration()
{
	changesPtr = changes;
	for (iterY = changeYstart; iterY < changeYend; iterY++)
	{
		doChanege = BETWEEN(iterY, map_pos_y == 0 ? 0 : map_pos_y - 1,  map_pos_y + visibleY + 1);
		currentYTilesPtr = nextYTiles + currentPtrOffests[iterY & 3];
		nextYTilesPtr = nextYTiles + currentPtrOffests[(iterY + 1) & 3];
		nextNextYTilesPtr = nextYTiles + currentPtrOffests[(iterY + 2) & 3];
		for (iterX = 0; iterX < 16; iterX++)
		{
			nextYTilesPtr++;
			nextNextYTilesPtr++;
			currentYTilesPtr++;
			if (*++mapPtr <= FIELD_TYPES_WALLS_END)
			{
				continue;
			}
			else if (*currentYTilesPtr != FIELD_NONE)
			{
				uint8_t tile = *currentYTilesPtr;
				*currentYTilesPtr = FIELD_NONE;
				*mapPtr = tile;
				if (doChanege)
				{
					PUT_CHANGES(mapPtr);
				}
			}
			else if (*mapPtr <= FIELD_TYPES_FUNCTIONS_END)
			{
				function function = functions_map[*mapPtr];
				if (function() && doChanege)
				{
					PUT_CHANGES(mapPtr);
				}
			}
			else
			{
				continue;
			}
		}
	}
	PUT_CHANGES_TERMINATOR();
}

bool stopCounting()
{
	screwsCounting = false;
	screwsCounted = true;
	showHUD();
	padEnabled = true;
	return true;
}

bool setupLevelFinished()
{
	screwsCounting = true;
	setNextFunction(&stopCounting);
	return false;
}

bool setupLevel()
{
	disableHUD();
	const uint8_t lvl = (0xf & level.value) + (level.value >> 4 & 0xf) * 10 - 1;
	uint8_t current = _current_bank;
	SWITCH_ROM_EX(BANK(levels_data));
	gb_decompress(levels[lvl], map);
	if (cave != (lvl/4))
	{
		cave = (lvl / 4);
		SWITCH_ROM_EX(BANK(tiles_data));
		gb_decompress_bkg_data(8, walls_tiles[cave]);
	}
	SWITCH_ROM_EX(current);
	repaintAll();
	robboState.screws.value = 0;
	robboState.ammo.value = 0;
	robboState.keys.value = 0;
	robboState.Y = robboState.X = 255;
	screwsCounted = false;
	setNextFunction(&setupLevelFinished);
	uint8_t wait = waitAfterSetupLevel;
	while (wait--)
		wait_vbl_done();
	startSlideOut();
	return false;
}

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
		else if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
		}
	}
	else if (counter == 2)
	{
		changeYstart = 12;
		changeYend = 18;
		if (slideX)
			slide_bkg_x();
		else if (slideY)
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
		else if (slideY)
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
		else if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
			slideY = 0;
		}
	}
	else
	{
		if (callNext)
		{
			callNextFunction();
		}
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
			if (padState & J_B)
			{
				if (padState & J_A)
				{
					if (padState & J_RIGHT)
					{
						padEnabled = false;
						uint8_t newLevel = incerement(&level);
						if (newLevel == 0x57)
							newLevel = 1;
						level.value = newLevel;
						drawNumber(9, 8, level.value);
						uiCounters[0] = uiElementNone;
						setNextFunction(&setupLevel);
						startSlideIn();
					}
					else if (padState & J_LEFT)
					{
						padEnabled = false;
						uint8_t newLevel = decrement(&level);
						if (newLevel == 0)
							newLevel = 0x56;
						level.value = newLevel;
						drawNumber(9, 8, level.value);
						uiCounters[0] = uiElementNone;
						setNextFunction(&setupLevel);
						startSlideIn();
					}
				}
				else
				{
					if ((padState & J_LEFT) && slide_to_map_pos_x == map_pos_x && slide_to_map_pos_x > 0)
					{
						slide_to_map_pos_x -= 3;
					}
					else if ((padState & J_RIGHT) && slide_to_map_pos_x == map_pos_x && slide_to_map_pos_x < maxPosX)
					{
						slide_to_map_pos_x += 3;
					}
					else if ((padState & J_UP) && slide_to_map_pos_y == map_pos_y && slide_to_map_pos_y > 0)
					{
						if (slide_to_map_pos_y == maxPosY && (maxPosY != (maxPosY & 0xfc)))
							slide_to_map_pos_y = (maxPosY & 0xfc);
						else
							slide_to_map_pos_y -= 4;
					}
					else if ((padState & J_DOWN) && slide_to_map_pos_y == map_pos_y && slide_to_map_pos_y < maxPosY)
					{
						slide_to_map_pos_y += 4;
						if ((maxPosY != (maxPosY & 0xfc)) && slide_to_map_pos_y > maxPosY)
							slide_to_map_pos_y = maxPosY;
					}
				}
			}
			memset(nextYTiles + 16, FIELD_NONE, 32);
		}
		if (slide_to_map_pos_x < map_pos_x)
		{
			slideX = -3;
			map_pos_x--;
			slide_bkg_x();
		}
		else if (slide_to_map_pos_x > map_pos_x)
		{
			slideX = 3;
			map_pos_x++;
			slide_bkg_x();
		}
		else if (slide_to_map_pos_y < map_pos_y)
		{
			slideY = -3;
			map_pos_y--;
			slide_bkg_y();
			if (map_pos_y != 0)
			{
				next_line = map + 16 * (map_pos_y - 1);
			}
		}
		else if (slide_to_map_pos_y > map_pos_y)
		{
			slideY = 3;
			map_pos_y++;
			slide_bkg_y();
			if (map_pos_y + visibleY < 32)
			{
				next_line = map + 16 * (map_pos_y + visibleY);
			}
		}
	}
	slideStep();
}

void main()
{
	waitAfterSetupLevel = 0;
	callNext = false;
	//cpu_fast();
	initSound();
	DISABLE_VBL_TRANSFER;
	DISPLAY_OFF;
	winSlideX = 0;
	winSlideToX = 0;
	padEnabled = false;
	set_bkg_palette(0, 1, (palette_color_t*)palettes);
	set_sprite_palette(0, 1, (palette_color_t*)sprites_palettes);
	uint8_t current = _current_bank;
	SWITCH_ROM_EX(BANK(tiles_data));
	gb_decompress_bkg_data(0, main_tiles);
	SWITCH_ROM_EX(current);
#ifdef GAMEBOY
	vmemcpy((uint8_t*)((void*)(TILE_ROBBO * 0x10 + 0x8000)), (uint8_t*)((void*)(TILE_ROBBO_DOWN * 0x10 + 0x8000)), 64);
#else
	//TODO: fix for SEGA
	//vmemcpy(TILE_ROBBO * 0x10, (uint8_t*)((uint16_t*)(TILE_ROBBO_DOWN * 0x10)), 128);
#endif 
	cameraPosY = cameraStartPosY;
	memset(nextYTiles, FIELD_NONE, 64);
	uint8_t* mapLastRow = map + 496;
	for (uint8_t i = 0; i < 16; i++)
		*mapLastRow++ = FIELD_BLACK_WALL;
	map_to_tiles = map_to_tiles1;
	map_to_tiles_hi = 0x2;
	map_pos_x = 0;
	map_pos_y = 0;
	slide_to_map_pos_x = 0;
	slide_to_map_pos_y = 0;
	drawNumber(9, 8, level.value);
	resetCounters();
	slideX = 0;
	slideY = 0;
	changeYstart = 0;
	changeYend = 6;
	mapPtr = map - 1;
	*changes = CHANGES_TERMINATOR;
	cameraPosX = -fixX;
	move_bkg(cameraPosX, cameraPosY);
	SHOW_BKG;
	setNextFunction(&setupLevel);
	initHUD();
	setupLevel();
	waitAfterSetupLevel = 40;
	DISPLAY_ON;
	wait_vbl_done();
	while (true)
	{
		padState = joypad();
		mapIteration();
		wait_vbl_done();
		drawHUD();
		incrementCounter();
		repaint();
		loopSound();
	}
}