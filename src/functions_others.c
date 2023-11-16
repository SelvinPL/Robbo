#include <stdint.h>
#include <rand.h>
#include <stdbool.h>
#include <fields_definition.h>
#include <globals.h>
#include <changes.h>
#include <map.h>
#include <robbo_state.h>
#include <projectile_utils.h>
#include <sound_engine.h>

uint8_t transportForceField = false;

void forceField()
{
	if (!(animCounter & 1))
		return;
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_FORCE_FIELD_START)
	{
		transportForceField = true;
		*mapPtr = FIELD_EMPTY;
	}
	else
	{
		*newMap = FIELD_FORCE_FIELD;
		change(newMap);
		*mapPtr = FIELD_EMPTY;
	}
	uint8_t next = *MAP_RIGHT(mapPtr);
	if(next != FIELD_FORCE_FIELD)
	{
		change(mapPtr);
	}
}

void forceFieldEnd()
{
	if (!(animCounter & 1))
		return;
	if (transportForceField)
	{
		uint8_t* newMap = MAP_LEFT(mapPtr);
		*newMap = FIELD_FORCE_FIELD;
		change(newMap);
		transportForceField = false;
	}
}

void blinkOnOdd()
{
	change(mapPtr);
}

const uint8_t nextField[] =
{
	FIELD_EXPLOSION_ANIM2, FIELD_EXPLOSION_ANIM3, FIELD_EXPLOSION_ANIM4, FIELD_EXPLOSION_ANIM5, FIELD_EXPLOSION_ANIM6, FIELD_EXPLOSION_ANIM7, FIELD_EMPTY,
	FIELD_ROBBO_APEARS_ANIM2, FIELD_ROBBO_APEARS_ANIM3, FIELD_ROBBO_APEARS_ANIM4, FIELD_ROBBO_APEARS_ANIM5, FIELD_ROBBO,

	FIELD_SURPRISE_SHOOT_ANIM2, FIELD_SURPRISE_SHOOT_ANIM3, FIELD_SURPRISE_SHOOT_ANIM4, FIELD_SURPRISE_SHOOT_ANIM5, FIELD_SURPRISE_SHOOT_ANIM6, FIELD_SURPRISE_SHOOT_ANIM7,
	FIELD_SURPRISE_SHOOT_ANIM8, FIELD_SURPRISE_EXPLOSION,

	FIELD_EMPTY,
};

void next()
{
	if (!(animCounter & 1))
		return;
	*mapPtr = nextField[*mapPtr - FIELD_TYPES_NEXT_START];
	change(mapPtr);
}

const uint8_t lootTable[] =
{
	FIELD_EMPTY,			FIELD_EMPTY,			FIELD_SURPRISE,			FIELD_SURPRISE,
	FIELD_AMMO,				FIELD_AMMO,				FIELD_AMMO,				FIELD_AMMO,
	FIELD_KEY,				FIELD_KEY,				FIELD_KEY,				FIELD_SCREW,
	FIELD_SCREW,			FIELD_SCREW,			FIELD_SCREW,			FIELD_SCREW,
	FIELD_EYES,				FIELD_EYES,				FIELD_BOMB,				FIELD_LIFE,
	FIELD_LIFE,				FIELD_LIFE,				FIELD_LIFE,				FIELD_LIFE,
	FIELD_EXPLOSION_ANIM3,	FIELD_EXPLOSION_ANIM3,	FIELD_SHIP_BLINK1,		FIELD_ROTATING_GUN_RIGHT,
	FIELD_ROTATING_GUN_LEFT,FIELD_ROTATING_GUN_DOWN,FIELD_ROTATING_GUN_UP,	FIELD_BOX
};

void surpriseExplosion()
{
	//TODO: if 0 the super explosion
	*mapPtr = lootTable[rand() & 31];
	change(mapPtr);
}

void robboDragLeft()
{
	newRobboX = iterX;
	newRobboY = iterY;
	robboState.existsCounter = EXISTS_COUNTER_START;
	slideToRobbo();
	if(animCounter & 1)
	{
		change(mapPtr);
		return;
	}
	uint8_t* newMap = MAP_LEFT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_ROBBO_DRAG_LEFT;
		change(newMap);
		*mapPtr = FIELD_EMPTY;
	}
	else
	{
		*mapPtr = FIELD_EXPLOSION_ANIM3;
	}
	change(mapPtr);
}


void robboDragRight()
{
	newRobboX = iterX;
	newRobboY = iterY;
	robboState.existsCounter = EXISTS_COUNTER_START;
	slideToRobbo();
	if(animCounter & 1)
	{
		change(mapPtr);
		return;
	}
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = FIELD_ROBBO_DRAG_RIGHT | FIELD_TYPES_WAIT_FLAG;
		change(newMap);
		*mapPtr = FIELD_EMPTY;
		change(mapPtr);
		return;
	}
	else
	{
		*mapPtr = FIELD_EXPLOSION_ANIM3;
	}
	change(mapPtr);
}

void magnetLeft()
{
	uint8_t* current = mapPtr;
	uint8_t i = iterX;
	do
	{
		current--;
		if(((*current) & FIELD_TYPES_MAX) == FIELD_ROBBO)
		{
			*current = FIELD_ROBBO_DRAG_RIGHT | FIELD_TYPES_WAIT_FLAG;
			playSound(magnetSound);
			return;
		}
		if(*current != FIELD_EMPTY)
			return;
	} while(--i > 0);
}

void magnetRight()
{
	uint8_t* current = mapPtr;
	for(uint8_t i = iterX; i < 16 ; i++)
	{
		current++;
		if(((*current) & FIELD_TYPES_MAX) == FIELD_ROBBO)
		{
			*current = FIELD_ROBBO_DRAG_LEFT | FIELD_TYPES_WAIT_FLAG;
			playSound(magnetSound);
			return;
		}
		if(*current != FIELD_EMPTY)
			return;
	}
}

inline void inertBox(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag)
{
	projectileGeneral(newMap, newFiled, false, FIELD_EMPTY, FIELD_INERT_BOX, waitFlag, true);
}

void inertBoxLeft()
{
	if (!(animCounter & 1))
		return;
	inertBox(MAP_LEFT(mapPtr), FIELD_INERT_BOX_LEFT, false);
}

void inertBoxRight()
{
	if (!(animCounter & 1))
		return;
	inertBox(MAP_RIGHT(mapPtr), FIELD_INERT_BOX_RIGHT, true);
}

void inertBoxUp()
{
	if (!(animCounter & 1))
		return;
	inertBox(MAP_UP(mapPtr), FIELD_INERT_BOX_UP, false);
}

void inertBoxDown()
{
	if (!(animCounter & 1))
		return;
	inertBox(MAP_DOWN(mapPtr), FIELD_INERT_BOX_DOWN, true);
}

inline void teleportTo(uint8_t* spawnPlace)
{
	*spawnPlace = FIELD_ROBBO_APEARS_ANIM1;
	newRobboX = ((uint8_t)spawnPlace) & 0xf;
	newRobboY = (((uint8_t)spawnPlace) >> 4) | (((uint8_t)((uint16_t)spawnPlace >> 8)) << 4);
	robboState.teleporting = 0;
	robboState.teleportingState = 0;
	robboState.existsCounter = EXISTS_COUNTER_START;
	slideToRobbo();
}

inline uint8_t teleportDirection(directions direction)
{
	uint8_t* spawnPlace = mapPtr + directions_matrix[direction];
	if(*spawnPlace != FIELD_EMPTY)
		return false;
	teleportTo(spawnPlace);
	return true;
}

void none()
{

}

void explode()
{
	if((*mapPtr & FIELD_TYPES_MAX) != FIELD_EMPTY)
	{
		*mapPtr = FIELD_EXPLOSION_ANIM1 + (rand() & 3U);
			change(mapPtr);
	}
}

void teleport()
{
	if(robboState.teleporting)
	{
		robboState.existsCounter = EXISTS_COUNTER_START;
		if(robboState.teleportingState == 1 && robboState.teleportX == iterX && robboState.teleportY == iterY)
		{
			robboState.teleportingState = 2;
		}
		else if(robboState.teleportingState == 2)
		{
			if(robboState.teleporting == *mapPtr)
			{
				for(uint8_t direction = 0; direction < 4; direction++)
				{
					if(teleportDirection((robboState.direction + direction) % 4))
						break;
				}
			}
		}
	}
	if (animCounter & 1)
	{
		change(mapPtr);
	}
}