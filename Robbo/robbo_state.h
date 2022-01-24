#pragma once

#include <stdint.h>
#include "BCD8.h"

typedef struct
{
	uint8_t X;
	uint8_t Y;
	BCD8 keys;
	BCD8 ammo;
	BCD8 lives;
	BCD8 screws;
	uint8_t shootDelay;

} robbo_info;

extern robbo_info robboState;