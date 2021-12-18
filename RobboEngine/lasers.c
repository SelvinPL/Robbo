#include <stdint.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"

void laserHeadRL()
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
	else if (*newMap == LASER_RIGHT)
	{
		*mapPtr = LASER_HORIZONTAL_HEAD_RIGHT_RIGHT;
	}
	else
	{
		*mapPtr = FIELD_EMPTY;
	}

}

void laserHeadRR()
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