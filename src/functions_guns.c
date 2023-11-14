#include <platform.h>
#include <stdint.h>
#include <rand.h>
#include <stdbool.h>
#include <projectile_utils.h>
#include <map.h>
#include <fields.h>
#include <globals.h>
#include <changes.h>
#include <functions_guns.h>

#pragma bank 1

#define RND() (((uint8_t)rand()) < 18)

inline void projectile(uint8_t* newMap, uint8_t newFiled, uint8_t allowPice, uint8_t waitFlag)
{
	projectileGeneral(newMap, newFiled, *newMap == allowPice, FIELD_EMPTY, FIELD_EXPLOSION_ANIM6, waitFlag, true);
}

void projectileLeft()
{
	if (!(animCounter & 1))
		return;
	projectile(MAP_LEFT(mapPtr), FIELD_PROJECTILE_LEFT, FIELD_PROJECTILE_HORIZONTAL, false);
}

void projectileRight()
{
	if (!(animCounter & 1))
		return;
	projectile(MAP_RIGHT(mapPtr), FIELD_PROJECTILE_RIGHT, FIELD_PROJECTILE_HORIZONTAL, true);
}

void projectileUp()
{
	if (!(animCounter & 1))
		return;
	projectile(MAP_UP(mapPtr), FIELD_PROJECTILE_UP, FIELD_PROJECTILE_VERTICAL, false);
}

void projectileDown()
{
	if (!(animCounter & 1))
		return;
	projectile(MAP_DOWN(mapPtr), FIELD_PROJECTILE_DOWN, FIELD_PROJECTILE_VERTICAL, true);
}

inline void laserHead(uint8_t* newMap, uint8_t newFiled, uint8_t replaceIfEmpty, uint8_t replaceOnHit, uint8_t waitFlag)
{
	projectileGeneral(newMap, newFiled, false, replaceIfEmpty, replaceOnHit, waitFlag, true);
}

void laserHeadLeft()
{
	if (!(animCounter & 1))
		return;
	laserHead(MAP_LEFT(mapPtr), FIELD_LASER_HEAD_LEFT, FIELD_PROJECTILE_HORIZONTAL, FIELD_PROJECTILE_RIGHT | FIELD_TYPES_WAIT_FLAG, false);
}


void laserHeadRight()
{
	if (!(animCounter & 1))
		return;
	laserHead(MAP_RIGHT(mapPtr), FIELD_LASER_HEAD_RIGHT, FIELD_PROJECTILE_HORIZONTAL, FIELD_PROJECTILE_LEFT, true);
}

void laserHeadUp()
{
	if (!(animCounter & 1))
		return;
	laserHead(MAP_UP(mapPtr), FIELD_LASER_HEAD_UP, FIELD_PROJECTILE_VERTICAL, FIELD_PROJECTILE_DOWN | FIELD_TYPES_WAIT_FLAG, false);
}

void laserHeadDown()
{
	if (!(animCounter & 1))
		return;
	laserHead(MAP_DOWN(mapPtr), FIELD_LASER_HEAD_DOWN, FIELD_PROJECTILE_VERTICAL, FIELD_PROJECTILE_UP, true);
}

inline void laserShoot(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag)
{
	if (!(animCounter & 1))
		return;
	projectileGeneral(newMap, newFiled, false, NULL, NULL, waitFlag, false);
}

void laserLeft()
{
	if(RND())
		laserShoot(MAP_LEFT(mapPtr), FIELD_LASER_HEAD_LEFT, false);
}

void laserRight()
{
	if(RND())
		laserShoot(MAP_RIGHT(mapPtr), FIELD_LASER_HEAD_RIGHT, true);
}

void laserUp()
{
	if(RND())
		laserShoot(MAP_UP(mapPtr), FIELD_LASER_HEAD_UP, false);
}

void laserDown()
{
	if(RND())
		laserShoot(MAP_DOWN(mapPtr), FIELD_LASER_HEAD_DOWN, true);
}

void gunLeft()
{
	shootLeft(RND(), mapPtr);
}

void gunRight()
{
	shootRight(RND(), mapPtr);
}

void gunUp()
{
	shootUp(RND(), mapPtr);
}

void gunDown()
{
	shootDown(RND(), mapPtr);
}

inline void blasterGeneral(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag, uint8_t changeCurrent)
{
	if (*newMap == FIELD_BOMB)
	{
		*newMap = waitFlag ? (newFiled | FIELD_BOMB_EXPLODING) : newFiled;
		change(newMap);
	}
	else if (*newMap == FIELD_EMPTY || (types[*newMap & FIELD_TYPES_MAX] & 1))
	{
		*newMap = waitFlag ? (newFiled | FIELD_TYPES_WAIT_FLAG) : newFiled;
		change(newMap);
	}
	if(changeCurrent)
	{
		*mapPtr = FIELD_EXPLOSION_ANIM2;
		change(mapPtr);
	}
}

inline void blasterHead(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag)
{
	blasterGeneral(newMap, newFiled, waitFlag, true);
}

void blasterHeadLeft()
{
	if (!(animCounter & 1))
		return;
	blasterHead(MAP_LEFT(mapPtr), FIELD_BLASTER_HEAD_LEFT, false);
}

void blasterHeadRight()
{
	if (!(animCounter & 1))
		return;
	blasterHead(MAP_RIGHT(mapPtr), FIELD_BLASTER_HEAD_RIGHT, true);
}

void blasterHeadUp()
{
	if (!(animCounter & 1))
		return;
	blasterHead(MAP_UP(mapPtr), FIELD_BLASTER_HEAD_UP, false);
}


void blasterHeadDown()
{
	if (!(animCounter & 1))
		return;
	blasterHead(MAP_DOWN(mapPtr), FIELD_BLASTER_HEAD_DOWN, true);
}

inline void blaster(uint8_t* newMap, uint8_t newFiled, uint8_t waitFlag)
{
	if(*newMap < FIELD_EXPLOSION_ANIM1 || *newMap > FIELD_EXPLOSION_ANIM7)
		blasterGeneral(newMap, newFiled, waitFlag, false);
}

void blasterLeft()
{
	if (RND())
	{
		blaster(MAP_LEFT(mapPtr), FIELD_BLASTER_HEAD_LEFT, false);
	}
}

void blasterRight()
{
	if (RND())
	{
		blaster(MAP_RIGHT(mapPtr), FIELD_BLASTER_HEAD_RIGHT, true);
	}
}

void blasterUp()
{
	if (RND())
	{
		blaster(MAP_UP(mapPtr), FIELD_BLASTER_HEAD_UP, false);
	}
}

void blasterDown()
{
	if (RND())
	{
		blaster(MAP_DOWN(mapPtr), FIELD_BLASTER_HEAD_DOWN, true);
	}
}

const uint8_t const rotationClock[] =  
{
	FIELD_ROTATING_GUN_UP, 
	FIELD_ROTATING_GUN_DOWN,
	FIELD_ROTATING_GUN_RIGHT, 
	FIELD_ROTATING_GUN_LEFT,
};

const uint8_t const rotationCounterClock[] =
{
	FIELD_ROTATING_GUN_DOWN,
	FIELD_ROTATING_GUN_UP,
	FIELD_ROTATING_GUN_LEFT,
	FIELD_ROTATING_GUN_RIGHT,
};

const int8_t const shootRotatingGunPosition[] =
{
	-1,
	1,
	-16,
	16,
};

void rotatingGun()
{
	if (animCounter == 5)
	{
		if ((animCounter & 3) && (rand() & 1))
		{
			const uint8_t* rotation = (rand() & 1) ? rotationClock : rotationCounterClock;
			*mapPtr = rotation[*mapPtr - FIELD_ROTATING_GUN_LEFT];
			change(mapPtr);
			return;
		}
		else
		{
			if(rand() & 7)
			{
				uint8_t index = (*mapPtr) - FIELD_ROTATING_GUN_LEFT;
				shoot(mapPtr + shootRotatingGunPosition[index], index + FIELD_PROJECTILE_LEFT, index % 2);
			}
		}
	}
}

inline void moveGun(uint8_t* newMap, uint8_t ifEmpty, uint8_t ifChange)
{
	if (*newMap == FIELD_EMPTY)
	{
		*newMap = ifEmpty;
		change(newMap);
		shootUp(RND(),  newMap);
		*mapPtr = FIELD_EMPTY;
		change(mapPtr);

	}
	else
	{
		*mapPtr =  ifChange;
		shootUp(RND(),  mapPtr);
	}
}

void movableGunLeft()
{
	if (animCounter == 1 || animCounter == 5)
	{
		moveGun(MAP_LEFT(mapPtr), FIELD_MOVABLE_GUN_LEFT, FIELD_MOVABLE_GUN_RIGHT | FIELD_TYPES_WAIT_FLAG);
	}
	else
	{
		shootUp(RND(),  mapPtr);
	}
}

void movableGunRight()
{
	if (animCounter == 1 || animCounter == 5)
	{
		moveGun(MAP_RIGHT(mapPtr), FIELD_MOVABLE_GUN_RIGHT | FIELD_TYPES_WAIT_FLAG, FIELD_MOVABLE_GUN_LEFT);
	}
	else
	{
		shootUp(RND(),  mapPtr);
	}
}