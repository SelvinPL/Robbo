#include "globals.h"
#include "fields.h"
#include "map.h"
#include "changes.h"
#include "sound_engine.h"

void shootLeft(uint8_t* ptr)
{
	uint8_t* newMapInner = MAP_LEFT(ptr);
	if (*newMapInner == FIELD_EMPTY)
	{
		*newMapInner = FIELD_PROJECTILE_LEFT;
		change(newMapInner);
		return;
	}
	else if (*newMapInner == FIELD_BOMB)
	{
		*newMapInner = FIELD_BOMB_EXPLODING;
		change(newMapInner);
		return;
	}
	else if (*newMapInner == FIELD_SURPRISE)
	{
		*newMapInner = FIELD_SURPRISE_SHOOT_ANIM1;
		change(newMapInner);
		return;
	}
	else
	{
		uint8_t type = types[*newMapInner];
		if (type & 1)
		{
			*newMapInner = FIELD_EXPLOSION_ANIM1;
			change(newMapInner);
			return;
		}
	}
}

void shootRight(uint8_t* ptr)
{
	uint8_t* newMapInner = MAP_RIGHT(ptr);
	uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMapInner : *(currentYTilesPtr + 1);
	if (next == FIELD_EMPTY)
	{
		*(currentYTilesPtr + 1) = FIELD_PROJECTILE_RIGHT;
		return;
	}
	else if (next == FIELD_BOMB)
	{
		*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
		return;
	}
	else if (next == FIELD_SURPRISE)
	{
		*(currentYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
		return;
	}
	else
	{
		uint8_t type = types[next];
		if (type & 1)
		{
			*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			return;
		}
	}
}

void shootUp(uint8_t* ptr)
{
	uint8_t* newMapInner = MAP_UP(ptr);
	if (*newMapInner == FIELD_EMPTY)
	{
		*newMapInner = FIELD_PROJECTILE_UP;
		change(newMapInner);
		return;
	}
	else if (*newMapInner == FIELD_BOMB)
	{
		*newMapInner = FIELD_BOMB_EXPLODING;
		change(newMapInner);
		return;
	}
	else if (*newMapInner == FIELD_SURPRISE)
	{
		*newMapInner = FIELD_SURPRISE_SHOOT_ANIM1;
		change(newMapInner);
		return;
	}
	else
	{
		uint8_t type = types[*newMapInner];
		if (type & 1)
		{
			*newMapInner = FIELD_EXPLOSION_ANIM1;
			change(newMapInner);
			return;
		}
	}
}

void shootDown(uint8_t* ptr)
{
	uint8_t* newMapInner = MAP_DOWN(ptr);
	uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMapInner : *nextYTilesPtr;
	if (next == FIELD_EMPTY)
	{
		*nextYTilesPtr = FIELD_PROJECTILE_DOWN;
		return;
	}
	else if (next == FIELD_BOMB)
	{
		*nextYTilesPtr = FIELD_BOMB_EXPLODING;
		return;
	}
	else if (next == FIELD_SURPRISE)
	{
		*nextYTilesPtr = FIELD_SURPRISE_SHOOT_ANIM1;
		return;
	}
	else
	{
		uint8_t type = types[next];
		if (type & 1)
		{
			*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;
			return;
		}
	}
}