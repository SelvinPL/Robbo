#include <stdint.h>
#include <gb/gb.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include <rand.h>
#include "iteration.h"

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
			changeLeft();
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

void projectileU()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY || *newMap == FIELD_LASER_VERTICAL_RAY)
		{
			*newMap = FIELD_PROJECTILE_U;
			*mapPtr = FIELD_EMPTY;
			changeUp();
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION6;
		}
	}
}

void projectileD()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY || *newMap == FIELD_LASER_VERTICAL_RAY)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_D;
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
			changeLeft();
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

void laserBeamU()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_BEAM_U;
			*mapPtr = FIELD_LASER_VERTICAL_RAY;
			changeUp();
		}
		else
		{
			*mapPtr = FIELD_PROJECTILE_D;
		}
	}
}

void laserBeamD()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_BEAM_D;
			*mapPtr = FIELD_LASER_VERTICAL_RAY;
		}
		else
		{
			*mapPtr = FIELD_PROJECTILE_U;
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
		changeLeft();
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

void laserU()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_LASER_BEAM_U;
		changeUp();
	}
}

void laserD()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_LASER_BEAM_D;
	}
}

void gunL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_PROJECTILE_L;
		changeLeft();
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

void gunU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_PROJECTILE_U;
		changeUp();
	}
}

void gunD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_PROJECTILE_D;
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
			changeLeft();
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

void blasterHeadU()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BLASTER_HEAD_U;
			*mapPtr = FIELD_EXPLOSION2;
			changeUp();
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION2;
		}
	}
}

void blasterHeadD()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_BLASTER_HEAD_D;
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
		changeLeft();
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

void blasterU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_U;
		changeUp();
	}
}

void blasterD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_BLASTER_HEAD_D;
	}
}