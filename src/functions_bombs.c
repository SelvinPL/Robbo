#include <stdint.h>
#include <platform.h>
#include <map.h>
#include <fields_definition.h>
#include <changes.h>
#include <sound_engine.h>

#pragma bank 1

inline void checkNextField(uint8_t* newMap, uint8_t explosionType)
{
	if (fields_types[*newMap & FIELD_TYPES_MAX])
	{
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING | FIELD_TYPES_WAIT_FLAG;
		}
		else
		{
			*newMap = explosionType;
		}
		change(newMap);
	}
}

void bombExploding()
{
	playSound(explosionSound);
	*mapPtr = FIELD_EXPLOSION_ANIM3 | FIELD_TYPES_WAIT_FLAG;
	uint8_t* newMap = MAP_LEFT(MAP_UP(mapPtr));
	checkNextField(newMap, FIELD_EXPLOSION_ANIM1 | FIELD_TYPES_WAIT_FLAG);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM2 | FIELD_TYPES_WAIT_FLAG);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM1 | FIELD_TYPES_WAIT_FLAG);
	newMap = MAP_DOWN(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM2);
	newMap = MAP_LEFT(MAP_LEFT(newMap));
	checkNextField(newMap, FIELD_EXPLOSION_ANIM2 | FIELD_TYPES_WAIT_FLAG);
	newMap = MAP_DOWN(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM1);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM2);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap, FIELD_EXPLOSION_ANIM1);
}