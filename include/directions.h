#pragma once

#include <stdint.h>

typedef enum
{
	direction_left	= 0,
	direction_up	= 1,
	direction_right	= 2,
	direction_down	= 3,
	direction_none	= 4,
} directions;

extern const int8_t directions_matrix[];