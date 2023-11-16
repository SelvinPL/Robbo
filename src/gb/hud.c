#pragma bank 1

#include <stdint.h>
#include <hud.h>
#include <tiles_definition.h>
#include <robbo_state.h>

const uint8_t uiElementsTiles[] =
{
    //screws
    TILE_HUD_SCREW, TILE_HUD_SCREW + 1, TILE_HUD_SCREW + 2, TILE_HUD_SCREW + 3,
    //lives
    TILE_HUD_LIFE, TILE_HUD_LIFE + 1, TILE_HUD_LIFE + 2, TILE_HUD_LIFE + 3,
    //keys
    TILE_HUD_KEY, TILE_HUD_KEY + 1, TILE_HUD_KEY + 2, TILE_HUD_KEY + 3,
    //ammo
    TILE_HUD_AMMO, TILE_HUD_AMMO + 1, TILE_HUD_AMMO + 2, TILE_HUD_AMMO + 3,
    //level
    TILE_HUD_LEVEL, TILE_HUD_LEVEL + 1, TILE_HUD_LEVEL + 2, TILE_HUD_LEVEL + 3,
};

const uint8_t numbersTiles[10][2] =
{
    { TILE_NUM_PART0, TILE_NUM_PART1 }, //0
    { TILE_NUM_PART2, TILE_NUM_PART3 }, //1
    { TILE_NUM_PARTB, TILE_NUM_PART5 }, //2
    { TILE_NUM_PARTB, TILE_NUM_PART6 }, //3
    { TILE_NUM_PART7, TILE_NUM_PART8 }, //4
    { TILE_NUM_PART9, TILE_NUM_PART6 }, //5
    { TILE_NUM_PART9, TILE_NUM_PARTA }, //6
    { TILE_NUM_PART4, TILE_NUM_PART3 }, //7
    { TILE_NUM_PARTC, TILE_NUM_PARTA }, //8
    { TILE_NUM_PARTC, TILE_NUM_PART6 }, //9
};

void drawNumber(uint8_t x, uint8_t y, uint8_t number)
{
    set_win_tiles(x, y, 1, 2, numbersTiles[(number >> 4) & 0xf]);
    set_win_tiles(x + 1, y, 1, 2, numbersTiles[number & 0xf]);
}

void showHUD()
{
    move_win(7, 128);

    drawUIElement(uiElementScrews);
    postUICounter(uiElementScrews, robboState.screws.value);

    drawUIElement(uiElementLives);
    postUICounter(uiElementLives, robboState.lives.value);

    drawUIElement(uiElementKeys);
    postUICounter(uiElementKeys, robboState.keys.value);

    drawUIElement(uiElementAmmo);
    postUICounter(uiElementAmmo, robboState.ammo.value);

    drawUIElement(uiElementLevel);
    postUICounter(uiElementLevel, level.value);
}

void drawHUD()
{
    drawHUDCommon();
}