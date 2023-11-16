#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <fields_definition.h>
#include <changes.h>
#include <sound_engine.h>
#include <map.h>
#include <directions.h>

inline uint8_t projectileGeneral(uint8_t* newMap, uint8_t newFiled, uint8_t allow, uint8_t replaceIfEmpty, uint8_t replaceOnHit, uint8_t waitFlag, uint8_t changeCurrent)
{
	if (*newMap == FIELD_EMPTY || allow)
	{
		*newMap = waitFlag ? (newFiled | FIELD_TYPES_WAIT_FLAG) : newFiled;
		change(newMap);
		if(changeCurrent)
		{
			*mapPtr = replaceIfEmpty;
			change(mapPtr);
		}
		return 1;
	}
	else if (*newMap == FIELD_BOMB)
	{
		playSound(smallExplosionSound);
		*newMap = waitFlag ? (FIELD_BOMB_EXPLODING | FIELD_TYPES_WAIT_FLAG) : FIELD_BOMB_EXPLODING;
		change(newMap);
		if(changeCurrent)
		{
			*mapPtr = replaceOnHit | FIELD_TYPES_WAIT_FLAG;
		}
	}
	else if (*newMap == FIELD_SURPRISE)
	{
		playSound(smallExplosionSound);
		*newMap = waitFlag ? (FIELD_SURPRISE_SHOOT_ANIM1 | FIELD_TYPES_WAIT_FLAG) : FIELD_SURPRISE_SHOOT_ANIM1;
		change(newMap);
		if(changeCurrent)
		{
			*mapPtr = replaceOnHit;
		}
	}
	else
	{
		uint8_t type = fields_types[*newMap & FIELD_TYPES_MAX];
		if (type & 1)
		{
			playSound(smallExplosionSound);
			*newMap = waitFlag ? (FIELD_EXPLOSION_ANIM1 | FIELD_TYPES_WAIT_FLAG) : FIELD_EXPLOSION_ANIM1;
			change(newMap);
			
		}
		if(changeCurrent)
		{
			*mapPtr = replaceOnHit;
		}
		if(replaceOnHit == FIELD_EXPLOSION_ANIM6)
		{
			playSound(smallExplosionSound);
		}
	}
	if(changeCurrent)
	{
		change(mapPtr);
	}
	return 0;
}

inline void shootDirection(directions direction, uint8_t when, uint8_t* map)
{
	if(when)
	{
		if(projectileGeneral(map + directions_matrix[direction], FIELD_PROJECTILE_LEFT + direction, false, NULL, NULL, direction > direction_up, false))
			playSound(smallExplosionSound);
	}
}