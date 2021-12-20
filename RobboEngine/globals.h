#pragma once

#include <stdint.h>
#include "functions_map.h"

extern uint8_t iterX;
extern uint8_t iterY;
extern uint8_t changeYstart;
extern uint8_t changeYend;
extern uint8_t doChanege;
extern uint8_t nextXTile;
extern uint8_t* mapPtr;
extern uint8_t* chanegesPtr;
extern uint8_t nextYTiles[];
extern uint8_t* nextYTilesPtr;


extern uint8_t counter;
extern const uint8_t* map_to_tiles;
extern uint8_t map_pos_x;
extern uint8_t map_pos_y;

extern uint8_t animCounter;
extern int8_t slideX;
extern int8_t slideY;

extern __sfr padState;
extern bool padEnabled;
extern function nextFunction;

extern uint8_t level;