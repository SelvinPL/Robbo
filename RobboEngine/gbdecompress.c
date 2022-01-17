#include "platform.h"

#ifndef  GAMEBOY
#include <stdlib.h>
#include <gbdk/gbdecompress.h>

void gb_decompress_bkg_data(uint16_t start, const uint8_t* source)
{
	uint8_t heap[4096];
	uint16_t res = gb_decompress(source, heap);
	CRITICAL
	{
		set_bkg_data(start, res / 16, heap);
	}
}
#endif