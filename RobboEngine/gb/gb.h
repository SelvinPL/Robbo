#pragma once

#include <gb/gb.h>

const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");	\
	__asm__("	nop");
