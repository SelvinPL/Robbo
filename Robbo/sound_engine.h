#pragma once

#include <stdint.h>
#include "platform.h"


typedef struct
{
	uint8_t isPlaying;
	uint8_t* data[4];
	uint8_t counter;
} sound_state;

extern sound_state soundState;

#ifdef GAMEBOY

extern void timerSoundProc();
extern void initSound();
extern void playSound(const uint8_t* sound);

#else

#define timerSoundProc()
#define initSound()
#define playSound(sound)

#endif

inline void loopSound()
{
	if (++soundState.counter == 4)
	{
		soundState.counter = 0;
		if (soundState.isPlaying)
			timerSoundProc();
	}
}

extern const uint8_t openExitSound[];
extern const uint8_t walkSound[];
extern const uint8_t nextLevelSound[];
extern const uint8_t extraLifeSound[];
extern const uint8_t openDoorSound[];
extern const uint8_t teleportSound[];
extern const uint8_t ammoSound[];
extern const uint8_t screwSound[];
extern const uint8_t keySound[];
extern const uint8_t magnetSound[];
extern const uint8_t explosionSound[];