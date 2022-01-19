#pragma once

#include "platform.h"
#include "tiles.h"
#include "globals.h"
#include "gbdecompress.h"

#ifdef GAMEBOY
typedef enum
{
	uiElementScrews = 0,
	uiElementLives = 4,
	uiElementKeys = 8,
	uiElementAmmo = 12,
	uiElementLevel = 16,
} uiElement;

void drawNumber(uint8_t x, uint8_t y, uint8_t number);
void drawUICounter(uiElement type, uint8_t number);

inline void drawUIElement(uint8_t x, uint8_t y, uiElement element)
{
	extern const uint8_t uiElementsTiles[20];
	set_win_tiles(x, y, 2, 2, &uiElementsTiles[element]);
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
	move_win(7, 128);

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
#define TILE_HUD_SEGA_SCREW 0x04
#define TILE_HUD_SEGA_NUM_PART0 0x18

void initHUD();
void drawHUD();

#define drawNumber(x, y, number)

inline void disableHUD()
{
	__WRITE_VDP_REG(VDP_R10, 0xff);
	__WRITE_VDP_REG(VDP_R2, R2_MAP_0x3000);
}

inline void hideHUD()
{
	extern const uint8_t hud_sprites_y_invisible_all[];
	extern bool hudVisible;
	vmemcpy(0x7f00, hud_sprites_y_invisible_all, 40);
	hudVisible = false;
}
inline void showHUD()
{
	extern const uint8_t* const hud_sprites_y[];
	extern bool hudVisible;
	extern uint8_t hudCounter;
	vmemcpy(0x7f20, hud_sprites_y[0], 8);
	hudVisible = true;
	hudCounter = 0;
}
#endif