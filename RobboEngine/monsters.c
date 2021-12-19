#include <stdint.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"




void monsterRL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_U;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_D;
	}
}

void monsterRR()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr+1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		x_next_tile = FIELD_MONSTER_RIGHT_D;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_U;
	}
}

void monsterRD()
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
}

void monsterRU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_R;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX;
			*chanegesPtr++ = iterY - 1;
		}
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_L;
	}
}

void monsterLL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_D;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_U;
	}
}

void monsterLR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr+1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		x_next_tile = FIELD_MONSTER_LEFT_U;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_D;
	}
}

void monsterLD()
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
}

void monsterLU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_L;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX;
			*chanegesPtr++ = iterY - 1;
		}
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_R;
	}
}