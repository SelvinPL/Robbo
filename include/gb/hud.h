#pragma once

#include <platform.h>
#include <tiles_definition.h>
#include <globals.h>
#include <robbo_state.h>
#include <uielement.h>

void drawNumber(uint8_t x, uint8_t y, uint8_t number);

inline void drawUIElement(uiElement element)
{
	extern const uint8_t uiElementsTiles[20];
	set_win_tiles(element, 0, 2, 2, &uiElementsTiles[element]);
}

static inline void initHUDCommon();

static inline void initHUD()
{
	init_win(TILE_BLACK_WALL);
	WX_REG = 7;
	WY_REG = sliderYPos;
	SHOW_WIN;
	initHUDCommon();
	drawNumber(9, 8, level.value);
}
#define	disableHUD()

void drawHUD();
void showHUD();

inline void hideHUD()
{
	fill_win_rect(0, 0, 20, 2, TILE_BLACK_WALL);
}

extern const uint8_t numbersTiles[10][2];

inline void drawUICounter(uiElement type, uint8_t number)
{
    set_win_tiles(type + 2, 0, 1, 2, numbersTiles[(number >> 4) & 0xf]);
    set_win_tiles(type + 3, 0, 1, 2, numbersTiles[number & 0xf]);
}