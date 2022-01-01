#include "platform.h"
#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"

#define RND() (((uint8_t)rand()) < 18)

bool projectileL()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY  || *newMap == FIELD_LASER_HORIZONTAL_RAY)
		{
			*newMap = FIELD_PROJECTILE_L;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
				*mapPtr = FIELD_EMPTY;
			}
			else
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
		uint8_t next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr + 1);
		if (next == FIELD_EMPTY || next == FIELD_LASER_HORIZONTAL_RAY)
		{
			nextXTile = FIELD_PROJECTILE_R;
			*mapPtr = FIELD_EMPTY;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				nextXTile = FIELD_EXPLOSION1;
				*mapPtr = FIELD_EMPTY;
			}
			else
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
			change(newMap);
			*mapPtr = FIELD_EMPTY;
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
				*mapPtr = FIELD_EMPTY;
			}
			else
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
				*mapPtr = FIELD_EMPTY;
			}
			else
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
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
		uint8_t next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr + 1);
		if (next == FIELD_EMPTY)
		{
			nextXTile = FIELD_LASER_BEAM_R;
			*mapPtr = FIELD_LASER_HORIZONTAL_RAY;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				nextXTile = FIELD_EXPLOSION1;
			}
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
			change(newMap);
			*mapPtr = FIELD_LASER_VERTICAL_RAY;
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
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
	if (*newMap != FIELD_LASER_HORIZONTAL_RAY && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_BEAM_L;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return false;
}

bool laserR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	uint8_t next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr + 1);
	if (next != FIELD_LASER_HORIZONTAL_RAY && RND())
	{
		if (next == FIELD_EMPTY)
		{
			nextXTile = FIELD_LASER_BEAM_R;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				nextXTile = FIELD_EXPLOSION1;
			}
		}
	}
	return false;
}

bool laserU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap != FIELD_LASER_VERTICAL_RAY && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_BEAM_U;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return false;
}

bool laserD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap != FIELD_LASER_VERTICAL_RAY && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_BEAM_D;
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
	return false;
}

bool gunL()
{
	if (RND())
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_L;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return false;
}

bool gunR()
{
	if (RND())
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr + 1);
		if (next == FIELD_EMPTY)
		{
			nextXTile = FIELD_PROJECTILE_R;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SUPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				nextXTile = FIELD_EXPLOSION1;
			}
		}
	}
	return false;
}

bool gunU()
{
	if (RND())
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_U;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return false;
}

bool gunD()
{
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
			change(newMap);
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
			change(newMap);
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
		change(newMap);
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
		change(newMap);
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

bool rotatingGunL()
{
	return false;
}

bool rotatingGunR()
{
	return false;
}

bool rotatingGunU()
{
	return false;
}

bool rotatingGunD()
{
	return false;
}

bool movableGunL()
{
	bool repaint = false;
	uint8_t* newMap;
	if (animCounter == 1 || animCounter == 5)
	{
		newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MOVABLE_GUN_L;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
			repaint = true;
		}
		else
		{
			*mapPtr = FIELD_MOVABLE_GUN_R;
			newMap = mapPtr;
		}
	}
	else
	{
		newMap = mapPtr;
	}
	if (RND())
	{
		newMap = MAP_UP(newMap);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_U;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return repaint;
}

bool movableGunR()
{
	bool repaint = false;
	uint8_t* newMap;
	if (animCounter == 1 || animCounter == 5)
	{
		newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			nextXTile = FIELD_MOVABLE_GUN_R;
			repaint = true;
		}
		else
		{
			*mapPtr = FIELD_MOVABLE_GUN_L;
			newMap = mapPtr;
		}
	}
	else
	{
		newMap = mapPtr;
	}
	if (RND())
	{
		newMap = MAP_UP(newMap);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_U;
			change(newMap);
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
				*newMap = FIELD_EXPLOSION1;
				change(newMap);
			}
		}
	}
	return repaint;
}