#pragma once

#include <gbdk/platform.h>

#define HIRAMUINT8(...) uint8_t
#define DEFHIRAMUINT8 uint8_t
#define STANDARD_CALL Z88DK_FASTCALL

extern void wait_vbl_done_alt();

#define wait_vbl_done()	wait_vbl_done_alt()	
#define SWITCH_ROM_EX SWITCH_ROM

#define platformFix 0U

inline void systemInit()
{
	__WRITE_VDP_REG(VDP_RBORDER, 3);
}	
