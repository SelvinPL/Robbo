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