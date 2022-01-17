#pragma once

#include <gbdk/gbdecompress.h>

#ifndef GAMEBOY
void gb_decompress_bkg_data(uint16_t start, const uint8_t* source);
#endif
