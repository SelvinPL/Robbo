#pragma once

#include "platform.h"
#include "hud.h"

extern bool winSlide;
extern int8_t winSlideX;
#ifdef GAMEBOY
#define winPositionX WX_REG
#else
extern uint8_t winPositionX;
#endif
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
		if (winSlideToX != winPositionX)
		{
#ifdef GAMEBOY
			WX_REG += winSlideX;
#else
			winPositionX += winSlideX;
			__WRITE_VDP_REG(VDP_R10, winPositionX);
#endif
		}
		else
		{
#ifndef GAMEBOY
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
