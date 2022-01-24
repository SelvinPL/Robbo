#include <stdint.h>
#include "map.h"
#include "globals.h"
#include "platform.h"
#include "fields.h"
#include "changes.h"
#include "robbo_state.h"
#include "projectile_utils.h"
#include "hud.h"
#include "BCD8.h"
#include "win_slide.h"
#include "projectile_utils.h"

#define MIN(A,B)					((A)<(B)?(A):(B))

bool setupLevel();

uint8_t newRobboTile;
uint8_t* newRobboPos;
uint8_t* newRobboPosDest;
uint8_t nextRobboTile;
uint8_t* nextRobboPos;
uint8_t* nextRobboPosDest;
bool sendChange;
uint8_t newRobboX;
uint8_t newRobboY;
robbo_info robboState;
bool screwsCounting;
bool screwsCounted;

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

bool screw()
{
	if (screwsCounting)
	{
		robboState.screws.value = incerement(&robboState.screws);
	}
	return false;
}

bool robbo()
{
	if (!(animCounter & 1))
		return false;
	if (robboState.X == 255)
	{
		newRobboX = ((uint8_t)mapPtr) & 0xf;
		newRobboY = (((uint8_t)mapPtr) >> 4) | (((uint8_t)((uint16_t)mapPtr >> 8)) << 4);
		robboState.keys.value =  0;
		robboState.ammo.value =  0;
		robboState.shootDelay = 0;
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
				newRobboPosDest = newRobboPos;
				newRobboTile = *newRobboPos;
				nextRobboPos = MAP_UP(newRobboPos);
				nextRobboPosDest = nextRobboPos;
				nextRobboTile = *nextRobboPos;
				newRobboY--;
				sendChange = true;
			}
			else if (padState & J_DOWN)
			{
				newRobboPos = MAP_DOWN(mapPtr);
				newRobboPosDest = nextYTilesPtr;
				newRobboTile = *newRobboPosDest != FIELD_NONE ? *newRobboPosDest : *newRobboPos;
				nextRobboPos = MAP_DOWN(newRobboPos);
				nextRobboPosDest = nextNextYTilesPtr;
				nextRobboTile = *nextRobboPosDest != FIELD_NONE ? *nextRobboPosDest : *nextRobboPos;
				newRobboY++;
				sendChange = false;
			}
			else if (padState & J_LEFT)
			{
				newRobboPos = MAP_LEFT(mapPtr);
				newRobboPosDest = newRobboPos;
				newRobboTile = *newRobboPos;
				nextRobboPos = MAP_LEFT(newRobboPos);
				nextRobboPosDest = nextRobboPos;
				nextRobboTile = *nextRobboPos;
				newRobboX--;
				sendChange = true;
			}
			else if (padState & J_RIGHT)
			{
				newRobboPos = MAP_RIGHT(mapPtr);
				newRobboPosDest = currentYTilesPtr + 1;
				newRobboTile = *newRobboPosDest != FIELD_NONE ? *newRobboPosDest : *newRobboPos;
				nextRobboPos = MAP_RIGHT(newRobboPos);
				nextRobboPosDest = MAP_RIGHT(newRobboPosDest);
				nextRobboTile = *nextRobboPosDest != FIELD_NONE ? *nextRobboPosDest : *nextRobboPos;
				newRobboX++;
				sendChange = false;
			}
			else
			{
				return false;
			}
			switch (newRobboTile)
			{
			case FIELD_KEY:
				{
					uint8_t keys = incerement(&robboState.keys);
					robboState.keys.value = keys < 0x99 ? keys : 0x99;
					postUICounter(uiElementKeys, keys);
				}
				break;
			case FIELD_AMMO:
				{
					uint8_t ammo = add_up_to_9(&robboState.ammo, 9);
					robboState.ammo.value = ammo < 0x99 ? ammo : 0x99;
					postUICounter(uiElementAmmo, ammo);
				}
				break;
			case FIELD_SCREW:
				{
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
					if (robboState.screws.value > 0)
					{
						uint8_t lives = incerement(&robboState.lives);
						robboState.lives.value = lives;
						postUICounter(uiElementLives, lives);
					}
				}
				break;
			case FIELD_INERT_BOX_RIGHT:
			case FIELD_INERT_BOX_DOWN:
			case FIELD_INERT_BOX:
				{
					if (nextRobboTile == FIELD_EMPTY)
					{
						if (padState & J_UP)
						{
							*nextRobboPosDest = FIELD_INERT_BOX_UP;
						}
						else if (padState & J_DOWN)
						{
							*nextRobboPosDest = FIELD_INERT_BOX_DOWN;
						}
						else if (padState & J_LEFT)
						{
							*nextRobboPosDest = FIELD_INERT_BOX_LEFT;
						}
						else
						{
							*nextRobboPosDest = FIELD_INERT_BOX_RIGHT;
						}
						if(sendChange)
							change(nextRobboPosDest);
					}
					else
						return false;
				}
			case FIELD_EMPTY:
				break;
			case FIELD_BOX:
			case FIELD_BOMB:
			case FIELD_SURPRISE:
			case FIELD_SHIP:
			case FIELD_MOVABLE_GUN_LEFT:
			case FIELD_MOVABLE_GUN_RIGHT:
				if (nextRobboTile == FIELD_EMPTY)
				{
					*nextRobboPosDest = newRobboTile;
					if (sendChange)
					{
						change(nextRobboPosDest);
					}
				}
				else
				{
					return false;
				}
				break;
			case FIELD_SHIP_BLINK1:
			case FIELD_SHIP_BLINK2:
				{
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
					*newRobboPosDest = FIELD_SHIP;
					screwsCounted = false;
					startSlideIn();
				}
				return true;
			case FIELD_DOOR:
				if (robboState.keys.value > 0)
				{
					robboState.keys.value = decrement(&robboState.keys);
					postUICounter(uiElementKeys, robboState.keys.value);
					*newRobboPosDest = FIELD_OPENING_DOOR;
				}
				return false;
			default:
				return false;
			}
			*mapPtr = FIELD_EMPTY;
			*newRobboPosDest = FIELD_ROBBO;
			if (sendChange)
			{
				change(newRobboPosDest);
			}
			slideToRobbo();
			return true;
		}
		else if(robboState.ammo.value > 0 && !robboState.shootDelay)
		{
			if (padState & J_UP)
			{
				shootUp(true, mapPtr);
			}
			else if (padState & J_DOWN)
			{
				shootDown(true, mapPtr);
			}
			else if (padState & J_LEFT)
			{
				shootLeft(true, mapPtr);
			}
			else if (padState & J_RIGHT)
			{
				shootRight(true, mapPtr);
			}
			else
			{
				return false;
			}
			robboState.ammo.value = decrement(&robboState.ammo);
			postUICounter(uiElementAmmo, robboState.ammo.value);
			robboState.shootDelay = 5;
		}
	}
	if (robboState.shootDelay)
	{
		robboState.shootDelay--;
	}
	return false;
}


bool ship()
{
	if (screwsCounted && !robboState.screws.value)
		*mapPtr = FIELD_SHIP_BLINK1;
	return false;
}


bool shipBlink1()
{
	if (animCounter == 1)
	{
		*mapPtr = FIELD_SHIP_BLINK2;
		return true;
	}
	return false;
}

bool shipBlink2()
{
	if (animCounter == 1)
	{
		*mapPtr = FIELD_SHIP_BLINK1;
		return true;
	}
	return false;
}