#pragma once

#include <stdint.h>

extern uint8_t* changes[];
extern uint8_t** changesPtr;

#define CHANGES_TERMINATOR NULL
#define PUT_CHANGES(map)	\
	*changesPtr++ = (map);

#define PUT_CHANGES_TERMINATOR()	*changesPtr=CHANGES_TERMINATOR


#define change(map)				\
do								\
{								\
	if (doChanege)				\
	{							\
		PUT_CHANGES(map);		\
	}							\
} while (0)
