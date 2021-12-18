#include <stdint.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"




void monsterRL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = MOB_R_UP;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
	else
	{
		*mapPtr = MOB_R_DOWN;
	}
}

void monsterRR()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr+1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		x_next_tile = MOB_R_DOWN;
	}
	else
	{
		*mapPtr = MOB_R_UP;
	}
}

void monsterRD()
{

	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = MOB_R_LEFT;
	}
	else
	{
		*mapPtr = MOB_R_RIGHT;
	}
}

void monsterRU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = MOB_R_RIGHT;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX;
			*chanegesPtr++ = iterY - 1;
		}
	}
	else
	{
		*mapPtr = MOB_R_LEFT;
	}
}

void monsterLL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = MOB_L_DOWN;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
	else
	{
		*mapPtr = MOB_L_UP;
	}
}

void monsterLR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr+1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		x_next_tile = MOB_L_UP;
	}
	else
	{
		*mapPtr = MOB_L_DOWN;
	}
}

void monsterLD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = MOB_L_RIGHT;
	}
	else
	{
		*mapPtr = MOB_L_LEFT;
	}
}

void monsterLU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = MOB_L_LEFT;
		*mapPtr = FIELD_EMPTY;
		if (doChanege)
		{
			*chanegesPtr++ = iterX;
			*chanegesPtr++ = iterY - 1;
		}
	}
	else
	{
		*mapPtr = MOB_L_RIGHT;
	}
}