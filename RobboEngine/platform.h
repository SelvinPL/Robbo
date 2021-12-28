#pragma once
#include <gbdk/platform.h>

#ifdef GAMEBOY

const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");	
#define SWITCH_ROM_EX SWITCH_ROM
#else
extern void wait_vbl_done_alt();
#define wait_vbl_done()	wait_vbl_done_alt()	
#define SWITCH_ROM_EX SWITCH_ROM2
#endif


#if defined(GAMEBOY)
#define maxPosX 6
#define maxPosY 23
#define visibleY 8
#define fixX 0
#define fixY 0
#define fixTileX 0
#define fixTileY 0
#define cameraStartPosY 0
#elif defined(GAMEGEAR)
#define maxPosX 6
#define maxPosY 23
#define visibleY 8
#define fixX 48
#define fixY 24
#define fixTileX 6
#define fixTileY 3
#define cameraStartPosY 200
#else
#define maxPosX 0
#define maxPosY 20
#define visibleY 11
#define fixX 0
#define fixY 0
#define fixTileX 0
#define fixTileY 0
#define cameraStartPosY 0
#endif 


//drawHUD
#ifdef GAMEBOY
#define drawHUD()
#else
#define	drawHUD()								\
	do											\
	{											\
		__WRITE_VDP_REG(VDP_R2, R2_MAP_0x3800);	\
	}											\
	while(0)
#endif


//initHUD
#ifdef GAMEBOY
#define	initHUD()								\
	do											\
	{											\
		init_win(tiles_trans_black_wall);		\
		WX_REG = 7;								\
		WY_REG = 0;								\
		SHOW_WIN;								\
		drawNumber(9, 8, level);				\
	}											\
	while(0)
#else
#define	initHUD()										\
	do													\
	{													\
		for (uint8_t c = 0; c < 112; c++)				\
		{												\
			vmemcpy(0x7000 + c * 16, tile2_data, 16);	\
		}												\
		uint8_t state = __READ_VDP_REG(VDP_R0);			\
		state |= R0_IE1;								\
		__WRITE_VDP_REG(VDP_R0, state);					\
		__WRITE_VDP_REG(VDP_R10, 175U - fixY);			\
	}													\
	while(0)
#endif