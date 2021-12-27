#pragma once
#include <gbdk/platform.h>

#ifdef GAMEBOY

const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");	

#else
extern void wait_vbl_done_alt();
#define wait_vbl_done()	wait_vbl_done_alt()	
/*
const __at(0x38) uint8_t vblank_isr[] = { 0xdb, 0xbf, 0xfb, 0xed, 0x4d, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");
//	*/ 
#endif