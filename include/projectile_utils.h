#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <fields.h>
#include <map.h>
#include <changes.h>
#include <sound_engine.h>

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
		uint8_t type = types[*newMap & FIELD_TYPES_MAX];
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

inline void shoot(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag)
{
	if(projectileGeneral(newMap, newFiled, false, NULL, NULL, waitFlag, false))
		playSound(smallExplosionSound);
}

inline void shootLeft(uint8_t when, uint8_t* map)
{
	if(when)
	{
		shoot(MAP_LEFT(map), FIELD_PROJECTILE_LEFT, false);
	}
}

inline void shootRight(uint8_t when, uint8_t* map)
{
	if(when)
	{
		shoot(MAP_RIGHT(map), FIELD_PROJECTILE_RIGHT, true);
	}
}

inline void shootUp(uint8_t when, uint8_t* map)
{
	if(when)
	{
		shoot(MAP_UP(map), FIELD_PROJECTILE_UP, false);
	}
}

inline void shootDown(uint8_t when, uint8_t* map)
{
	if(when)
	{
		shoot(MAP_DOWN(map), FIELD_PROJECTILE_DOWN, true);
	}
}