#pragma once

#include "platform.h"
#include "tiles.h"
#include "globals.h"
#include "gbdecompress.h"
#include "robbo_state.h"

#ifdef GAMEBOY
#define UI_ELEMENT_MULTIPLIER 4
#else
#define UI_ELEMENT_MULTIPLIER 16
#endif 

typedef enum
{
	uiElementScrews = (0 * UI_ELEMENT_MULTIPLIER),
	uiElementLives = (1 * UI_ELEMENT_MULTIPLIER),
	uiElementKeys = (2 * UI_ELEMENT_MULTIPLIER),
	uiElementAmmo = (3 * UI_ELEMENT_MULTIPLIER),
	uiElementLevel = (4 * UI_ELEMENT_MULTIPLIER),
	uiElementNone = 0xff
} uiElement;

extern uint8_t* uiCountersPtr;
extern uint8_t uiCounters[20];

inline void initHUDCommon()
{
	uiCountersPtr = uiCounters;
	*uiCountersPtr = uiElementNone;
}

inline void postUICounter(uiElement type, uint8_t number)
{
	*uiCountersPtr++ = type;
	*uiCountersPtr++ = number;
	*uiCountersPtr = uiElementNone;
}

#ifdef GAMEBOY

void drawNumber(uint8_t x, uint8_t y, uint8_t number);

inline void drawUIElement(uiElement element)
{
	extern const uint8_t uiElementsTiles[20];
	set_win_tiles(element, 0, 2, 2, &uiElementsTiles[element]);
}

inline void initHUD()
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

#else
#define TILE_HUD_SEGA_SCREW 0x04
#define TILE_HUD_SEGA_NUM_PART0 0x18
#define drawNumber(x, y, number)

void initHUD();
void drawHUD();

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
	postUICounter(uiElementScrews, robboState.screws.value);
	postUICounter(uiElementLives, robboState.lives.value);
	postUICounter(uiElementKeys, robboState.keys.value);
	postUICounter(uiElementAmmo, robboState.ammo.value);
	postUICounter(uiElementLevel, level.value);
}

#endif