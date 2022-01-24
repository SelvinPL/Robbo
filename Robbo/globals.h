#pragma once

#include <stdint.h>
#include <types.h>
#include "BCD8.h"
#include "functions_map.h"

extern uint8_t iterX;
extern uint8_t iterY;
extern uint8_t changeYstart;
extern uint8_t changeYend;
extern uint8_t doChanege;

extern uint8_t* mapPtr;
extern uint8_t nextYTiles[];
extern uint8_t* nextYTilesPtr;
extern uint8_t* nextNextYTilesPtr;
extern uint8_t* currentYTilesPtr;

extern uint8_t counter;
extern const uint8_t* map_to_tiles;
extern uint8_t map_to_tiles_hi;
extern uint8_t map_pos_x;
extern uint8_t map_pos_y;
extern uint8_t slide_to_map_pos_x;
extern uint8_t slide_to_map_pos_y;
extern uint8_t waitAfterSetupLevel;

extern uint8_t animCounter;
extern int8_t slideX;
extern int8_t slideY;

extern uint8_t padState;
extern bool padEnabled;

extern BCD8 level;
extern uint8_t cave;

extern uint8_t cameraPosX;
extern uint8_t cameraPosY;

extern bool screwCounting;

inline void setNextFunction(function nextFunction)
{
	extern function nextFunctionPtr;
	nextFunctionPtr = nextFunction;
}

inline void callNextFunction()
{
	extern function nextFunctionPtr;
	if (nextFunctionPtr && nextFunctionPtr())
		nextFunctionPtr = NULL;
}