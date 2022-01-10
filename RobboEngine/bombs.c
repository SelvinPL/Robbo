#include "bombs.h"
#include "globals.h"
#include "map.h"
#include "fields.h"
#include "changes.h"
#include "stdbool.h"
#include "platform.h"

bool bombExploding()
{
	if (!(animCounter & 1))
	{
#ifdef GAMEBOY
		rAUD4LEN = 0x00;
		rAUD4ENV = 0xf5;
		rAUD4POLY = 0x5d;
		rAUD4GO = 0x80;
#endif
		uint8_t* newMap = MAP_LEFT(MAP_UP(mapPtr));
		if (types[*newMap])
		{
			if (*newMap == FIELD_BOMB)
			{
				*newMap = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}
		newMap = MAP_RIGHT(newMap);
		if (types[*newMap])
		{
			if (*newMap == FIELD_BOMB)
			{
				*newMap = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*newMap = FIELD_EXPLOSION_ANIM2;
				change(newMap);
			}
		}
		newMap = MAP_RIGHT(newMap);
		if (types[*newMap])
		{
			if (*newMap == FIELD_BOMB)
			{
				*newMap = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*newMap = FIELD_EXPLOSION_ANIM1;
				change(newMap);
			}
		}

		newMap = MAP_LEFT(mapPtr);
		if (types[*newMap])
		{
			if (*newMap == FIELD_BOMB)
			{
				*newMap = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*newMap = FIELD_EXPLOSION_ANIM2;
				change(newMap);
			}
		}
		*mapPtr = FIELD_EXPLOSION_ANIM3;
		newMap = MAP_RIGHT(mapPtr);
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMap : *(currentYTilesPtr + 1);
		if (types[next])
		{
			if (next == FIELD_BOMB)
			{
				*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM2;
			}
		}

		newMap = MAP_LEFT(MAP_DOWN(mapPtr));
		next = *(nextYTilesPtr - 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr - 1);
		if (types[next])
		{
			if (next == FIELD_BOMB)
			{
				*(nextYTilesPtr - 1) = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*(nextYTilesPtr - 1) = FIELD_EXPLOSION_ANIM1;
			}
		}
		newMap = MAP_RIGHT(newMap);
		next = *nextYTilesPtr == FIELD_NONE ? *newMap : *nextYTilesPtr;
		if (types[next])
		{
			if (next == FIELD_BOMB)
			{
				*nextYTilesPtr = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM2;
			}
		}
		newMap = MAP_RIGHT(newMap);
		next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMap : *(nextYTilesPtr + 1);
		if (types[next])
		{
			if (next == FIELD_BOMB)
			{
				*(nextYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
			}
			else
			{
				*(nextYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			}
		}
		return true;
	}
	return false;
}