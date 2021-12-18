#include <stdint.h>


__at(0xffa0) uint8_t iterX;
__at(0xffa1) uint8_t iterY;
__at(0xffa3) uint8_t changeYstart;
__at(0xffa4) uint8_t changeYend;
__at(0xffa5) uint8_t doChanege;
__at(0xffa6) uint8_t x_next_tile;
__at(0xffa7) uint8_t ux;
__at(0xffa8) uint8_t uy;
__at(0xffa9) uint8_t anim_counter;
__at(0xffaa) uint8_t* mapPtr;
__at(0xffac) uint8_t* chanegesPtr;
__at(0xffae) uint8_t* change;


__at(0xffb0) uint8_t counter;
__at(0xffb1) int8_t slideX;
__at(0xffb2) int8_t slideY;
__at(0xffb3) uint8_t map_pos_x;
__at(0xffb4) uint8_t map_pos_y;
__at(0xffb5) const uint8_t* map_to_tiles;
__at(0xffb7) uint8_t* y_next_tilesPtr;

__at(0xffc0) uint8_t y_next_tiles[16];