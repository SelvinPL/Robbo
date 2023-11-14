#pragma once

#include <gbdk/platform.h>
#ifdef NINTENDO
	#include "gb/platform.h"
#endif	
#ifdef SEGA
	#include "sega/platform.h"
#endif

#define maxPosX (16U-(DEVICE_SCREEN_WIDTH/2U))
#define visibleY ((DEVICE_SCREEN_HEIGHT/2U) + platformFix)
#define maxPosY (32U-visibleY + platformFix)
#define fixX (8U*DEVICE_SCREEN_X_OFFSET)
#define fixY (8U*DEVICE_SCREEN_Y_OFFSET)
#define fixTileX DEVICE_SCREEN_X_OFFSET
#define fixTileY DEVICE_SCREEN_Y_OFFSET
#define hudX (DEVICE_SPRITE_PX_OFFSET_X+((DEVICE_SCREEN_WIDTH-20U)*4U))

#define cameraStartPosY ((DEVICE_SCREEN_BUFFER_HEIGHT-DEVICE_SCREEN_Y_OFFSET)*8U)