#include <stdint.h>
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