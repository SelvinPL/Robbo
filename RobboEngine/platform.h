#pragma once
#include <gbdk/platform.h>
#ifdef GAMEBOY
	#define maxPosX 6
	#define maxPosY 23
	#define visibleY 8
	#define fixX 0
	#define fixY 0
	#define fixTileX 0
	#define fixTileY 0
	#define cameraStartPosY 0
	#define sliderYPos 0
	const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };
	#define wait_vbl_done()	\
		__asm__("	halt");	
	#define SWITCH_ROM_EX SWITCH_ROM
#else
	extern void wait_vbl_done_alt();
	#define wait_vbl_done()	wait_vbl_done_alt()	
	#define SWITCH_ROM_EX SWITCH_ROM2
	#ifdef GAMEGEAR
		#define maxPosX 6
		#define maxPosY 23
		#define visibleY 8
		#define fixX 48
		#define fixY 24
		#define fixTileX 6
		#define fixTileY 3
		#define cameraStartPosY 200
		#define hudX 48U
		#define hudY (127U+256U+fixY)
	#else
		#define maxPosX 0
		#define maxPosY 20
		#define visibleY 11
		#define fixX 0
		#define fixY 0U
		#define fixTileX 0
		#define fixTileY 0
		#define hudX 48U
		#define hudY (175U+256U)
		#define cameraStartPosY 0
	#endif
#endif