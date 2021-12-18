#include <stdint.h>
#include <gb/gb.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"

void laserHeadRL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == LASER_HORIZONTAL_RAY)
		{
			*newMap = LASER_HORIZONTAL_HEAD_RIGHT_LEFT;
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
		if (*newMap == FIELD_EMPTY)
		{
			x_next_tile = LASER_HORIZONTAL_HEAD_RIGHT_RIGHT;
			*mapPtr = LASER_HORIZONTAL_RAY;
		}
		else
		{
			*mapPtr = LASER_HORIZONTAL_HEAD_RIGHT_LEFT;
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
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && DIV_REG < 0x06)
	{
		x_next_tile = LASER_HORIZONTAL_HEAD_RIGHT_RIGHT;
	}
}