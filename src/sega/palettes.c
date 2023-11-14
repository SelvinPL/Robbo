#include <platform.h>

#define palette1c1 RGBHTML(0xffffff)
#define palette1c2 RGBHTML(0xffaa55)
#define palette1c3 RGBHTML(0x55aa55)
#define palette1c4 RGBHTML(0x000000)

#define palette3c1 RGBHTML(0xffffc7)
#define palette3c2 RGBHTML(0xd4984a)
#define palette3c3 RGBHTML(0x4e494c)
#define palette3c4 RGBHTML(0x00303b)

#define palette8c1 RGBHTML(0xffefff)
#define palette8c2 RGBHTML(0xf7b58c)
#define palette8c3 RGBHTML(0x84739c)
#define palette8c4 RGBHTML(0x181010)

#define palette4c1 RGBHTML(0xdad3af)
#define palette4c2 RGBHTML(0xc23a73)
#define palette4c3 RGBHTML(0xd58863)
#define palette4c4 RGBHTML(0x2c1e74)

const palette_color_t palettes[] =
{
	palette1c1, palette1c2, palette1c3, palette1c4,
	palette3c1, palette3c2, palette3c3, palette3c4,
	palette8c1, palette8c2, palette8c3, palette8c4,
	palette4c1, palette4c2, palette4c3, palette4c4
};

const palette_color_t sprites_palettes[] =
{
	palette1c1, palette1c1, palette1c1, palette1c4,
};