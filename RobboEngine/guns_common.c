#include <stdint.h>
#include <rand.h>
#include "globals.h"
#include "fields.h"
#include "changes.h"
#include "map.h"

#define RND() (((uint8_t)rand()) < 18)

inline bool gunLeftImpl(uint8_t* ptr)
{
	if (RND())
	{
		uint8_t* newMap = MAP_LEFT(ptr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_LEFT;
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

inline bool gunRightImpl(uint8_t* ptr)
{
	if (RND())
	{
		uint8_t* newMap = MAP_RIGHT(ptr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (next == FIELD_EMPTY)
		{
			*(currentYTilesPtr + 1) = FIELD_PROJECTILE_RIGHT;
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

inline bool gunUpImpl(uint8_t* ptr)
{
	if (RND())
	{
		uint8_t* newMap = MAP_UP(ptr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_PROJECTILE_UP;
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

inline bool gunDownImpl(uint8_t* ptr)
{
	if (RND())
	{
		uint8_t* newMap = MAP_DOWN(ptr);
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (next == FIELD_EMPTY)
		{
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
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