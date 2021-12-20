#include <stdint.h>
#include "map.h"
#include "fields.h"
#include "hi_ram_globals.h"
#include <rand.h>
#include "iteration.h"

#define RND() (((uint8_t)rand()) < 18)

void monsterLL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_D;
		*mapPtr = FIELD_EMPTY;
		changeLeft();
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_U;
	}
}

void monsterLR()
{
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		nextXTile = FIELD_MONSTER_LEFT_U;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_D;
	}
}

void monsterLU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_LEFT_L;
		*mapPtr = FIELD_EMPTY;
		changeUp();
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_R;
	}
}

void monsterLD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_MONSTER_LEFT_R;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_LEFT_L;
	}
}

void monsterRL()
{
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_U;
		*mapPtr = FIELD_EMPTY;
		changeLeft();
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_D;
	}
}

void monsterRR()
{

	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY && *(nextYTilesPtr+1) == FIELD_NONE)
	{
		*mapPtr = FIELD_EMPTY;
		nextXTile = FIELD_MONSTER_RIGHT_D;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_U;
	}
}

void monsterRU()
{
	uint8_t* newMap = MAP_UP(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_MONSTER_RIGHT_R;
		*mapPtr = FIELD_EMPTY;
		changeUp();
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_L;
	}
}

void monsterRD()
{
	uint8_t* newMap = MAP_DOWN(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*mapPtr = FIELD_EMPTY;
		*nextYTilesPtr = FIELD_MONSTER_RIGHT_L;
	}
	else
	{
		*mapPtr = FIELD_MONSTER_RIGHT_R;
	}
}

void birdL()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_BIRD_L;
			*mapPtr = FIELD_EMPTY;
			changeLeft();
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_R;
		}
	}
}

void birdR()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			nextXTile = FIELD_MONSTER_BIRD_R;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_L;
		}
	}
}

void birdU()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_UP(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_BIRD_U;
			*mapPtr = FIELD_EMPTY;
			changeUp();
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_D;
		}
	}
}

void birdD()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_DOWN(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*mapPtr = FIELD_EMPTY;
			*nextYTilesPtr = FIELD_MONSTER_BIRD_D;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_BIRD_U;
		}
	}
}

void shootingL()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		if (*newMap == FIELD_EMPTY)
		{
			*newMap = FIELD_MONSTER_SHOOTING_L;
			*mapPtr = FIELD_EMPTY;
			changeLeft();
		}
		else
		{
			*mapPtr = FIELD_MONSTER_SHOOTING_R;
		}
	}
	if (*MAP_DOWN(mapPtr) == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_PROJECTILE_D;
	}
}

void shootingR()
{
	if (!(animCounter & 1))
	{
		uint8_t* newMap = MAP_RIGHT(mapPtr);
		if (*newMap == FIELD_EMPTY && *(nextYTilesPtr + 1) == FIELD_NONE)
		{
			*mapPtr = FIELD_EMPTY;
			nextXTile = FIELD_MONSTER_SHOOTING_R;
		}
		else
		{
			*mapPtr = FIELD_MONSTER_SHOOTING_L;
		}
	}
	if (*MAP_DOWN(mapPtr) == FIELD_EMPTY && RND())
	{
		*nextYTilesPtr = FIELD_PROJECTILE_D;
	}
}

void eyes()
{

}