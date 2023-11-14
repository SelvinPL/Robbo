#pragma once

#include <platform.h>
#include <globals.h>
#include <hud.h>
#include <stdbool.h>

#ifdef NINTENDO
#include <gb/win_slide.h>
#endif
#ifdef SEGA
#include <sega/win_slide.h>
#endif

inline void startSlideIn()
{
	hideHUD();
	startSlideInPlatformSpecific();
	winSlideX = (uint8_t)-4;
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