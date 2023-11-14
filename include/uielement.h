#pragma once

#ifdef NINTENDO
#include "gb/uielement.h"
#endif
#ifdef SEGA
#include "sega/uielement.h"
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