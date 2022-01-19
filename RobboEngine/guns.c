#include "platform.h"
#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "projectile_utils.h"
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"
#include "bombs.h"

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
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
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
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
			*mapPtr = FIELD_EMPTY;
		}
		else if (next == FIELD_SURPRISE)
		{
			*(currentYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
			*mapPtr = FIELD_EMPTY;
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
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
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
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (next == FIELD_EMPTY || next == FIELD_PROJECTILE_VERTICAL)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
			*mapPtr = FIELD_EMPTY;
		}
		else if (next == FIELD_BOMB)
		{
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;
			*mapPtr = FIELD_EMPTY;
		}
		else if (next == FIELD_SURPRISE)
		{
			*nextYTilesPtr = FIELD_SURPRISE_SHOOT_ANIM1;
			*mapPtr = FIELD_EMPTY;
		}
		else
		{
			uint8_t type = types[next];
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
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_HORIZONTAL;
		}
		else if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_RIGHT;
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_RIGHT;
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
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
			*mapPtr = FIELD_PROJECTILE_LEFT;
		}
		else if (next == FIELD_SURPRISE)
		{
			*(currentYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
			*mapPtr = FIELD_PROJECTILE_LEFT;
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
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_DOWN;
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
			*mapPtr = FIELD_PROJECTILE_DOWN;
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
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (next == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_HEAD_DOWN;
			*mapPtr = FIELD_PROJECTILE_VERTICAL;
		}
		else if (next == FIELD_BOMB)
		{
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;
			*mapPtr = FIELD_PROJECTILE_UP;
		}
		else if (next == FIELD_SURPRISE)
		{
			*nextYTilesPtr = FIELD_SURPRISE_SHOOT_ANIM1;
			*mapPtr = FIELD_PROJECTILE_UP;
		}
		else
		{
			uint8_t type = types[next];
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
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
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
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_SURPRISE)
		{
			*(currentYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
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
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_SURPRISE)
		{
			*newMap = FIELD_SURPRISE_SHOOT_ANIM1;
			change(newMap);
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
	uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
	if (next != FIELD_PROJECTILE_VERTICAL && RND())
	{
		if (next == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_LASER_HEAD_DOWN;
		}
		else if (next == FIELD_BOMB)
		{
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_SURPRISE)
		{
			*nextYTilesPtr = FIELD_SURPRISE_SHOOT_ANIM1;
		}
		else
		{
			uint8_t type = types[next];
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
	shootLeft(RND(), mapPtr);
	return false;
}

bool gunRight()
{
	shootRight(RND(), mapPtr);
	return false;
}

bool gunUp()
{
	shootUp(RND(), mapPtr);
	return false;
}

bool gunDown()
{
	shootDown(RND(), mapPtr);
	return false;
}

bool blasterHeadLeft()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_EMPTY || (types[*newMap] & 1))
		{
			*newMap = FIELD_BLASTER_HEAD_LEFT;
			change(newMap);
		}
		*mapPtr = FIELD_EXPLOSION_ANIM2;
		return true;
	}
	return false;
}

bool blasterHeadRight()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_BOMB)
		{
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_EMPTY || (types[next] & 1))
		{
			*(currentYTilesPtr + 1) = FIELD_BLASTER_HEAD_RIGHT;
		}
		*mapPtr = FIELD_EXPLOSION_ANIM2;
		return true;
	}
	return false;
}

bool blasterHeadUp()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_EMPTY || (types[*newMap] & 1))
		{
			*newMap = FIELD_BLASTER_HEAD_UP;
			change(newMap);
		}
		*mapPtr = FIELD_EXPLOSION_ANIM2;
		return true;
	}
	return false;
}

bool blasterHeadDown()
{
	if (animCounter & 1)
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (next == FIELD_BOMB)
		{
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_EMPTY || (types[next] & 1))
		{
			*nextYTilesPtr = FIELD_BLASTER_HEAD_DOWN;
		}
		*mapPtr = FIELD_EXPLOSION_ANIM2;
		return true;
	}
	return false;
}


bool blasterLeft()
{
	if (RND())
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_EMPTY || (types[*newMap] & 1))
		{
			*newMap = FIELD_BLASTER_HEAD_LEFT;
			change(newMap);
		}
	}
	return false;
}

bool blasterRight()
{
	if (RND())
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_BOMB)
		{
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_EMPTY || (types[next] & 1))
		{
			*(currentYTilesPtr + 1) = FIELD_BLASTER_HEAD_RIGHT;
		}
	}
	return false;
}

bool blasterUp()
{
	if (RND())
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING;
			change(newMap);
		}
		else if (*newMap == FIELD_EMPTY || (types[*newMap] & 1))
		{
			*newMap = FIELD_BLASTER_HEAD_UP;
			change(newMap);
		}
	}
	return false;
}

bool blasterDown()
{
	if (RND())
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (next == FIELD_BOMB)
		{
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;
		}
		else if (next == FIELD_EMPTY || (types[next] & 1))
		{
			*nextYTilesPtr = FIELD_BLASTER_HEAD_DOWN;
		}
	}
	return false;
}

const uint8_t rotationClock[] =  
{
	FIELD_ROTATING_GUN_UP, 
	FIELD_ROTATING_GUN_DOWN,
	FIELD_ROTATING_GUN_RIGHT, 
	FIELD_ROTATING_GUN_LEFT,
};

const uint8_t rotationCounterClock[] =
{
	FIELD_ROTATING_GUN_DOWN,
	FIELD_ROTATING_GUN_UP,
	FIELD_ROTATING_GUN_LEFT,
	FIELD_ROTATING_GUN_RIGHT,
};

bool rotatingGun()
{
	if (animCounter == 5)
	{
		if ((animCounter & 3) && (rand() & 1))
		{
			const uint8_t* rotation = (rand() & 1) ? rotationClock : rotationCounterClock;
			*mapPtr = rotation[*mapPtr - FIELD_ROTATING_GUN_LEFT];
			return true;
		}
		else
		{
			switch (*mapPtr)
			{
			case FIELD_ROTATING_GUN_LEFT:
				shootLeft(rand() & 7, mapPtr);
				break;
			case FIELD_ROTATING_GUN_RIGHT:
				shootRight(rand() & 7, mapPtr);
				break;
			case FIELD_ROTATING_GUN_UP:
				shootUp(rand() & 7, mapPtr);
				break;
			case FIELD_ROTATING_GUN_DOWN:
				shootDown(rand() & 7, mapPtr);
				break;
			}
		}
	}
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
	shootUp(RND(), newMap);
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
	shootUp(RND(), newMap);
	return repaint;
}