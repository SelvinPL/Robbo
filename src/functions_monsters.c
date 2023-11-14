#include <stdbool.h>
#include <stdint.h>
#include <rand.h>
#include <map.h>
#include <fields.h>
#include <globals.h>
#include <changes.h>
#include <map.h>
#include <robbo_state.h>
#include <functions_monsters.h>
#include <projectile_utils.h>

#define RND() (((uint8_t)rand()) < 18)

const int8_t const checkForRobboPositions[] =
{
	-1,
	1,
	-16,
	16,
};

void checkRobbo(uint8_t* newMap)
{
	for (uint8_t i = 0; i < 4; i++)
	{
		uint8_t* near = newMap + checkForRobboPositions[i];
		if((*near & FIELD_TYPES_MAX) == FIELD_ROBBO)
		{
			*near = FIELD_EXPLOSION_ANIM1;
			change(near);
			return;
		}	
	}
}

inline uint8_t monsterMove(uint8_t* newMap, uint8_t ifEmpty, uint8_t ifChanege)
{
	if ((*newMap & FIELD_TYPES_MAX) == FIELD_EMPTY)
	{
		*newMap = ifEmpty;
		change(newMap);
		checkRobbo(newMap);
		change(mapPtr);
		*mapPtr = FIELD_EMPTY;
		return 1;
	}
	else
	{
		*mapPtr = ifChanege;
		change(mapPtr);
		checkRobbo(mapPtr);
		return 0;
	}
}

inline void monsterMove2(uint8_t* newMap, uint8_t ifEmpty, uint8_t* newMap2, uint8_t ifEmpty2, uint8_t ifChanege)
{
	if ((*newMap & FIELD_TYPES_MAX) == FIELD_EMPTY)
	{
		*newMap = ifEmpty;
		change(newMap);
		checkRobbo(newMap);
		change(mapPtr);
		*mapPtr = FIELD_EMPTY;
	}
	else if ((*newMap2 & FIELD_TYPES_MAX) == FIELD_EMPTY)
	{
		*newMap2 = ifEmpty2;
		change(newMap2);
		checkRobbo(newMap2);
		change(mapPtr);
		*mapPtr = FIELD_EMPTY;
	}
	else
	{
		*mapPtr = ifChanege;
		change(mapPtr);
		checkRobbo(mapPtr);
	}
}

//A
void leftHandLeft()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_LEFT(mapPtr), FIELD_LEFT_HAND_DOWN, 
		MAP_UP(mapPtr), FIELD_LEFT_HAND_LEFT, FIELD_LEFT_HAND_UP);
}

//B
void leftHandRight()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_RIGHT(mapPtr), FIELD_LEFT_HAND_UP | FIELD_TYPES_WAIT_FLAG, 
		MAP_DOWN(mapPtr), FIELD_LEFT_HAND_RIGHT | FIELD_TYPES_WAIT_FLAG, FIELD_LEFT_HAND_DOWN);
}

//C
void leftHandUp()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_UP(mapPtr), FIELD_LEFT_HAND_LEFT, 
		MAP_RIGHT(mapPtr), FIELD_LEFT_HAND_UP | FIELD_TYPES_WAIT_FLAG, FIELD_LEFT_HAND_RIGHT);
}

//D
void leftHandDown()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_DOWN(mapPtr), FIELD_LEFT_HAND_RIGHT | FIELD_TYPES_WAIT_FLAG, 
		MAP_LEFT(mapPtr), FIELD_LEFT_HAND_DOWN, FIELD_LEFT_HAND_LEFT);
}

//E
void rightHandLeft()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_LEFT(mapPtr), FIELD_RIGHT_HAND_UP, 
		MAP_DOWN(mapPtr), FIELD_RIGHT_HAND_LEFT | FIELD_TYPES_WAIT_FLAG, FIELD_RIGHT_HAND_DOWN);
}

//F
void rightHandRight()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_RIGHT(mapPtr), FIELD_RIGHT_HAND_DOWN | FIELD_TYPES_WAIT_FLAG, 
		MAP_UP(mapPtr), FIELD_RIGHT_HAND_RIGHT, FIELD_RIGHT_HAND_UP);
}

//G
void rightHandUp()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_UP(mapPtr), FIELD_RIGHT_HAND_RIGHT, 
		MAP_LEFT(mapPtr), FIELD_RIGHT_HAND_UP, FIELD_RIGHT_HAND_LEFT);
}

//H
void rightHandDown()
{
	if (!(animCounter & 1))
		return;
	monsterMove2(MAP_DOWN(mapPtr), FIELD_RIGHT_HAND_LEFT | FIELD_TYPES_WAIT_FLAG, 
		MAP_RIGHT(mapPtr), FIELD_RIGHT_HAND_DOWN | FIELD_TYPES_WAIT_FLAG, FIELD_RIGHT_HAND_RIGHT);
}

//I
void batLeft()
{
	if (!(animCounter & 1))
		return;
	monsterMove(MAP_LEFT(mapPtr), FIELD_BAT_LEFT, FIELD_BAT_RIGHT);
}

//J
void batRight()
{
	if (!(animCounter & 1))
		return;
	monsterMove(MAP_RIGHT(mapPtr), FIELD_BAT_RIGHT | FIELD_TYPES_WAIT_FLAG, FIELD_BAT_LEFT);
}

//K
void batUp()
{
	if (!(animCounter & 1))
		return;
	monsterMove(MAP_UP(mapPtr), FIELD_BAT_UP, FIELD_BAT_DOWN);
}


//L
void batDown()
{
	if (!(animCounter & 1))
		return;
	monsterMove(MAP_DOWN(mapPtr), FIELD_BAT_DOWN | FIELD_TYPES_WAIT_FLAG, FIELD_BAT_UP);
}

void batShootingLeft()
{
	if (!(animCounter & 1))
		return;
	uint8_t* newMap = MAP_LEFT(mapPtr);
	uint8_t offset = monsterMove(newMap, FIELD_BAT_SHOOTING_LEFT, FIELD_BAT_SHOOTING_RIGHT);
	if (RND())
	{
		if(offset)
		{
			shoot(MAP_DOWN(offset ? newMap : mapPtr), FIELD_PROJECTILE_DOWN, true);
		}
	}
	change(mapPtr);
}

void batShootingRight()
{
	if (!(animCounter & 1))
		return;
	uint8_t* newMap = MAP_RIGHT(mapPtr);
	uint8_t offset = monsterMove(newMap, FIELD_BAT_SHOOTING_RIGHT | FIELD_TYPES_WAIT_FLAG, FIELD_BAT_SHOOTING_LEFT);
	if (RND())
	{
		if(offset)
		{
			shoot(MAP_DOWN(offset ? newMap : mapPtr), FIELD_PROJECTILE_DOWN, true);
		}
	}
	change(mapPtr);
}

#define eyesDown() \
{\
	uint8_t* newMap = MAP_DOWN(mapPtr);\
	if (*newMap == FIELD_EMPTY)\
	{\
		*newMap = FIELD_EYES | FIELD_TYPES_WAIT_FLAG;\
		checkRobbo(newMap);\
		*mapPtr = FIELD_EMPTY;\
		change(mapPtr);\
		return;\
	}\
}

#define eyesUp() \
{\
	uint8_t* newMap = MAP_UP(mapPtr);\
	if (*newMap == FIELD_EMPTY)\
	{\
		*newMap = FIELD_EYES;\
		change(newMap);\
		checkRobbo(newMap);\
		*mapPtr = FIELD_EMPTY;\
		change(mapPtr);\
		return;\
	}\
}

#define eyesRight() \
{\
	uint8_t* newMap = MAP_RIGHT(mapPtr);\
	if (*newMap == FIELD_EMPTY)\
	{\
		*newMap = FIELD_EYES | FIELD_TYPES_WAIT_FLAG;\
		checkRobbo(newMap);\
		*mapPtr = FIELD_EMPTY;\
		change(mapPtr);\
		return;\
	}\
}

#define eyesLeft() \
{\
	uint8_t* newMap = MAP_LEFT(mapPtr);\
	if (*newMap == FIELD_EMPTY)\
	{\
		*newMap = FIELD_EYES;\
		change(newMap);\
		checkRobbo(newMap);\
		*mapPtr = FIELD_EMPTY;\
		change(mapPtr);\
		return;\
	}\
}

void eyes()
{
	if (!(animCounter & 1))
		return;
	if (rand() & 1)
	{
		if (robboState.Y > iterY)
		{
			eyesDown();
		}
		else if (robboState.Y < iterY)
		{
			eyesUp();
		}
		if (robboState.X > iterX)
		{
			eyesRight();
		}
		else if (robboState.X < iterX)
		{
			eyesLeft();
		}
	}
	else
	{
		//jump
		if (rand() & 32U)
		{
			switch (rand() & 3U)
			{
			case 0:
				eyesDown();
			case 1:
				eyesUp();
			case 2:
				eyesRight();
			case 3:
				eyesLeft();
			}
		}
	}
}