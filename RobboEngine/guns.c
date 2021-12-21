#include "platform.h"
#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "iteration.h"


#define RND() (((uint8_t)rand()) < 18)

bool projectileL()
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
		return true;
	}
	return false;
}

bool projectileR()
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
		return true;
	}
	return false;
}

bool projectileU()
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
		return true;
	}
	return false;
}

bool projectileD()
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
		return true;
	}
	return false;
}

bool laserBeamL()
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
		return true;
	}
	return false;
}

bool laserBeamR()
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
		return true;
	}
	return false;
}

bool laserBeamU()
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
		return true;
	}
	return false;
}

bool laserBeamD()
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
		return true;
	}
	return false;
}

bool expolosion()
{
	if (animCounter & 1)
	{
		if (*mapPtr == FIELD_EXPLOSION7)
			*mapPtr = FIELD_EMPTY;
		else
			(*mapPtr)++;
		return true;
	}
	return false;
}

bool laserL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_LASER_BEAM_L;
		changeLeft();
	}
	return false;
}

bool laserR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_LASER_BEAM_R;
	}
	return false;
}

bool laserU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_LASER_BEAM_U;
		changeUp();
	}
	return false;
}

bool laserD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_LASER_BEAM_D;
	}
	return false;
}

bool gunL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_PROJECTILE_L;
		changeLeft();
	}
	return false;
}

bool gunR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_PROJECTILE_R;
	}
	return false;
}

bool gunU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_PROJECTILE_U;
		changeUp();
	}
	return false;
}

bool gunD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_PROJECTILE_D;
	}
	return false;
}

bool blasterHeadL()
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
		return true;
	}
	return false;
}

bool blasterHeadR()
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
		return true;
	}
	return false;
}

bool blasterHeadU()
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
		return true;
	}
	return false;
}

bool blasterHeadD()
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
		return true;
	}
	return false;
}


bool blasterL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_L;
		changeLeft();
	}
	return false;
}

bool blasterR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE && RND())
	{
		nextXTile = FIELD_BLASTER_HEAD_R;
	}
	return false;
}

bool blasterU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_U;
		changeUp();
	}
	return false;
}

bool blasterD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_BLASTER_HEAD_D;
	}
	return false;
}