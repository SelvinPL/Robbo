#include <stdint.h>
#include "map.h"
#include "globals.h"
#include "platform.h"
#include "fields.h"
#include "changes.h"
#include "robbo_state.h"
#include "projectile_utils.h"

#define MIN(A,B)					((A)<(B)?(A):(B))

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
uint8_t screwCounting;

void slideToRobbo()
{
	robboState.X = newRobboX;
	if (maxPosX)
	{
		slide_to_map_pos_x = (robboState.X >= 9) ? 6 : (robboState.X < 6) ? 0 : 3;
	}
	robboState.Y = newRobboY;
	if (robboState.Y > 1)
	{
		slide_to_map_pos_y = MIN((((robboState.Y - 2) >> 2) << 2), maxPosY);
	}
}

bool screw()
{
	if (screwCounting)
	{
		robboState.screws++;
	}
	return false;
}

bool robbo()
{
	if (!(animCounter & 1))
		return;
	if (robboState.X == 255)
	{
		newRobboX = ((uint8_t)mapPtr) & 0xf;
		newRobboY = (((uint8_t)mapPtr) >> 4) | (((uint8_t)((uint16_t)mapPtr >> 8)) << 4);
		robboState.keys = 0;
		robboState.ammo = 0;
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
				//TODO: pick key
				robboState.keys++;
				break;
			case FIELD_AMMO:
				robboState.ammo+=9;
				//TODO: pick ammo
				break;
			case FIELD_SCREW:
				//TODO: pick screw
			case FIELD_LIFE:
				//TODO: pick life
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
			case FIELD_DOOR:
				if (robboState.keys > 0)
				{
					robboState.keys--;
					*newRobboPosDest = FIELD_OPENING_DOOR;
				}
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
		else if(robboState.ammo > 0 && !robboState.shootDelay)
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
			robboState.ammo--;
			robboState.shootDelay = 5;
		}
	}
	if (robboState.shootDelay)
	{
		robboState.shootDelay--;
	}
	return false;
}