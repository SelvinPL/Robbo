#include <platform.h>
#include <stdbool.h>
#include <string.h>
#include <gbdecompress.h>
#include <fields.h>
#include <functions_map.h>
#include <map.h>
#include <globals.h>
#include <levels_data.h>
#include <tiles.h>
#include <win_slide.h>
#include <changes.h>
#include <hud.h>
#include <camera.h>
#include <palettes.h>
#include <tiles_helperc.h>
#include <map_to_tiles.h>
#include <robbo_state.h>
#include <BCD8.h>
#include <sound_engine.h>
#include <changes.h>

inline void resetCounters()
{
	animCounter = 7U;
	counter = 255U;
}

const void_function*  current_functions_map = functions_map;

void mapIteration()
{
	changesPtr = changes;
	iterY = changeYstart;
	while(true)
	{
		iterX = 0;
		while(true)
		{
			if (*++mapPtr > FIELD_TYPES_WALLS_END)
			{
				if (*mapPtr <= FIELD_TYPES_MAX)
				{
					current_functions_map[*mapPtr]();
				} 
				else
				{
					*mapPtr = *mapPtr & FIELD_TYPES_MAX;
					change(mapPtr);
				}
			}
			if(++iterX == 16)
				break;
		}
		if(++iterY == changeYend)
			break;
	}
	PUT_CHANGES_TERMINATOR();
}

uint8_t stopCounting()
{
	screwsCountingState = SCREW_STATE_COUNTED;
	showHUD();
	padEnabled = true;
	return true;
}

uint8_t setupLevelFinished()
{
	screwsCountingState = SCREW_STATE_COUNTING;
	setNextFunction(&stopCounting);
	return false;
}

uint8_t setupLevel()
{
	disableHUD();
	PUT_CHANGES_TERMINATOR();
	const uint8_t lvl = level.low + level.hi * 10 - 1;
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
	setupMapToTiles(0);
	repaintAll();
	robboState.screws.value = 0;
	robboState.ammo.value = 0;
	robboState.keys.value = 0;
	robboState.teleporting = 0;
	robboState.teleportingState = 0;
	robboState.teleportX = 0;
	robboState.teleportY = 0;
	robboState.Y = robboState.X = 255;
	robboState.existsCounter = EXISTS_COUNTER_START;
	robboState.direction = direction_down;
	setupRooboTiles(direction_none);
	screwsCountingState = SCREW_STATE_NONE;
	counter = 5;
	setNextFunction(&setupLevelFinished);
	uint8_t wait = waitAfterSetupLevel;
	set_bkg_palette(0, 1, ((palette_color_t*)palettes) + ((cave % 4) * 4) );
	while (wait-- || soundState.isPlaying)
	{
		if(soundState.isPlaying)
			loopSound();
		wait_vbl_done();
	}
	startSlideOut();
	return false;
}

uint8_t* next_line = NULL;

void loadNextLine()
{
	if (slideY > 0)
	{
		if (map_pos_y < 33U - visibleY)
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

//#define PAL

#ifdef PAL
#define SLIDE_BY 		4
#define COUNTER4		3
#define CHANGE_Y_START0	0	
#define CHANGE_Y_END0	8
#define CHANGE_Y_START1	8	
#define CHANGE_Y_END1	16
#define CHANGE_Y_START2	16	
#define CHANGE_Y_END2	24
#define CHANGE_Y_START4	24	
#define CHANGE_Y_END4	32
#else
#define SLIDE_BY		3
#define COUNTER4		4
#define CHANGE_Y_START0	0	
#define CHANGE_Y_END0	6
#define CHANGE_Y_START1	6	
#define CHANGE_Y_END1	13
#define CHANGE_Y_START2	13	
#define CHANGE_Y_END2	19
#define CHANGE_Y_START3	19	
#define CHANGE_Y_END3	25
#define CHANGE_Y_START4	25	
#define CHANGE_Y_END4	32
#endif


void incrementCounter()
{
	counter++;

	if (counter == 1)
	{
		changeYstart = CHANGE_Y_START1;
		changeYend = CHANGE_Y_END1;
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
		changeYstart = CHANGE_Y_START2;
		changeYend = CHANGE_Y_END2;
		if (slideX)
		{
			slide_bkg_x();	
		}
		else if (slideY)
		{
			loadNextLine();
			slide_bkg_y();
		}
	}
#ifndef PAL
	else if (counter == 3)
	{
		changeYstart = CHANGE_Y_START3;
		changeYend = CHANGE_Y_END3;
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
#endif
	else if (counter == COUNTER4)
	{
		changeYstart = CHANGE_Y_START4;
		changeYend = CHANGE_Y_END4;
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
		changeYstart = CHANGE_Y_START0;
		changeYend = CHANGE_Y_END0;
		counter = 0;
		mapPtr = map - 1;
		animCounter = ((uint8_t)(animCounter + 1)) % 8u;
		setupMapToTiles(animCounter / 2);
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
		}
		if (slide_to_map_pos_x < map_pos_x)
		{
			--map_pos_x;
			slideX = (uint8_t)-SLIDE_BY;
			slide_bkg_x();
		}
		else if (slide_to_map_pos_x > map_pos_x)
		{
			++map_pos_x;
			slideX = SLIDE_BY;
			slide_bkg_x();
		}
		else if (slide_to_map_pos_y < map_pos_y)
		{
			--map_pos_y;
			slideY = (uint8_t)-SLIDE_BY;
			slide_bkg_y();
			if (map_pos_y != 0)
			{
				next_line = map + 16 * (uint8_t)(map_pos_y - 1);
			}
		}
		else if (slide_to_map_pos_y > map_pos_y)
		{
			++map_pos_y;
			slideY = SLIDE_BY;
			slide_bkg_y();
			if (map_pos_y < 32U - visibleY)
			{
				next_line = map + 16 * (uint8_t)(map_pos_y + visibleY - 1);
			}
		}

#ifdef PAL
		if (slideY)
		{
			loadNextLine();
		}
#endif						
		if(!winSlide && --robboState.existsCounter == 0)
		{
			robboState.lives.value = decrement(&robboState.lives);
			padEnabled = false;
			setNextFunction(&setupLevel);
			startSlideIn();
		}
		if(robboState.existsCounter == 20)
		{
			current_functions_map = functions_map_room_exploding;
		}
		else
		{
			current_functions_map = functions_map;
		}
	}
	slideStep();
}

uint8_t padStates[4] = {0};

void main()
{
	systemInit();
	level.value = 1;
	cave = 255;
	callNext = false;
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
	SWITCH_ROM_EX(BANK(map_to_tiles_data));
	loadMapToTilesData();
	SWITCH_ROM_EX(current);
	cameraPosY = cameraStartPosY;
	uint8_t* mapLastRow = map + 496;
	for (uint8_t i = 0; i < 16; i++)
		*mapLastRow++ = FIELD_BLACK_WALL;
	setupMapToTiles(0);
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
	initHUD();
	waitAfterSetupLevel = 40;
	DISPLAY_ON;
	wait_vbl_done();
	setupLevel();
	robboState.lives.value = 8;
	padStateCounter = 255;
	while (true)
	{
		padStates[++padStateCounter & 1] = joypad();
		padState = padStates[0] | padStates[1];
		mapIteration();
		wait_vbl_done();
		drawHUD();
		incrementCounter();
		repaint();
		loopSound();
	}
}