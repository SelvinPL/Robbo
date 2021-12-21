#pragma once
#include "globals.h"

inline void changeLeft()
{
	if (doChanege)
	{
		*changesPtr++ = iterX - 1;
		*changesPtr++ = iterY;
	}
}

inline void changeUp()
{
	if (doChanege)
	{
		*changesPtr++ = iterX;
		*changesPtr++ = iterY - 1;
	}
}