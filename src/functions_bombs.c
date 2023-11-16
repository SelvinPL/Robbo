#include <stdint.h>
#include <platform.h>
#include <map.h>
#include <fields_definition.h>
#include <changes.h>
#include <sound_engine.h>

#pragma bank 1

inline void checkNextField(uint8_t* newMap)
{
	if (fields_types[*newMap & FIELD_TYPES_MAX])
	{
		if (*newMap == FIELD_BOMB)
		{
			*newMap = FIELD_BOMB_EXPLODING | FIELD_TYPES_WAIT_FLAG;
		}
		else
		{
			*newMap = FIELD_EXPLOSION_ANIM1;
		}
		change(newMap);
	}
}

void bombExploding()
{
	playSound(explosionSound);
	*mapPtr = FIELD_EXPLOSION_ANIM3 | FIELD_TYPES_WAIT_FLAG;
	uint8_t* newMap = MAP_LEFT(MAP_UP(mapPtr));
	checkNextField(newMap);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap);
	newMap = MAP_DOWN(newMap);
	checkNextField(newMap);
	newMap = MAP_LEFT(MAP_LEFT(newMap));
	checkNextField(newMap);
	newMap = MAP_DOWN(newMap);
	checkNextField(newMap);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap);
	newMap = MAP_RIGHT(newMap);
	checkNextField(newMap);
}