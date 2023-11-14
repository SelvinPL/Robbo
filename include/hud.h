#pragma once

#include <platform.h>
#include <tiles.h>
#include <globals.h>
#include <robbo_state.h>
#include <uielement.h>

#ifdef NINTENDO
#include <gb/hud.h>
#endif
#ifdef SEGA
#include <sega/hud.h>
#endif 

extern uint8_t* uiCountersPtr;
extern uint8_t uiCounters[20];

static inline void initHUDCommon()
{
	uiCountersPtr = uiCounters;
	*uiCountersPtr = uiElementNone;
}

static inline void postUICounter(uiElement type, uint8_t number)
{
	*uiCountersPtr++ = type;
	*uiCountersPtr++ = number;
	*uiCountersPtr = uiElementNone;
}

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