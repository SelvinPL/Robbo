#pragma once

#include <stdint.h>
#include <platform.h>

inline uint8_t incrementCameraX();

inline uint8_t incrementCameraY()
{
	uint8_t ret = cameraPosY + slideY;
	if (ret > 240)
		ret -= 32U;
	else if (ret >= 224U)
		ret -= 224U;
	return cameraPosY = ret;
}

static inline void slide_bkg_x()
{
	__WRITE_VDP_REG(VDP_RSCX, -incrementCameraX());
}

static inline void slide_bkg_y()
{
	__WRITE_VDP_REG(VDP_RSCY, incrementCameraY());
}