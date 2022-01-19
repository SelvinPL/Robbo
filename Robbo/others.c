#include <stdint.h>
#include <rand.h>
#include "stdbool.h"
#include "fields.h"
#include "globals.h"
#include "changes.h"
#include "map.h"

bool transportForceField = false;

bool forceField()
{
	if (!(animCounter & 1))
	{
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
		return next != FIELD_FORCE_FIELD;
	}
	return false;
}

bool forceFieldEnd()
{
	if (!(animCounter & 1))
	{
		if (transportForceField)
		{
			uint8_t* newMap = MAP_LEFT(mapPtr);
			*newMap = FIELD_FORCE_FIELD;
			change(newMap);
			transportForceField = false;
		}
	}
	return false;
}

bool blinkOnOdd()
{
	return (animCounter & 1);
}

const uint8_t nextField[] =
{
	FIELD_EXPLOSION_ANIM2,
	FIELD_EXPLOSION_ANIM3,
	FIELD_EXPLOSION_ANIM4,
	FIELD_EXPLOSION_ANIM5,
	FIELD_EXPLOSION_ANIM6,
	FIELD_EXPLOSION_ANIM7,
	FIELD_EMPTY,

	FIELD_ROBBO_APEARS_ANIM2,
	FIELD_ROBBO_APEARS_ANIM3,
	FIELD_ROBBO_APEARS_ANIM4,
	FIELD_ROBBO_APEARS_ANIM5,
	FIELD_ROBBO,

	FIELD_SURPRISE_SHOOT_ANIM2,
	FIELD_SURPRISE_SHOOT_ANIM3,
	FIELD_SURPRISE_SHOOT_ANIM4,
	FIELD_SURPRISE_SHOOT_ANIM5,
	FIELD_SURPRISE_SHOOT_ANIM6,
	FIELD_SURPRISE_SHOOT_ANIM7,
	FIELD_SURPRISE_SHOOT_ANIM8,
	FIELD_SURPRISE_EXPLOSION,

	FIELD_EMPTY,

	FIELD_ROBBO_DRAG_ANIM2,
	FIELD_EXPLOSION_ANIM1,
};

bool next()
{
	if (animCounter & 1)
	{
		*mapPtr = nextField[*mapPtr - FIELD_TYPES_NEXT_START];
		return true;
	}
	return false;
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

bool surpriseExplosion()
{
	//TODO: if 0 the super explosion
	*mapPtr = lootTable[rand() & 31];
	return true;
}

//TODO: implement those

bool robboDragLeft()
{
	return false;
}

bool robboDragRight()
{
	return false;
}

bool ship()
{
	return false;
}

bool shipBlink1()
{
	return false;
}

bool shipBlink2()
{
	return false;
}

bool robboStart()
{
	return false;
}

bool magnetLeft()
{
	return false;
}

bool magnetRight()
{
	return false;
}

bool inertBoxLeft()
{
	return false;
}

bool inertBoxRight()
{
	return false;
}

bool inertBoxUp()
{
	return false;
}

bool inertBoxDown()
{
	return false;
}

bool teleport()
{
	return (animCounter & 1);
}