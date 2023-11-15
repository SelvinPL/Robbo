#pragma once

#include <stdint.h>
#include <BCD8.h>

#define EXISTS_COUNTER_START	40U

typedef struct
{
	uint8_t X;
	uint8_t Y;
	BCD8 keys;
	BCD8 ammo;
	BCD8 lives;
	BCD8 screws;
	uint8_t delay;
	uint8_t existsCounter;
	uint8_t teleporting;
	uint8_t teleportingState;
	uint8_t teleportX;
	uint8_t teleportY;
	uint8_t direction;
} robbo_info;

extern robbo_info robboState;