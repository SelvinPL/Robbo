#pragma once

#include <stdint.h>

typedef struct
{
	uint8_t X;
	uint8_t Y;
	uint8_t keys;
	uint8_t ammo;
	uint8_t lives;
	uint8_t screws;
	uint8_t shootDelay;

} robbo_info;

extern robbo_info robboState;
