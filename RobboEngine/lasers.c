#include <stdint.h>
#include <gb/gb.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"

void missleHL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY  || *newMap == LASER_HORIZONTAL_RAY)
		{
			*newMap = HORIZONTAL_MISSLE_LEFT;
			*mapPtr = FIELD_EMPTY;
			if (doChanege)
			{
				*chanegesPtr++ = iterX - 1;
				*chanegesPtr++ = iterY;
			}
		}
		else if (*newMap != FIELD_EMPTY)
		{
			*mapPtr = FIELD_EXPLOSION3;
		}
		else
		{
			*mapPtr = FIELD_EMPTY;
		}
	}
}

void laserHeadRR()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			x_next_tile = LASER_HORIZONTAL_HEAD_RIGHT_RIGHT;
			*mapPtr = LASER_HORIZONTAL_RAY;
		}
		else
		{
			*mapPtr = HORIZONTAL_MISSLE_LEFT;
		}
	}
}

void expolosion3()
{
	if (animCounter & 1)
		*mapPtr = FIELD_EXPLOSION4;
}

void expolosion4()
{
	if (animCounter & 1)
		*mapPtr = FIELD_EMPTY;
}

void laserR()
{
	//if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && (DIV_REG < 18))
		{
			x_next_tile = LASER_HORIZONTAL_HEAD_RIGHT_RIGHT;
		}
	}
}

void gunL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && (DIV_REG < 18))
	{
		*newMap = HORIZONTAL_MISSLE_LEFT;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
}