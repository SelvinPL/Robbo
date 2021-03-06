#include <stdint.h>
#include "hud.h"
#include "tiles.h"
#include "BCD8.h"
#include "robbo_state.h"
#include <string.h>


uint8_t* uiCountersPtr;
uint8_t uiCounters[20];

#ifdef SEGA

const uint8_t tile2_data[] =
{
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
    TILE_BLACK_WALL, 0, TILE_BLACK_WALL, 0,
};

const uint8_t sega_hud_tiles[] =
{
    0x3f, 0x00, 0x85, 0xc0, 0xff, 0xc6, 0x3f, 0x00, 0x3a, 0x00, 0x3d, 0x00, 0x3f, 0x88, 0xb3, 0xff,
    0xca, 0xfc, 0x00, 0xa4, 0x00, 0x54, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x0f, 0x83, 0xfc, 0xff, 0x86,
    0xf8, 0xff, 0xc4, 0x03, 0x00, 0x00, 0x00, 0xd0, 0x83, 0xfc, 0xff, 0x86, 0xf8, 0xff, 0xff, 0x40,
    0x00, 0x00, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x19, 0x00, 0x1f, 0x00, 0x1f,
    0x00, 0x00, 0x00, 0x30, 0x00, 0x60, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x30, 0x00, 0xf0, 0x00, 0xf0,
    0x00, 0x00, 0x00, 0x5f, 0x00, 0xcf, 0x00, 0xd7, 0x00, 0xca, 0x00, 0x15, 0x00, 0x00, 0x00, 0x1c,
    0x00, 0x3c, 0x00, 0xf4, 0x00, 0xf6, 0x00, 0xf6, 0x00, 0xa6, 0x00, 0x50, 0x00, 0x00, 0x00, 0xc2,
    0x70, 0x00, 0x78, 0x88, 0x41, 0xff, 0xc6, 0x0e, 0x00, 0x1f, 0x00, 0x3b, 0x00, 0x71, 0x8a, 0x31,
    0xff, 0xce, 0x0a, 0x00, 0x8a, 0x00, 0xfe, 0x00, 0x60, 0x00, 0x71, 0x00, 0x3b, 0x00, 0x1f, 0x00,
    0x0e, 0x86, 0x17, 0xff, 0xc4, 0xfe, 0x00, 0xfe, 0x00, 0x80, 0x98, 0x0b, 0xff, 0x83, 0x52, 0xff,
    0x89, 0xee, 0xfe, 0xdc, 0x08, 0x00, 0xfe, 0x00, 0x10, 0x00, 0x0f, 0x00, 0x3f, 0x00, 0x3e, 0x00,
    0x7c, 0x00, 0x7f, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0xfe, 0x00, 0xa0, 0x00,
    0x40, 0x8a, 0xba, 0xff, 0xca, 0x0f, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x77, 0x00, 0x7e, 0x00, 0x55,
    0x84, 0x76, 0xff, 0xe2, 0xd6, 0x00, 0xc6, 0x00, 0xac, 0x00, 0x5c, 0x00, 0xb8, 0x00, 0x74, 0x00,
    0x7a, 0x00, 0x75, 0x00, 0x2b, 0x00, 0x57, 0x00, 0xae, 0x00, 0xfd, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0xe8, 0x00, 0xd4, 0x00, 0xa8, 0x00, 0x50, 0x84, 0xbe, 0xff, 0x85, 0x84, 0xfe, 0xc2, 0x7c, 0x00,
    0xba, 0x43, 0x00, 0xc6, 0xc5, 0x00, 0x82, 0x00, 0x00, 0x00, 0x82, 0x88, 0xf2, 0xff, 0xc0, 0xba,
    0x84, 0x8e, 0xff, 0x83, 0x8c, 0xff, 0x43, 0x06, 0x00, 0xc0, 0x02, 0x8d, 0xf2, 0xff, 0x86, 0xc0,
    0xff, 0xc0, 0x3a, 0x8a, 0xe0, 0xff, 0xc2, 0x7c, 0x00, 0xb8, 0x43, 0x00, 0xc0, 0xc3, 0x00, 0xb8,
    0x00, 0x7c, 0x8c, 0xe2, 0xff, 0xc0, 0x3a, 0x86, 0xb0, 0xff, 0x8d, 0x9e, 0xff, 0x8b, 0xc2, 0xff,
    0x85, 0x70, 0xff, 0x8d, 0xbe, 0xff, 0x89, 0x62, 0xff, 0x85, 0x70, 0xff, 0x8d, 0xae, 0xff, 0x8d,
    0x40, 0xff, 0xc1, 0xba, 0x00, 0x00,
};

const uint8_t hud_sprites_y_invisible_all[] =
{
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
};

const uint8_t hud_sprites_y_visible_all[] =
{
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
};

const uint8_t hud_sprites_y1[] =
{
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
};
const uint8_t hud_sprites_y2[] =
{
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
    hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8, hudY, hudY + 8,
};

const uint8_t hud_sprites_y3[] =
{
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
    0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
};

const uint8_t* const hud_sprites_y[] = 
{
    hud_sprites_y1, hud_sprites_y2, hud_sprites_y3
};

const uint8_t hud_sprites_y_size[] =
{
    16,
    32, 
    16,
};

const uint16_t hud_sprites_y_start[] =
{
    0x7f00,
    0x7f00,
    0x7f10
};

bool hudVisible = false;
uint8_t hudCounter = 0;

/*
sprite order:
T0T1T2T3B0B1A0A1
where: TILE_HUD_SEGA_NUM_PART0 + 0x
    TX is ui element graphical title
    AX  is 2nd digit
    BX  is 1st digit
*/

const uint8_t numbersTiles[10][2] =
{
    { TILE_HUD_SEGA_NUM_PART0 + 0x0, TILE_HUD_SEGA_NUM_PART0 + 0x1 }, //0
    { TILE_HUD_SEGA_NUM_PART0 + 0x2, TILE_HUD_SEGA_NUM_PART0 + 0x3 }, //1
    { TILE_HUD_SEGA_NUM_PART0 + 0xB, TILE_HUD_SEGA_NUM_PART0 + 0x5 }, //2
    { TILE_HUD_SEGA_NUM_PART0 + 0xB, TILE_HUD_SEGA_NUM_PART0 + 0x6 }, //3
    { TILE_HUD_SEGA_NUM_PART0 + 0x7, TILE_HUD_SEGA_NUM_PART0 + 0x8 }, //4
    { TILE_HUD_SEGA_NUM_PART0 + 0x9, TILE_HUD_SEGA_NUM_PART0 + 0x6 }, //5
    { TILE_HUD_SEGA_NUM_PART0 + 0x9, TILE_HUD_SEGA_NUM_PART0 + 0xA }, //6
    { TILE_HUD_SEGA_NUM_PART0 + 0x4, TILE_HUD_SEGA_NUM_PART0 + 0x3 }, //7
    { TILE_HUD_SEGA_NUM_PART0 + 0xC, TILE_HUD_SEGA_NUM_PART0 + 0xA }, //8
    { TILE_HUD_SEGA_NUM_PART0 + 0xC, TILE_HUD_SEGA_NUM_PART0 + 0x6 }, //9
};

const uint8_t hud_sprites_x_tile[] =
{
    hudX + 0, TILE_HUD_SEGA_SCREW + 0, hudX + 0, TILE_HUD_SEGA_SCREW + 2, hudX + 8, TILE_HUD_SEGA_SCREW + 1, hudX + 8, TILE_HUD_SEGA_SCREW + 3,
    hudX + 24, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 24, TILE_HUD_SEGA_NUM_PART0 + 1, hudX + 16, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 16, TILE_HUD_SEGA_NUM_PART0 + 1,
    hudX + 32, TILE_HUD_SEGA_SCREW + 4, hudX + 32, TILE_HUD_SEGA_SCREW + 6, hudX + 40, TILE_HUD_SEGA_SCREW + 5, hudX + 40, TILE_HUD_SEGA_SCREW + 7,
    hudX + 56, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 56, TILE_HUD_SEGA_NUM_PART0 + 1, hudX + 48, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 48, TILE_HUD_SEGA_NUM_PART0 + 1,
    hudX + 64, TILE_HUD_SEGA_SCREW + 8, hudX + 64, TILE_HUD_SEGA_SCREW + 10, hudX + 72, TILE_HUD_SEGA_SCREW + 9, hudX + 72, TILE_HUD_SEGA_SCREW + 11,
    hudX + 88, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 88, TILE_HUD_SEGA_NUM_PART0 + 1, hudX + 80, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 80, TILE_HUD_SEGA_NUM_PART0 + 1,
    hudX + 96, TILE_HUD_SEGA_SCREW + 12, hudX + 96, TILE_HUD_SEGA_SCREW + 14, hudX + 104, TILE_HUD_SEGA_SCREW + 13, hudX + 104, TILE_HUD_SEGA_SCREW + 15,
    hudX + 120, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 120, TILE_HUD_SEGA_NUM_PART0 + 1, hudX + 112, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 112, TILE_HUD_SEGA_NUM_PART0 + 1,
    hudX + 128, TILE_HUD_SEGA_SCREW + 16, hudX + 128, TILE_HUD_SEGA_SCREW + 18, hudX + 136, TILE_HUD_SEGA_SCREW + 17, hudX + 136, TILE_HUD_SEGA_SCREW + 19,
    hudX + 152, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 152, TILE_HUD_SEGA_NUM_PART0 + 1, hudX + 144, TILE_HUD_SEGA_NUM_PART0 + 0, hudX + 144, TILE_HUD_SEGA_NUM_PART0 + 1,
};

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
    initHUDCommon();
}

uint8_t drawUICounterBuffer[8];

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

#else

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

inline void drawUICounter(uiElement type, uint8_t number)
{
    set_win_tiles(type + 2, 0, 1, 2, numbersTiles[(number >> 4) & 0xf]);
    set_win_tiles(type + 3, 0, 1, 2, numbersTiles[number & 0xf]);
}

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

#endif


inline void drawHUDCommon()
{
    uint8_t* ptr = uiCounters;
    while (*ptr != uiElementNone)
    {
        uiElement elem = (uiElement)*ptr++;
        uint8_t value = *ptr++;
        drawUICounter(elem, value);
    }
    uiCountersPtr = uiCounters;
    *uiCountersPtr = uiElementNone;
}


#ifdef SEGA

uint8_t hudDalayCounter = 0;

void drawHUD()
{
    __WRITE_VDP_REG(VDP_R2, R2_MAP_0x3800);
    if (hudVisible && counter == 3 && animCounter == 7)
    {
        if (hudDalayCounter == 1)
        {
            vmemcpy(hud_sprites_y_start[hudCounter], hud_sprites_y[hudCounter], hud_sprites_y_size[hudCounter]);
            hudCounter++;
            if (hudCounter == 3)
                hudCounter = 0;
            hudDalayCounter = 0;
        }
        else
        {
            hudDalayCounter++;
        }
    }
    drawHUDCommon();
}

#else

void drawHUD()
{
    drawHUDCommon();
}

#endif