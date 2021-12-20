#pragma once

#include "gb/gb.h"


extern bool winSlide;
extern int8_t winSlideX;
extern uint8_t winSlideToX;


inline void startSlideIn()
{
	move_win(167, 0);
	winSlideToX = 7;
	winSlideX = -4;
	winSlide = true;
}



inline void startSlideOut()
{
	move_win(7, 0);
	winSlideToX = 167;
	winSlideX = 4;
	winSlide = true;
}

inline void slideStep()
{
	if (winSlide)
	{
		if (winSlideToX != WX_REG)
		{
			WX_REG += winSlideX;
		}
		else
		{
			winSlide = false;
			if(nextFunction)
				nextFunction();
		}
	}
}
