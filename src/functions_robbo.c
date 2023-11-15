#include <stdint.h>
#include <map.h>
#include <globals.h>
#include <platform.h>
#include <fields.h>
#include <changes.h>
#include <robbo_state.h>
#include <projectile_utils.h>
#include <hud.h>
#include <BCD8.h>
#include <win_slide.h>
#include <projectile_utils.h>
#include <sound_engine.h>
#include <stdbool.h>
#include <functions_robbo.h>
#include <map_to_tiles.h>

#define MIN(A,B)					((A)<(B)?(A):(B))

uint8_t setupLevel();

uint8_t newRobboTile;
uint8_t* newRobboPos;
uint8_t nextRobboTile;
uint8_t* nextRobboPos;
uint8_t waitFlag;
robbo_info robboState;

void slideToRobbo()
{
	robboState.X = newRobboX;
	if (maxPosX)
	{
		slide_to_map_pos_x = (robboState.X >= 9) ? 6 : (robboState.X < 6) ? 0 : 3;
	}
	robboState.Y = newRobboY;
	slide_to_map_pos_y = robboState.Y > 1 ? MIN((((robboState.Y - 2) >> 2) << 2), maxPosY) : 0;
}

void screw()
{
	if (screwsCountingState == SCREW_STATE_COUNTING)
	{
		robboState.screws.value = incerement(&robboState.screws);
	}
}

void robboStart()
{
	robboState.existsCounter = EXISTS_COUNTER_START;
	if(slideX != 0 || slideY != 0 || winSlide)
	{
		return;
	}
	if(--robboState.delay > 0)
	{
		return;
	}
	playSound(startLevelSound);
	*mapPtr = FIELD_ROBBO_APEARS_ANIM1;
	change(mapPtr);
	setupRooboSprite(TILE_ROBBO_DOWN, TILE_ROBBO_DOWN2);
}

void robbo()
{
	robboState.existsCounter = EXISTS_COUNTER_START;
	if (!(animCounter & 1))
		return;
	if (robboState.X == 255)
	{
		newRobboX = iterX;
		newRobboY = iterY;
		robboState.keys.value =  0;
		robboState.ammo.value =  0;
		robboState.delay = 5;
		*mapPtr = FIELD_ROBBO_START | FIELD_TYPES_WAIT_FLAG;
		change(mapPtr);
		slideToRobbo();
	}
	else if (!(padState & J_B))
	{
		if (!(padState & J_A))
		{
			newRobboX = robboState.X;
			newRobboY = robboState.Y;
			if (padState & J_UP)
			{
				newRobboPos = MAP_UP(mapPtr);
				newRobboTile = *newRobboPos & FIELD_TYPES_MAX;
				nextRobboPos = MAP_UP(newRobboPos);
				nextRobboTile = *nextRobboPos & FIELD_TYPES_MAX;
				newRobboY--;
				robboState.direction = J_UP;
				setupRooboSprite(TILE_ROBBO_UP, TILE_ROBBO_UP2);
				waitFlag = 0;
			}
			else if (padState & J_DOWN)
			{
				newRobboPos = MAP_DOWN(mapPtr);
				newRobboTile = *newRobboPos & FIELD_TYPES_MAX;
				nextRobboPos = MAP_DOWN(newRobboPos);
				nextRobboTile = *nextRobboPos & FIELD_TYPES_MAX;
				newRobboY++;
				robboState.direction = J_DOWN;
				setupRooboSprite(TILE_ROBBO_DOWN, TILE_ROBBO_DOWN2);
				waitFlag = FIELD_TYPES_WAIT_FLAG;
			}
			else if (padState & J_LEFT)
			{
				newRobboPos = MAP_LEFT(mapPtr);
				newRobboTile = *newRobboPos & FIELD_TYPES_MAX;
				nextRobboPos = MAP_LEFT(newRobboPos);
				nextRobboTile = *nextRobboPos & FIELD_TYPES_MAX;
				newRobboX--;
				robboState.direction = J_LEFT;
				setupRooboSprite(TILE_ROBBO_LEFT, TILE_ROBBO_LEFT2);
				waitFlag = 0;
			}
			else if (padState & J_RIGHT)
			{
				newRobboPos = MAP_RIGHT(mapPtr);
				newRobboTile = *newRobboPos & FIELD_TYPES_MAX;
				nextRobboPos = MAP_RIGHT(newRobboPos);
				nextRobboTile = *nextRobboPos & FIELD_TYPES_MAX;
				newRobboX++;
				robboState.direction = J_RIGHT;
				setupRooboSprite(TILE_ROBBO_RIGHT, TILE_ROBBO_RIGHT2);
				waitFlag = FIELD_TYPES_WAIT_FLAG;
			}
			else
			{
				robboState.teleporting = 0;
				return;
			}
			switch (newRobboTile)
			{
			case FIELD_EMPTY:
				break;
			case FIELD_KEY:
				{
					playSound(keySound);
					uint8_t keys = incerement(&robboState.keys);
					robboState.keys.value = keys < ((uint8_t)0x99) ? keys : ((uint8_t)0x99);
					postUICounter(uiElementKeys, keys);
				}
				break;
			case FIELD_AMMO:
				{
					playSound(ammoSound);
					uint8_t ammo = add_up_to_9(&robboState.ammo, 9);
					robboState.ammo.value = ammo < ((uint8_t)0x99) ? ammo : ((uint8_t)0x99);
					postUICounter(uiElementAmmo, ammo);
				}
				break;
			case FIELD_SCREW:
				{
					playSound(screwSound);
					if (robboState.screws.value > 0 )
					{
						uint8_t screws = decrement(&robboState.screws);
						robboState.screws.value = screws;
						postUICounter(uiElementScrews, screws);
					}
				}
				break;
			case FIELD_LIFE:
				{
					playSound(extraLifeSound);
					uint8_t lives = incerement(&robboState.lives);
					robboState.lives.value = lives;
					postUICounter(uiElementLives, lives);
				}
				break;
			case FIELD_INERT_BOX:
				{
					if (nextRobboTile == FIELD_EMPTY)
					{
						if (padState & J_UP)
						{
							*nextRobboPos = FIELD_INERT_BOX_UP;
						}
						else if (padState & J_DOWN)
						{
							*nextRobboPos = FIELD_INERT_BOX_DOWN | FIELD_TYPES_WAIT_FLAG;
						}
						else if (padState & J_LEFT)
						{
							*nextRobboPos = FIELD_INERT_BOX_LEFT;
						}
						else
						{
							*nextRobboPos = FIELD_INERT_BOX_RIGHT | FIELD_TYPES_WAIT_FLAG;
						}
						change(nextRobboPos);
						break;
					}
					else
						return;
				}
			case FIELD_BOX:
			case FIELD_BOMB:
			case FIELD_SURPRISE:
			case FIELD_SHIP:
			case FIELD_MOVABLE_GUN_LEFT:
			case FIELD_MOVABLE_GUN_RIGHT:
				if (nextRobboTile == FIELD_EMPTY)
				{
					*nextRobboPos = newRobboTile | waitFlag;
					change(nextRobboPos);
				}
				else
				{
					return;
				}
				break;
			case FIELD_SHIP_BLINK1:
			case FIELD_SHIP_BLINK2:
				{
					playSound(nextLevelSound);
					uint8_t newLevel = incerement(&level);
					if (newLevel == 0x57)
					{
						//TODO: win!!
						newLevel = 1;
					}
					level.value = newLevel;
					drawNumber(9, 8, level.value);
					setNextFunction(&setupLevel);
					*mapPtr = FIELD_EMPTY;
					*newRobboPos = FIELD_SHIP;
					screwsCountingState = SCREW_STATE_NONE;
					startSlideIn();
				}
				change(mapPtr);
				return;
			case FIELD_DOOR:
				if (robboState.keys.value > 0)
				{
					playSound(openDoorSound);
					robboState.keys.value = decrement(&robboState.keys);
					postUICounter(uiElementKeys, robboState.keys.value);
					*newRobboPos = FIELD_OPENING_DOOR | waitFlag;
				}
				return;
			case FIELD_TELEPORT0:
			case FIELD_TELEPORT1:
			case FIELD_TELEPORT2:
			case FIELD_TELEPORT3:
			case FIELD_TELEPORT4:
			case FIELD_TELEPORT5:
			case FIELD_TELEPORT6:
			case FIELD_TELEPORT7:
			case FIELD_TELEPORT8:
			case FIELD_TELEPORT9:
				playSound(teleportSound);
				*mapPtr = FIELD_EXPLOSION_ANIM3;
				robboState.teleporting = newRobboTile;
				robboState.teleportingState = 1;
				switch (robboState.direction)
				{
				case J_UP:
					robboState.teleportX = iterX;
					robboState.teleportY = iterY - 1;
					break;
				case J_DOWN:
					robboState.teleportX = iterX;
					robboState.teleportY = iterY + 1;
					break;
				case J_LEFT:
					robboState.teleportX = iterX - 1;
					robboState.teleportY = iterY;
					break;
				case J_RIGHT:
					robboState.teleportX = iterX + 1;
					robboState.teleportY = iterY;
					break;
				}
				change(mapPtr);
				return;
			default:
				return;
			}
			*mapPtr = FIELD_EMPTY;
#ifndef SEGA
			playSound(walkSound);
#endif
			*newRobboPos = FIELD_ROBBO | FIELD_TYPES_WAIT_FLAG;
			change(newRobboPos);
			slideToRobbo();
			change(mapPtr);
			return;
		}
		else if(robboState.ammo.value > 0 && !robboState.delay)
		{
			if (padState & J_UP)
			{
				setupRooboSprite(TILE_ROBBO_UP, TILE_ROBBO_UP2);
				shootUp(true, mapPtr);
			}
			else if (padState & J_DOWN)
			{
				setupRooboSprite(TILE_ROBBO_DOWN, TILE_ROBBO_DOWN2);
				shootDown(true, mapPtr);
			}
			else if (padState & J_LEFT)
			{
				
				setupRooboSprite(TILE_ROBBO_LEFT, TILE_ROBBO_LEFT2);
				shootLeft(true, mapPtr);
			}
			else if (padState & J_RIGHT)
			{
				setupRooboSprite(TILE_ROBBO_RIGHT, TILE_ROBBO_RIGHT2);
				shootRight(true, mapPtr);
			}
			else
			{
				return;
			}
			robboState.ammo.value = decrement(&robboState.ammo);
			postUICounter(uiElementAmmo, robboState.ammo.value);
			robboState.delay = 5;
			change(mapPtr);
			return;
		}
	}
	if (robboState.delay)
	{
		robboState.delay--;
	}
}


void ship()
{
	if (screwsCountingState == SCREW_STATE_COUNTED && !robboState.screws.value)
	{
		playSound(openExitSound);
		*mapPtr = FIELD_SHIP_BLINK1;
	}
}


void shipBlink1()
{
	if (animCounter == 1)
	{
		*mapPtr = FIELD_SHIP_BLINK2;
		change(mapPtr);
	}
}

void shipBlink2()
{
	if (animCounter == 1)
	{
		*mapPtr = FIELD_SHIP_BLINK1;
		change(mapPtr);
	}
}