#pragma once

#include <stdint.h>
#include "stdbool.h"

inline void shootLeft(bool when, uint8_t* ptr)
{
	if ((when))
	{
		extern void shootLeft(uint8_t * ptr);
		shootLeft(ptr);
	}
}

inline void shootRight(bool when, uint8_t* ptr)
{
	if ((when))
	{
		extern void shootRight(uint8_t * ptr);
		shootRight(ptr);
	}
}

inline void shootUp(bool when, uint8_t* ptr)
{
	if ((when))
	{
		extern void shootUp(uint8_t * ptr);
		shootUp(ptr);
	}
}

inline void shootDown(bool when, uint8_t* ptr)
{
	if ((when))
	{
		extern void shootDown(uint8_t * ptr);
		shootDown(ptr);
	}
}