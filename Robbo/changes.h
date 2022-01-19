#pragma once

#include <stdint.h>
#include "globals.h"

extern uint8_t* changes[];
extern uint8_t** changesPtr;

#define CHANGES_TERMINATOR NULL

#define PUT_CHANGES(map)			*changesPtr++ = (map)

#define PUT_CHANGES_TERMINATOR()	*changesPtr=CHANGES_TERMINATOR

void inline change(uint8_t* map)
{
	if (doChanege)
	{
		PUT_CHANGES(map);
	}
}