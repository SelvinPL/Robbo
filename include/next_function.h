#pragma once

#include <stdint.h>
#include <types.h>

typedef uint8_t (*function)();

extern function nextFunctionPtr;

inline void setNextFunction(function nextFunction)
{
	nextFunctionPtr = nextFunction;
}

inline void callNextFunction()
{	
	if (nextFunctionPtr && nextFunctionPtr())
		nextFunctionPtr = NULL;
}