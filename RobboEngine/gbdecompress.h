#pragma once

#include <gbdk/gbdecompress.h>

#ifdef SEGA
void gb_decompress_bkg_data(uint16_t start, const uint8_t* source);
void gb_decompress_sprite_data(uint16_t start, const uint8_t* source);
#endif
