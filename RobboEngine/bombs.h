#pragma once

#include <stdint.h>

extern uint8_t* bombPlacement;

void bombExplosionImpl();

#define bombExplosion(bombPlacement_) bombPlacement = bombPlacement_; bombExplosionImpl();