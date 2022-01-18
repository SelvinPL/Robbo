#include <stdint.h>
#include "platform.h"
#include "tiles.h"

const uint8_t numbersTiles[10][2] =
{
	{ TILE_NUM_PART0, TILE_NUM_PART1 }, //0
	{ TILE_NUM_PART2, TILE_NUM_PART3 }, //1
	{ TILE_NUM_PARTB, TILE_NUM_PART5 }, //2
	{ TILE_NUM_PARTB, TILE_NUM_PART6 }, //3
	{ TILE_NUM_PART7, TILE_NUM_PART8 }, //4
	{ TILE_NUM_PART9, TILE_NUM_PART6 }, //5
	{ TILE_NUM_PART9, TILE_NUM_PARTA }, //6
	{ TILE_NUM_PART4, TILE_NUM_PART3 }, //7
	{ TILE_NUM_PARTC, TILE_NUM_PARTA }, //8
	{ TILE_NUM_PARTC, TILE_NUM_PART6 }, //9
};


void drawNumber(uint8_t x, uint8_t y, uint8_t number)
{
	set_win_tiles(x, y, 1, 2, numbersTiles[(number >> 4) & 0xf]);
	set_win_tiles(x + 1, y, 1, 2, numbersTiles[number & 0xf]);
}