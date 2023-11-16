#pragma once

#include <stdint.h>
#include <platform.h>
#include <globals.h>

#ifdef NINTENDO
#include "gb/camera.h"
#endif
#ifdef SEGA
#include "sega/camera.h"
#endif

inline uint8_t incrementCameraY();
static inline void slide_bkg_x();
static inline void slide_bkg_y();

inline uint8_t incrementCameraX()
{
	return cameraPosX += slideX;
}