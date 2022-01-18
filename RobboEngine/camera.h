#pragma once

#include <stdint.h>
#include "globals.h"
#include "platform.h"

inline uint8_t incrementCameraX()
{
	return cameraPosX += slideX;
}

#ifdef GAMEBOY
inline uint8_t incrementCameraY()
{
	return cameraPosY += slideY;
}
inline void slide_bkg_x()
{
	SCX_REG = incrementCameraX();
}
inline void slide_bkg_y()
{
	SCY_REG = incrementCameraY();
}
#else
inline uint8_t incrementCameraY()
{
	uint8_t ret = cameraPosY + slideY;
	if (ret > 240)
		ret -= 32;
	else if (ret >= 224)
		ret -= 224;
	return cameraPosY = ret;
}

inline void slide_bkg_x()
{
	__WRITE_VDP_REG(VDP_RSCX, -incrementCameraX());
}
inline void slide_bkg_y()
{
	__WRITE_VDP_REG(VDP_RSCY, incrementCameraY());
}
#endif 