#pragma once

#include "platform.h"
#include "hud.h"

extern bool winSlide;
extern int8_t winSlideX;
extern uint8_t winSlideToX;
extern bool callNext;

#ifdef GAMEBOY
#define winPositionX WX_REG
#define slideStepElsePlatformSpecific()

inline void startSlideInPlatformSpecific()
{
	move_win(167, sliderYPos);
	winSlideToX = 7;
}

inline void startSlideOutPlatformSpecific()
{
	move_win(7, sliderYPos);
	winSlideToX = 167;
}

inline void slideStepIfPlatformSpecific()
{
	WX_REG += winSlideX;
}
#else
extern uint8_t winPositionX;

inline void startSlideInPlatformSpecific()
{
	winPositionX = 172 - fixY;
	winSlideToX = 0;
	__WRITE_VDP_REG(VDP_R10, winPositionX);
}

inline void startSlideOutPlatformSpecific()
{
	winPositionX = 0;
	winSlideToX = 172 - fixY;
	__WRITE_VDP_REG(VDP_R10, winPositionX);
}

inline void slideStepIfPlatformSpecific()
{
	winPositionX += winSlideX;
	__WRITE_VDP_REG(VDP_R10, winPositionX);
}

inline void slideStepElsePlatformSpecific()
{
	if (winPositionX == (172 - fixY))
	{
		__WRITE_VDP_REG(VDP_R10, 175 - fixY);
	}
}
#endif

inline void startSlideIn()
{
	hideHUD();
	startSlideInPlatformSpecific();
	winSlideX = -4;
	winSlide = true;
	callNext = false;
}

inline void startSlideOut()
{
	startSlideOutPlatformSpecific();
	winSlideX = 4;
	winSlide = true;
	callNext = false;
}

inline void slideStep()
{
	if (winSlide)
	{
		if (winSlideToX != winPositionX)
		{
			slideStepIfPlatformSpecific();
		}
		else
		{
			slideStepElsePlatformSpecific();
			winSlide = false;
			callNext = true;
		}
	}
}