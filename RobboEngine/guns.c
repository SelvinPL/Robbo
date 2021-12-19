#include <stdint.h>
#include <gb/gb.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"
#include <rand.h>

#define RND() (((uint8_t)rand()) < 18)

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
		else
		{
			*mapPtr = FIELD_EXPLOSION6;
		}
	}
}

void projectileR()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if ((*newMap == FIELD_EMPTY || *newMap == FIELD_LASER_HORIZONTAL_RAY) && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			nextXTile = FIELD_PROJECTILE_R;
			*mapPtr = FIELD_EMPTY;
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION6;
		}
	}
}

void laserBeamL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_BEAM_L;
			*mapPtr = FIELD_LASER_HORIZONTAL_RAY;
			if (doChanege)
			{
				*chanegesPtr++ = iterX - 1;
				*chanegesPtr++ = iterY;
			}
		}
		else
		{
			*mapPtr = FIELD_PROJECTILE_R;
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
			nextXTile = FIELD_LASER_BEAM_R;
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

void laserL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_LASER_BEAM_L;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
}

void laserR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_LASER_BEAM_R;
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

void gunR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_PROJECTILE_R;
	}
}

void blasterHeadL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BLASTER_HEAD_L;
			*mapPtr = FIELD_EXPLOSION2;
			if (doChanege)
			{
				*chanegesPtr++ = iterX - 1;
				*chanegesPtr++ = iterY;
			}
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION2;
		}
	}
}

void blasterHeadR()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			nextXTile = FIELD_BLASTER_HEAD_R;
			*mapPtr = FIELD_EXPLOSION2;
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION2;
		}
	}
}

void blasterL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_L;
		if (doChanege)
		{
			*chanegesPtr++ = iterX - 1;
			*chanegesPtr++ = iterY;
		}
	}
}

void blasterR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_BLASTER_HEAD_R;
	}
}