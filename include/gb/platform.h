#pragma once

#include <gbdk/platform.h>

#define sliderYPos 0U

#define wait_vbl_done()	\
	__asm__("	halt"); \
	__asm__("	nop");
#define SWITCH_ROM_EX SWITCH_ROM
#define HIRAMUINT8(...) uint8_t AT(__VA_ARGS__)
#ifdef __SDCC
#define DEFHIRAMUINT8 __sfr
#define STANDARD_CALL __sdcccall(1)
#else
#define DEFHIRAMUINT8 uint8_t
#define STANDARD_CALL
#endif
#define platformFix 1U
inline void systemInit()
{
//if(_cpu == CGB_TYPE)
//	cpu_fast();
}