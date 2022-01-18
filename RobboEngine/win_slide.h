#pragma once

#include "platform.h"
#include "hud.h"

extern bool winSlide;
extern int8_t winSlideX;
extern uint8_t winPositionX;
extern uint8_t winSlideToX;

inline void startSlideIn()
{
	hideHUD();
#ifdef GAMEBOY
	move_win(167, sliderYPos);
	winSlideToX = 7;
#else
	winPositionX = 172 - fixY;
	winSlideToX = 0;
	__WRITE_VDP_REG(VDP_R10, winPositionX);
#endif 
	winSlideX = -4;
	winSlide = true;
}

inline void startSlideOut()
{
#ifdef GAMEBOY
	move_win(7, sliderYPos);
	winSlideToX = 167;
#else
	winPositionX = 0;
	winSlideToX = 172 - fixY;
	__WRITE_VDP_REG(VDP_R10, winPositionX);
#endif 
	winSlideX = 4;
	winSlide = true;
}

inline void slideStep()
{
	if (winSlide)
	{
#ifdef GAMEBOY
		if (winSlideToX != WX_REG)
		{
			WX_REG += winSlideX;
		}
		else
		{ 
#else
		if (winSlideToX != winPositionX)
		{
			winPositionX += winSlideX;
			__WRITE_VDP_REG(VDP_R10, winPositionX);

		}
		else
		{
			if (winPositionX == (172 - fixY))
			{
				__WRITE_VDP_REG(VDP_R10, 175 - fixY);
			}
#endif
			winSlide = false;
			if(nextFunction)
				nextFunction();
		}
	}
}
