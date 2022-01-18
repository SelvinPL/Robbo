#include "platform.h"

#ifdef GAMEBOY
#define palette1c1 RGBHTML(0xa8a8a8)
#define palette1c2 RGBHTML(0xbf7a19)
#define palette1c3 RGBHTML(0x208020)
#define palette1c4 RGBHTML(0x000000)
#else
#define palette1c1 RGBHTML(0xffffff)
#define palette1c2 RGBHTML(0xffaa55)
#define palette1c3 RGBHTML(0x55aa55)
#define palette1c4 RGBHTML(0x000000)
#endif

const palette_color_t palettes[] =
{
	palette1c1, palette1c2, palette1c3, palette1c4,
};