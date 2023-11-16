#pragma once

#include <stdint.h>
#include <platform.h>

#ifdef NINTENDO
#include "gb/sound_engine.h"
#endif
#ifdef SEGA
#include "sega/sound_engine.h"
#endif

typedef struct
{
	uint8_t isPlaying;
	uint8_t* data[4];
	uint8_t counter;
} sound_state;

extern sound_state soundState;

typedef enum
{
	openExitSound = 0,
	walkSound = 1,
	nextLevelSound = 2,
	extraLifeSound = 3,
	openDoorSound = 4,
	teleportSound = 5,
	ammoSound = 6,
	screwSound = 7,
	keySound = 8,
	magnetSound = 9,
	explosionSound = 10,
	smallExplosionSound = 11,
	startLevelSound = 12,
} soundType;

void playSound(soundType sound);