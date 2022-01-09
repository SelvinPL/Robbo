#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"
#include "map.h"

#define RND() (((uint8_t)rand()) < 18)

bool leftHandLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_LEFT_HAND_DOWN;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_UP;
	}
	return true;
}

bool leftHandRight()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		*(currentYTilesPtr + 1) = FIELD_LEFT_HAND_UP;
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_DOWN;
	}
	return true;
}

bool leftHandUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_LEFT_HAND_LEFT;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_RIGHT;
	}
	return true;
}

bool leftHandDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_LEFT_HAND_RIGHT;
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_LEFT;
	}
	return true;
}

bool rightHandLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_RIGHT_HAND_UP;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_DOWN;
	}
	return true;
}

bool rightHandRight()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr +1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		*(currentYTilesPtr + 1) = FIELD_RIGHT_HAND_DOWN;
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_UP;
	}
	return true;
}

bool rightHandUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_RIGHT_HAND_RIGHT;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_LEFT;
	}
	return true;
}

bool rightHandDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_RIGHT_HAND_LEFT;
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_RIGHT;
	}
	return true;
}

bool batLeft()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_LEFT;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_BAT_RIGHT;
		}
		return true;
	}
	return false;
}

bool batRight()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			*(currentYTilesPtr + 1) = FIELD_BAT_RIGHT;
		}
		else
		{
			*mapPtr = FIELD_BAT_LEFT;
		}
		return true;
	}
	return false;
}

bool batUp()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_UP;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_BAT_DOWN;
		}
		return true;
	}
	return false;
}

bool batDown()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*mapPtr = FIELD_EMPTY;
			*nextYTilesPtr = FIELD_BAT_DOWN;
		}
		else
		{
			*mapPtr = FIELD_BAT_UP;
		}
		return true;
	}
	return false;
}

bool batShootingLeft()
{
	uint8_t* newMap;
	if (!(animCounter & 1))
	{
		newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_SHOOTING_LEFT;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_BAT_SHOOTING_RIGHT;
			newMap = mapPtr;
		}
	}
	else
	{
		newMap = mapPtr;
	}
	if (RND())
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return true;
}

bool batShootingRight()
{
	uint8_t* newMap;
	uint8_t* shootPtr;
	if (!(animCounter & 1))
	{
		newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			*(currentYTilesPtr + 1) = FIELD_BAT_SHOOTING_RIGHT;
			shootPtr = nextYTilesPtr + 1;
		}
		else
		{
			*mapPtr = FIELD_BAT_SHOOTING_LEFT;
			newMap = mapPtr;
			shootPtr = nextYTilesPtr;
		}
	}
	else
	{ 
		newMap = mapPtr;
		shootPtr = nextYTilesPtr;
	}
	if (RND())
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*shootPtr = FIELD_PROJECTILE_DOWN;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*shootPtr = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return true;
}

bool eyes()
{
	return true;
}