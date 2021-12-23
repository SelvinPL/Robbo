#pragma once

#include <stdint.h>

extern uint8_t changes[];
extern uint8_t* changesPtr;

#define CHANGES_TERMINATOR 0xff
#define PUT_CHANGES(x, y)	\
	*changesPtr++ = (x);	\
	*changesPtr++ = (y)

#define PUT_CHANGES_TERMINATOR()	*changesPtr=0xff


inline void changeLeft()
{
	if (doChanege)
	{
		PUT_CHANGES(iterX - 1, iterY);
	}
}

inline void changeUp()
{
	if (doChanege)
	{
		PUT_CHANGES(iterX, iterY - 1);
	}
}