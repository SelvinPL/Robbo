#include <stdint.h>
#include <gbdk/gbdecompress.h>
#include <platform.h>

void gb_decompress_bkg_data(uint16_t start, const uint8_t* source)
{
	uint8_t heap[4096];
	uint16_t res = gb_decompress(source, heap);
	CRITICAL
	{
		set_bkg_data(start, res / 16, heap);
	}
}

void gb_decompress_sprite_data(uint16_t start, const uint8_t* source)
{
	uint8_t heap[4096];
	uint16_t res = gb_decompress(source, heap);
	CRITICAL
	{
		set_sprite_data(start, res / 16, heap);
	}
}