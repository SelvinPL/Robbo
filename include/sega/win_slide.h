#pragma once

#include <stdint.h>
#include <platform.h>
#include <globals.h>

#ifdef __SDCC
#define WRITE_VDP_WIN_POS __critical{VDP_CMD=(winPositionX),VDP_CMD=VDP_R10;}
#define WRITE_VDP_WIN_POS_EX __critical{VDP_CMD=(uint8_t)(175U - fixY),VDP_CMD=VDP_R10;}
#else
#define WRITE_VDP_WIN_POS
#define WRITE_VDP_WIN_POS_EX
#endif

extern uint8_t winPositionX;

inline void startSlideInPlatformSpecific()
{
	winPositionX = (uint8_t)(172U - fixY);
	winSlideToX = 0U;
	WRITE_VDP_WIN_POS;
}

inline void startSlideOutPlatformSpecific()
{
	winPositionX = 0U;
	winSlideToX = (uint8_t)(172U - fixY);
	WRITE_VDP_WIN_POS;
}

inline void slideStepIfPlatformSpecific()
{
	winPositionX += winSlideX;
	WRITE_VDP_WIN_POS;
}

inline void slideStepElsePlatformSpecific()
{
	if (winPositionX == ((uint8_t)(172U - fixY)))
	{
		WRITE_VDP_WIN_POS_EX;
	}
}