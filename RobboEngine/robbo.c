#include <stdint.h>
#include "map.h"
#include "globals.h"
#include "platform.h"
#include "fields.h"
#include "changes.h"

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
uint8_t keys;

bool robbo()
{
	if (!(padState & J_SELECT) && (animCounter & 1))
	{
		if (robboX == 255)
		{
			robboX = ((uint8_t)mapPtr) & 0xf;
			robboY = ((((uint8_t)mapPtr) & 0xf0) >> 4) | ((((uint8_t)((uint16_t)mapPtr >> 8)) & 0xf) << 4);
			keys = 0;
		}
		newRobboX = robboX;
		newRobboY = robboY;
		if ((padState & J_UP))
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
		else if ((padState & J_DOWN))
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
		else if ((padState & J_LEFT))
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
		else if ((padState & J_RIGHT))
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
			keys++;
		case FIELD_AMMO:
			//TODO: pick ammo
		case FIELD_SCREW:
			//TODO: pick screw
		case FIELD_EMPTY:
			break;
		case FIELD_BOX:
		case FIELD_BOMB:
		case FIELD_SURPRISE:
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
			if (keys > 0)
			{
				keys--;
				if (sendChange)
				{
					change(newRobboPosDest);
				}
				break;
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
		robboX = newRobboX;
		if (maxPosX)
		{
			slide_to_map_pos_x = (robboX >= 9) ? 6 : (robboX < 6 ) ? 0 : 3;
		}
		robboY = newRobboY;
		if (robboY > 1)
		{
			slide_to_map_pos_y = MIN((((robboY - 2) >> 2) << 2), maxPosY);
		}
		return true;
	}
	return false;
}