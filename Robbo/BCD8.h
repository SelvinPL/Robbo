#pragma once
#include <stdint.h>

typedef struct 
{
	uint8_t value;
} BCD8;

inline uint8_t incerement(BCD8* i)
{
	uint8_t ni = i->value + 1;
	if ((ni & 0xf) > 9)
	{
		ni += 6;
	}
	return ni;
}

inline uint8_t decrement(BCD8* i)
{
	uint8_t ni = i->value - 1;
	if ((ni & 0xf) == 0xf)
	{
		ni -= 6;
	}
	return ni;
}

inline uint8_t add_up_to_9(BCD8* i, uint8_t a)
{
	uint8_t ni = i->value + a;
	if (((i->value & 0xf) + (a & 0xf)) > 9)
	{
		ni += 6;
	}
	return ni;
}
