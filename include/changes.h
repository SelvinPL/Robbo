#pragma once

#include <stdint.h>
#include <types.h>

extern uint8_t* changes[];
extern uint8_t** changesPtr;

#define CHANGES_TERMINATOR NULL

#define PUT_CHANGES(map)			*changesPtr++ = (map)

#define PUT_CHANGES_TERMINATOR()	*changesPtr=CHANGES_TERMINATOR

void change(uint8_t* map);