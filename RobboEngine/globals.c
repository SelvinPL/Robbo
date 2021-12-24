#include <stdint.h>
#include "functions_map.h"


uint8_t iterX;
uint8_t iterY;
uint8_t changeYstart;
uint8_t changeYend;
uint8_t doChanege;
uint8_t nextXTile;
uint8_t animCounter;
uint8_t* mapPtr;
uint8_t* changesPtr;


uint8_t counter;
int8_t slideX;
int8_t slideY;
uint8_t map_pos_x;
uint8_t map_pos_y;
const uint8_t* map_to_tiles;
uint8_t map_to_tiles_hi;
uint8_t* nextYTilesPtr;

uint8_t nextYTiles[16];
uint8_t level;


uint8_t padState;

function nextFunction;
bool padEnabled;