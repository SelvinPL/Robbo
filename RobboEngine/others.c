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
		if (*newMap == FIELD_FORCEFIELD_START)
		{
			transportForceField = true;
			*mapPtr = FIELD_EMPTY;
		}
		else
		{
			*newMap = FIELD_FORCEFIELD;
			change(newMap);
			*mapPtr = FIELD_EMPTY;
		}
		uint8_t next = *MAP_RIGHT(mapPtr);
		return next != FIELD_FORCEFIELD;
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
			*newMap = FIELD_FORCEFIELD;
			change(newMap);
			transportForceField = false;
		}
	}
	return false;
}