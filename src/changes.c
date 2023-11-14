#include <stdint.h>
#include <types.h>
#include <globals.h>
#include <platform.h>
#include <changes.h>

uint8_t** changesPtr = NULL;


void change(uint8_t* map)
{
	uint8_t y = (((uint16_t)map) >> 4) & 0x1fU;
	if (y >= (map_pos_y == 0U ? 0U : (uint8_t)(map_pos_y - 1)) && y < (map_pos_y + (visibleY + 1)))
	{
		PUT_CHANGES(map);
	}
}