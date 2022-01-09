#include "platform.h"
#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"

#define RND() (((uint8_t)rand()) < 18)

bool projectileLeft()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY  || *newMap == FIELD_PROJECTILE_HORIZONTAL)
		{
			*newMap = FIELD_PROJECTILE_LEFT;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
				*mapPtr = FIELD_EMPTY;
			}
			else
				*mapPtr = FIELD_EXPLOSION_ANIM6;
		}
		return true;
	}
	return false;
}

bool projectileRight()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_EMPTY || next == FIELD_PROJECTILE_HORIZONTAL)
		{
			*(currentYTilesPtr + 1) = FIELD_PROJECTILE_RIGHT;
			*mapPtr = FIELD_EMPTY;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
				*mapPtr = FIELD_EMPTY;
			}
			else
				*mapPtr = FIELD_EXPLOSION_ANIM6;
		}
		return true;
	}
	return false;
}

bool projectileUp()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY || *newMap == FIELD_PROJECTILE_VERTICAL)
		{
			*newMap = FIELD_PROJECTILE_UP;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
				*mapPtr = FIELD_EMPTY;
			}
			else
				*mapPtr = FIELD_EXPLOSION_ANIM6;
		}
		return true;
	}
	return false;
}

bool projectileDown()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY || *newMap == FIELD_PROJECTILE_VERTICAL)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
			*mapPtr = FIELD_EMPTY;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
				*mapPtr = FIELD_EMPTY;
			}
			else
				*mapPtr = FIELD_EXPLOSION_ANIM6;
		}
		return true;
	}
	return false;
}

bool laserHeadLeft()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_HEAD_LEFT;
			*mapPtr = FIELD_PROJECTILE_HORIZONTAL;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
			*mapPtr = FIELD_PROJECTILE_RIGHT;
		}
		return true;
	}
	return false;
}

bool laserHeadRight()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_EMPTY)
		{
			*(currentYTilesPtr + 1) = FIELD_LASER_HEAD_RIGHT;
			*mapPtr = FIELD_PROJECTILE_HORIZONTAL;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			}
			*mapPtr = FIELD_PROJECTILE_LEFT;
		}
		return true;
	}
	return false;
}

bool laserHeadUp()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_HEAD_UP;
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_VERTICAL;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
			*mapPtr = FIELD_PROJECTILE_DOWN;
		}
		return true;
	}
	return false;
}

bool laserHeadDown()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_HEAD_DOWN;
			*mapPtr = FIELD_PROJECTILE_VERTICAL;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
			}
			*mapPtr = FIELD_PROJECTILE_UP;
		}
		return true;
	}
	return false;
}

bool laserLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap != FIELD_PROJECTILE_HORIZONTAL && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_HEAD_LEFT;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return false;
}

bool laserRight()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
	if (next != FIELD_PROJECTILE_HORIZONTAL && RND())
	{
		if (next == FIELD_EMPTY)
		{
			*(currentYTilesPtr + 1) = FIELD_LASER_HEAD_RIGHT;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return false;
}

bool laserUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap != FIELD_PROJECTILE_VERTICAL && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_LASER_HEAD_UP;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return false;
}

bool laserDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap != FIELD_PROJECTILE_VERTICAL && RND())
	{
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_HEAD_DOWN;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return false;
}

bool gunLeft()
{
	if (RND())
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_LEFT;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return false;
}

bool gunRight()
{
	if (RND())
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_EMPTY)
		{
			*(currentYTilesPtr + 1) = FIELD_PROJECTILE_RIGHT;
		}
		else if (next == FIELD_BOMB)
		{

		}
		else if (next == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[next];
			if (type & 1)
			{
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return false;
}

bool gunUp()
{
	if (RND())
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_UP;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return false;
}

bool gunDown()
{
	if (RND())
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
			}
		}
	}
	return false;
}

bool blasterHeadLeft()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BLASTER_HEAD_LEFT;
			*mapPtr = FIELD_EXPLOSION_ANIM2;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		return true;
	}
	return false;
}

bool blasterHeadRight()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
		{
			*(currentYTilesPtr + 1) = FIELD_BLASTER_HEAD_RIGHT;
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		return true;
	}
	return false;
}

bool blasterHeadUp()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BLASTER_HEAD_UP;
			*mapPtr = FIELD_EXPLOSION_ANIM2;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		return true;
	}
	return false;
}

bool blasterHeadDown()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_BLASTER_HEAD_DOWN;
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		else
		{
			*mapPtr = FIELD_EXPLOSION_ANIM2;
		}
		return true;
	}
	return false;
}


bool blasterLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_LEFT;
		change(newMap);
	}
	return false;
}

bool blasterRight()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE && RND())
	{
		*(currentYTilesPtr + 1) = FIELD_BLASTER_HEAD_RIGHT;
	}
	return false;
}

bool blasterUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*newMap = FIELD_BLASTER_HEAD_UP;
		change(newMap);
	}
	return false;
}

bool blasterDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_BLASTER_HEAD_DOWN;
	}
	return false;
}

bool rotatingGunLeft()
{
	return false;
}

bool rotatingGunRight()
{
	return false;
}

bool rotatingGunUp()
{
	return false;
}

bool rotatingGunDown()
{
	return false;
}

bool movableGunLeft()
{
	bool repaint = false;
	uint8_t* newMap;
	if (animCounter == 1 || animCounter == 5)
	{
		newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MOVABLE_GUN_LEFT;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
			repaint = true;
		}
		else
		{
			*mapPtr = FIELD_MOVABLE_GUN_RIGHT;
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
			*newMap = FIELD_PROJECTILE_UP;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return repaint;
}

bool movableGunRight()
{
	bool repaint = false;
	uint8_t* newMap;
	if (animCounter == 1 || animCounter == 5)
	{
		newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			*(currentYTilesPtr + 1) = FIELD_MOVABLE_GUN_RIGHT;
			repaint = true;
		}
		else
		{
			*mapPtr = FIELD_MOVABLE_GUN_LEFT;
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
			*newMap = FIELD_PROJECTILE_UP;
			change(newMap);
		}
		else if (*newMap == FIELD_BOMB)
		{

		}
		else if (*newMap == FIELD_SURPRISE)
		{

		}
		else
		{
			uint8_t type = types[*newMap];
			if (type & 1)
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
	}
	return repaint;
}