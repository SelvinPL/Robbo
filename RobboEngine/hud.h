#pragma once
#include "platform.h"
#include "tiles.h"
#include "globals.h"
#include "stats.h"

#ifdef GAMEBOY
typedef enum
{
	uiElementScrews = 0,
	uiElementLives = 4,
	uiElementKeys = 8,
	uiElementAmmo = 12,
	uiElementLevel = 16,
} uiElement;

inline void drawUIElement(uint8_t x, uint8_t y, uiElement element)
{
	extern const uint8_t uiElementsTiles[20];
	set_win_tiles(x, y, 2, 2, &uiElementsTiles[element]);
}

void drawUICounter(uiElement type, uint8_t number)
{
	set_win_tiles(type + 2, 0, 1, 2, numbersTiles[(number >> 4) & 0xf]);
	set_win_tiles(type + 3, 0, 1, 2, numbersTiles[number & 0xf]);
}

inline void initHUD()
{
	init_win(TILE_BLACK_WALL);
	WX_REG = 7;
	WY_REG = sliderYPos;
	SHOW_WIN;
	drawNumber(9, 8, level);
}
#define	disableHUD()
inline void drawHUD()
{
}
inline void hideHUD()
{
	fill_win_rect(0, 0, 20, 2, TILE_BLACK_WALL);
}
inline void showHUD()
{
	drawUIElement(0, 0, uiElementScrews);
	drawUICounter(uiElementScrews, 0);

	drawUIElement(4, 0, uiElementLives);
	drawUICounter(uiElementLives, 0);

	drawUIElement(8, 0, uiElementKeys);
	drawUICounter(uiElementKeys, 0);

	drawUIElement(12, 0, uiElementAmmo);
	drawUICounter(uiElementAmmo, 0);

	drawUIElement(16, 0, uiElementLevel);
	drawUICounter(uiElementLevel, level);
}
#else
extern const uint8_t tile2_data[];
extern const uint8_t sega_hud_tiles[];
extern const uint8_t hud_sprites_y_invisible_all[];
extern const uint8_t hud_sprites_y_visible_all[];
extern const uint8_t* const hud_sprites_y[];
extern const uint8_t hud_sprites_y_size[];
extern const uint16_t hud_sprites_y_start[];
extern const uint8_t hud_sprites_x_tile[];
bool hudVisible = false;
uint8_t hudCounter = 0;

#define TILE_HUD_SEGA_SCREW 0x04
#define TILE_HUD_SEGA_NUM_PART0 0x08
void initHUD()
{
	gb_decompress_sprite_data(0, sega_hud_tiles);
	vmemcpy(0x7f00, hud_sprites_y_invisible_all, 40);
	vmemcpy(0x7f80, hud_sprites_x_tile, 80);
	for (uint8_t c = 0; c < 112; c++)
	{
		vmemcpy(0x7000 + c * 16, tile2_data, 16);
	}
	uint8_t state = __READ_VDP_REG(VDP_R0);
	state |= R0_IE1;
	__WRITE_VDP_REG(VDP_R0, state);
	__WRITE_VDP_REG(VDP_R10, 175U - fixY);
}
inline void disableHUD()
{
	__WRITE_VDP_REG(VDP_R10, 0xff);
	__WRITE_VDP_REG(VDP_R2, R2_MAP_0x3000);
}
 void drawHUD()
{
	__WRITE_VDP_REG(VDP_R2, R2_MAP_0x3800);
	if (counter == 3 && animCounter == 7 && hudVisible)
	{
		vmemcpy(hud_sprites_y_start[hudCounter], hud_sprites_y[hudCounter], hud_sprites_y_size[hudCounter]);
		hudCounter++;
		if (hudCounter == 3)
			hudCounter = 0;
	}
}
inline void hideHUD()
{
	vmemcpy(0x7f00, hud_sprites_y_invisible_all, 40);
	hudVisible = false;
}
inline void showHUD()
{
	vmemcpy(0x7f20, hud_sprites_y[0], 8);
	hudVisible = true;
	hudCounter = 0;
}
#endif