#include <stdint.h>
#include <BCD8.h>
#include <platform.h>

#define START 0xffe0

#define HIRAM HIRAMUINT8(0xffa0 + __COUNTER__)

HIRAM iterX;
HIRAM iterY;
HIRAM changeYstart;
HIRAM changeYend;
HIRAM counter;
HIRAM map_pos_x;
HIRAM map_pos_y;
HIRAM animCounter;
HIRAM map_to_tiles_lo;
HIRAM map_to_tiles_hi;
HIRAM padState;
HIRAM padStateCounter;
HIRAM padEnabled;
HIRAM cameraPosX;
HIRAM cameraPosY;
HIRAM screwsCountingState;
HIRAM winSlide;
HIRAM winSlideX;
HIRAM winSlideToX;
HIRAM callNext;
HIRAM newRobboX;
HIRAM newRobboY;

uint8_t cave;
uint8_t slideX;
uint8_t slideY;

uint8_t* map_to_tiles;

uint8_t slide_to_map_pos_x;
uint8_t slide_to_map_pos_y;

BCD8 level = { 0x1 };

uint8_t waitAfterSetupLevel;