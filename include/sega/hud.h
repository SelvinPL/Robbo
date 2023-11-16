#pragma once

#include <stdbool.h>
#include <string.h>
#include <platform.h>
#include <globals.h>
#include <robbo_state.h>
#include <uielement.h>


#define TILE_HUD_SEGA_SCREW 0x04
#define TILE_HUD_SEGA_NUM_PART0 0x18
#define drawNumber(x, y, number)

void initHUD();
void drawHUD();

static inline void disableHUD()
{
	__WRITE_VDP_REG(VDP_R10, 0xff);
	__WRITE_VDP_REG(VDP_R2, R2_MAP_0x3000);
}

inline void hideHUD()
{
	extern const uint8_t hud_sprites_y_invisible_all[];
	extern uint8_t hudVisible;
	vmemcpy(0x7f00, hud_sprites_y_invisible_all, 40);
	hudVisible = false;
}

static inline void postUICounter(uiElement type, uint8_t number);

inline void showHUD()
{
	extern const uint8_t* const hud_sprites_y[];
	extern uint8_t hudVisible;
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

extern uint8_t drawUICounterBuffer[8];
extern const uint8_t hud_sprites_x_tile[];
extern const uint8_t numbersTiles[10][2];

inline void drawUICounter(uiElement type, uint8_t number)
{
    uint8_t offset = type + 8;
    memcpy(drawUICounterBuffer, hud_sprites_x_tile + offset, 8);
    uint8_t second = number & 0xf;
    const uint8_t* tiles = numbersTiles[second];
    drawUICounterBuffer[1] = tiles[0];
    drawUICounterBuffer[3] = tiles[1];
    uint8_t first = (number >> 4) & 0xf;
    tiles = numbersTiles[first];
    drawUICounterBuffer[5] = tiles[0];
    drawUICounterBuffer[7] = tiles[1];
    vmemcpy(0x7f80 + offset, drawUICounterBuffer, 8);
}