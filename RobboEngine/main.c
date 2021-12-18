#include <gb/gb.h>
#include <string.h>
#include "tiles.h"
#include <gb/cgb.h>
#include "fields.h"
#include "functions_map.h"
#include "map.h"
#include "hi_ram_globals.h"


const uint8_t const map_to_tiles1[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1, 
	tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left,
	tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right,
	tiles_trans_pickable_screw, tiles_missle_horizontal, tiles_missle_horizontal, tiles_missle_horizontal, tiles_trans_gun_right
};

const uint8_t const map_to_tiles2[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1, 
	tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2,
	tiles_trans_pickable_screw, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_trans_gun_right
};

extern void mapIterationASM();
extern void mapIterationC();

//#define mapIteration mapIterationASM
#define mapIteration mapIterationC

extern uint8_t chaneges[];

#define BETWEEN(n, start, end) (((n)>=((uint8_t)(start))) && ((n)<=((uint8_t)(end))))

extern void set_bkg_tile_xy_2(uint8_t x, uint8_t y, uint8_t t) OLDCALL;

void mapIterationC()
{
	chanegesPtr = chaneges;
	for (iterY = changeYstart; iterY < changeYend; iterY++)
	{
		doChanege = BETWEEN(iterY, map_pos_y == 0 ? 0 : map_pos_y - 1, map_pos_y + 9);
		y_next_tilesPtr = y_next_tiles - 1;
		for (iterX = 0; iterX < 16; iterX++)
		{
			y_next_tilesPtr++;
			if (*++mapPtr == FIELD_WALL)
			{
				continue;
			}
			else if (*mapPtr == FIELD_EMPTY)
			{
				if (*y_next_tilesPtr != FIELD_NONE)
				{
					*mapPtr = *y_next_tilesPtr;
					*y_next_tilesPtr = FIELD_NONE;
					if (doChanege)
					{
						*chanegesPtr++ = iterX;
						*chanegesPtr++ = iterY;
					}
				}
				else if (x_next_tile != FIELD_NONE)
				{
					*mapPtr = x_next_tile;
					x_next_tile = FIELD_NONE;
					if (doChanege)
					{
						*chanegesPtr++ = iterX;
						*chanegesPtr++ = iterY;
					}
				}
				continue;
			}
			else
			{
				function function = functions_map[*mapPtr];
				uint8_t hi = (((uint16_t)function) >> 8) && 0xff;
				if (hi == 0)
				{
					uint8_t low = ((uint8_t)function);
					if (low == 0)
					{
						continue;
					}
					else if(doChanege)
					{
						*chanegesPtr++ = iterX;
						*chanegesPtr++ = iterY;
					}
				}
				else
				{
					function();
					if (doChanege)
					{
						*chanegesPtr++ = iterX;
						*chanegesPtr++ = iterY;
					}
				}
			}
		}
	}
	*chanegesPtr = 0xff;
}

const __at(0x40) uint8_t vblank_isr[] = { 0xd9, 0, 0, 0, 0, 0, 0, 0 };

#define wait_vbl_done()	\
	__asm__("	halt");	\
	__asm__("	nop");


void repaint()
{
	uint8_t* change = chaneges;
	while (*change != 0xff)
	{
		uint8_t ux = *change++;
		uint8_t uy = *change++;
		set_bkg_tile_xy_2(ux, uy, map_to_tiles[map[ux + uy * 16]]);
	}

}

void incrementCounter()
{
	counter++;
	if (counter == 1)
	{
		changeYstart = 6;
		changeYend = 12;
		uint8_t pad = joypad();
		if (pad == J_LEFT && map_pos_x > 0)
		{
			map_pos_x--;
			slideX = -4;
			SCX_REG -= 4;
		}
		else if (pad == J_RIGHT && map_pos_x < 6)
		{
			map_pos_x++;
			slideX = 4;
			SCX_REG += 4;
		} 
		else if (pad == J_UP && map_pos_y > 0)
		{
			slideY = -4;
			SCY_REG -= 4;
			map_pos_y--;

		}
		else if (pad == J_DOWN && map_pos_y < (31 - 9))
		{
			slideY = 4;
			SCY_REG += 4;
			map_pos_y++;
		}
	}
	else if (counter == 2)
	{
		changeYstart = 12;
		changeYend = 18;
		if(slideX)
			SCX_REG += slideX;
		if (slideY)
		{
			SCY_REG += slideY;
			if (slideY > 0)
			{
				uint8_t y = map_pos_y + 9;
				for (uint8_t x = 0; x < 16; x++)
				{
					*chanegesPtr++ = x;
					*chanegesPtr++ = y;
				}
				*chanegesPtr = 0xff;
			}
			else if (map_pos_y != 0)
			{
				uint8_t y = map_pos_y - 1;
				for (uint8_t x = 0; x < 16; x++)
				{
					*chanegesPtr++ = x;
					*chanegesPtr++ = y;
				}
				*chanegesPtr = 0xff;
			}
		}
	}
	else if (counter == 3)
	{
		changeYstart = 18;
		changeYend = 24;
		if (slideX)
			SCX_REG += slideX;
		if (slideY)
			SCY_REG += slideY;
	}
	else if (counter == 4)
	{
		changeYstart = 24;
		changeYend = 32;
		if (slideX)
		{
			SCX_REG += slideX;
			slideX = 0;
		}
		if (slideY)
		{
			SCY_REG += slideY;
			slideY = 0;
		}
	}
	else
	{
		changeYstart = 0;
		changeYend = 6;
		counter = 0;
		mapPtr = map - 1;

		anim_counter++;
		if (anim_counter == 2)
		{
			map_to_tiles = map_to_tiles2;
		}
		else  if (anim_counter == 4)
		{
			map_to_tiles = map_to_tiles1;
			anim_counter = 0;
		}
		
	}
}

void main()
{
	DISPLAY_OFF;
	SHOW_BKG;
	set_bkg_data(0, 172, map_tiles);
	set_bkg_data(0xc0, 0xd7 - 0xc0, map_tiles + 0xc0 * 16);
	memcpy(map, map1, 512);
	memset(y_next_tiles, FIELD_NONE, 16);
	anim_counter = 0;
	map_to_tiles = map_to_tiles1;
	//map_pos_x = 3;
	//map_pos_y = 9;
	map_pos_x = 0;
	map_pos_y = 22;
	counter = 255;
	slideX = 0;
	slideY = 0;
	changeYstart = 0;
	changeYend = 6;
	x_next_tile = FIELD_NONE;
	mapPtr = map - 1;
	*chaneges = 0xff;
	SCX_REG = map_pos_x * 16;
	SCY_REG = map_pos_y * 16;
	for (uint8_t y = map_pos_y == 0 ? 0 : map_pos_y - 1; y < map_pos_y + 10; y++)
	{
		for (uint8_t x = 0; x < 16; x++)
		{
			set_bkg_tile_xy_2(x, y, map_to_tiles[map[x + y * 16]]);
		}
	}
	DISPLAY_ON;
	while (TRUE)
	{
		wait_vbl_done();
		incrementCounter();
		repaint();
		mapIteration();
	}
}