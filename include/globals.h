#pragma once

#include <stdint.h>
#include <types.h>
#include <platform.h>
#include <BCD8.h>
#include <functions_map.h>


extern DEFHIRAMUINT8 iterX;
extern DEFHIRAMUINT8 iterY;
extern DEFHIRAMUINT8 changeYstart;
extern DEFHIRAMUINT8 changeYend;
extern DEFHIRAMUINT8 counter;
extern DEFHIRAMUINT8 map_pos_x;
extern DEFHIRAMUINT8 map_pos_y;
extern DEFHIRAMUINT8 animCounter;
#ifdef SET_BKG_TILE_ASM
extern DEFHIRAMUINT8 map_to_tiles_lo;
extern DEFHIRAMUINT8 map_to_tiles_hi;
#else
extern const uint8_t* map_to_tiles;
#endif
extern DEFHIRAMUINT8 padState;
extern DEFHIRAMUINT8 padStateCounter;
extern DEFHIRAMUINT8 padEnabled;
extern DEFHIRAMUINT8 cameraPosX;
extern DEFHIRAMUINT8 cameraPosY;
#define SCREW_STATE_NONE		0
#define SCREW_STATE_COUNTING	1
#define SCREW_STATE_COUNTED		2
extern DEFHIRAMUINT8 screwsCountingState;
extern DEFHIRAMUINT8 winSlide;
extern DEFHIRAMUINT8 winSlideX;
extern DEFHIRAMUINT8 winSlideToX;
extern DEFHIRAMUINT8 newRobboX;
extern DEFHIRAMUINT8 newRobboY;
extern uint8_t callNext;
extern uint8_t cave;
extern uint8_t slideX;
extern uint8_t slideY;

extern uint8_t slide_to_map_pos_x;
extern uint8_t slide_to_map_pos_y;
extern uint8_t waitAfterSetupLevel;

extern BCD8 level;