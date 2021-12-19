#include <stdint.h>
#include <gb/gb.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"
#include <rand.h>

void projectileL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY  || *newMap == FIELD_LASER_HORIZONTAL_RAY)
		{
			*newMap = FIELD_PROJECTILE_L;
			*mapPtr = FIELD_EMPTY;
			if (doChanege)
			{
				*chanegesPtr++ = iterX - 1;
				*chanegesPtr++ = iterY;
			}
		}
		else if (*newMap != FIELD_EMPTY)
		{
			*mapPtr = FIELD_EXPLOSION6;
		}
		else
		{
			*mapPtr = FIELD_EMPTY;
		}
	}
}

void laserBeamR()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			x_next_tile = FIELD_LASER_BEAM_R;
			*mapPtr = FIELD_LASER_HORIZONTAL_RAY;
		}
		else
		{
			*mapPtr = FIELD_PROJECTILE_L;
		}
	}
}

void expolosion()
{
	if (animCounter & 1)
	{
		if (*mapPtr == FIELD_EXPLOSION7)
			*mapPtr = FIELD_EMPTY;
		else
			(*mapPtr)++;
	}
}

#define RND() (((uint8_t)rand()) < 18)

void laserR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		x_next_tile = FIELD_LASER_BEAM_R;
	}
}

void gunL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_PROJECTILE_L;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
}