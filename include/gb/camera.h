#pragma once

#include <stdint.h>
#include <platform.h>

inline uint8_t incrementCameraX();

inline uint8_t incrementCameraY()
{
	return cameraPosY += slideY;
}

static inline void slide_bkg_x()
{
	SCX_REG = incrementCameraX();
}

static inline void slide_bkg_y()
{
	SCY_REG = incrementCameraY();
}