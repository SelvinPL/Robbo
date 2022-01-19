#include "stdbool.h"
#include <stdint.h>
#include <rand.h>
#include "map.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"
#include "map.h"

#define RND() (((uint8_t)rand()) < 18)

bool leftHandLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_LEFT_HAND_DOWN;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_UP;
	}
	return true;
}

bool leftHandRight()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		*(currentYTilesPtr + 1) = FIELD_LEFT_HAND_UP;
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_DOWN;
	}
	return true;
}

bool leftHandUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_LEFT_HAND_LEFT;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_RIGHT;
	}
	return true;
}

bool leftHandDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_LEFT_HAND_RIGHT;
	}
	else
	{
		*mapPtr = FIELD_LEFT_HAND_LEFT;
	}
	return true;
}

bool rightHandLeft()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_RIGHT_HAND_UP;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_DOWN;
	}
	return true;
}

bool rightHandRight()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(currentYTilesPtr +1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		*(currentYTilesPtr + 1) = FIELD_RIGHT_HAND_DOWN;
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_UP;
	}
	return true;
}

bool rightHandUp()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_RIGHT_HAND_RIGHT;
		*mapPtr = FIELD_EMPTY;
		change(newMap);
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_LEFT;
	}
	return true;
}

bool rightHandDown()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_RIGHT_HAND_LEFT;
	}
	else
	{
		*mapPtr = FIELD_RIGHT_HAND_RIGHT;
	}
	return true;
}

bool batLeft()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_LEFT;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_BAT_RIGHT;
		}
		return true;
	}
	return false;
}

bool batRight()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(currentYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			*(currentYTilesPtr + 1) = FIELD_BAT_RIGHT;
		}
		else
		{
			*mapPtr = FIELD_BAT_LEFT;
		}
		return true;
	}
	return false;
}

bool batUp()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_UP;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
		}
		else
		{
			*mapPtr = FIELD_BAT_DOWN;
		}
		return true;
	}
	return false;
}

bool batDown()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*mapPtr = FIELD_EMPTY;
			*nextYTilesPtr = FIELD_BAT_DOWN;
		}
		else
		{
			*mapPtr = FIELD_BAT_UP;
		}
		return true;
	}
	return false;
}

bool batShootingLeft()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_BAT_SHOOTING_LEFT;
			*mapPtr = FIELD_EMPTY;
			change(newMap);
			if (RND())
			{
				uint8_t* newMapInner = MAP_DOWN(newMap);
				uint8_t next = *(nextYTilesPtr - 1) == FIELD_NONE ? *newMapInner : *(nextYTilesPtr - 1);
				if (next == FIELD_EMPTY)
				{
					*(nextYTilesPtr - 1) = FIELD_PROJECTILE_DOWN;
				}
				else if (next == FIELD_BOMB)
				{
					*(nextYTilesPtr - 1) = FIELD_BOMB_EXPLODING;
				}
				else if (next == FIELD_SURPRISE)
				{
					*(nextYTilesPtr - 1) = FIELD_SURPRISE_SHOOT_ANIM1;
				}
				else
				{
					uint8_t type = types[next];
					if (type & 1)
					{
						*(nextYTilesPtr - 1) = FIELD_EXPLOSION_ANIM1;
					}
				}
			}
			return true;
		}
		else
		{
			*mapPtr = FIELD_BAT_SHOOTING_RIGHT;
		}
	}
	if (RND())
	{
		uint8_t* newMapInner = MAP_DOWN(mapPtr);
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMapInner : *nextYTilesPtr;
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
	return true;
}

bool batShootingRight()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			*(currentYTilesPtr + 1) = FIELD_BAT_SHOOTING_RIGHT;
			if (RND())
			{
				uint8_t* newMapInner = MAP_DOWN(newMap);
				uint8_t next = *(nextYTilesPtr + 1) == FIELD_NONE ? *newMapInner : *(nextYTilesPtr + 1);
				if (next == FIELD_EMPTY)
				{
					*(nextYTilesPtr + 1) = FIELD_PROJECTILE_DOWN;
				}
				else if (next == FIELD_BOMB)
				{
					*(nextYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
				}
				else if (next == FIELD_SURPRISE)
				{
					*(nextYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
				}
				else
				{
					uint8_t type = types[next];
					if (type & 1)
					{
						*(nextYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
					}
				}
			}
			return true;
		}
		else
		{
			*mapPtr = FIELD_BAT_SHOOTING_LEFT;
		}
	}
	if (RND())
	{
		uint8_t* newMapInner = MAP_DOWN(mapPtr);
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMapInner : *nextYTilesPtr;
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
	return true;
}

bool eyes()
{
	return true;
}