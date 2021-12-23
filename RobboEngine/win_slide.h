#pragma once

#include "platform.h"


extern bool winSlide;
extern int8_t winSlideX;
extern uint8_t winSlideToX;


inline void startSlideIn()
{
#ifdef GAMEBOY
	move_win(167, 0);
	winSlideToX = 7;
	winSlideX = -4;
#endif 
	winSlide = true;
}



inline void startSlideOut()
{
#ifdef GAMEBOY
	move_win(7, 0);
	winSlideToX = 167;
	winSlideX = 4;
#endif
	winSlide = true;
}

inline void slideStep()
{
#ifdef GAMEBOY
	if (winSlide)
	{
		if (winSlideToX != WX_REG)
		{
			WX_REG += winSlideX;
		}
		else
		{
#endif
			winSlide = false;
			if(nextFunction)
				nextFunction();
#ifdef GAMEBOY
		}
	}
#endif
}
