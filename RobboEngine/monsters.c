#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"
#include "map.h"

#define RND() (((uint8_t)rand()) < 18)

bool monsterLL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_D;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_U;
	}
	return true;
}

bool monsterLR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		nextXTile = FIELD_MONSTER_LEFT_U;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_D;
	}
	return true;
}

bool monsterLU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_L;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_R;
	}
	return true;
}

bool monsterLD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_MONSTER_LEFT_R;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_L;
	}
	return true;
}

bool monsterRL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_U;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_D;
	}
	return true;
}

bool monsterRR()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr +1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		nextXTile = FIELD_MONSTER_RIGHT_D;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_U;
	}
	return true;
}

bool monsterRU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_R;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_L;
	}
	return true;
}

bool monsterRD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_MONSTER_RIGHT_L;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_R;
	}
	return true;
}

bool birdL()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_BIRD_L;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_R;
		}
		return true;
	}
	return false;
}

bool birdR()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			nextXTile = FIELD_MONSTER_BIRD_R;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_L;
		}
		return true;
	}
	return false;
}

bool birdU()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_BIRD_U;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_D;
		}
		return true;
	}
	return false;
}

bool birdD()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*mapPtr = FIELD_EMPTY;
			*nextYTilesPtr = FIELD_MONSTER_BIRD_D;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_U;
		}
		return true;
	}
	return false;
}

bool shootingL()
{
	uint8_t* newMap;
	if (!(animCounter & 1))
	{
		newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_SHOOTING_L;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_MONSTER_SHOOTING_R;
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
			*nextYTilesPtr = FIELD_PROJECTILE_D;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION1;
			}
		}
	}
	return true;
}

bool shootingR()
{
	uint8_t* newMap;
	uint8_t* shootPtr;
	if (!(animCounter & 1))
	{
		newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			nextXTile = FIELD_MONSTER_SHOOTING_R;
			shootPtr = nextYTilesPtr + 1;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_SHOOTING_L;
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
			*shootPtr = FIELD_PROJECTILE_D;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*shootPtr = FIELD_EXPLOSION1;
			}
		}
	}
	return true;
}

bool eyes()
{
	return true;
}