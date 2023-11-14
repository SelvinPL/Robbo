#pragma once

#include <globals.h>

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
	WX_REG += (int8_t)winSlideX;
}