#pragma once
#include "hi_ram_globals.h"

inline void changeLeft()
{
	if (doChanege)
	{
		*chanegesPtr++ = iterX - 1;
		*chanegesPtr++ = iterY;
	}
}

inline void changeUp()
{
	if (doChanege)
	{
		*chanegesPtr++ = iterX;
		*chanegesPtr++ = iterY - 1;
	}
}