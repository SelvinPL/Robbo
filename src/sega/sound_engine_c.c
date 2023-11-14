#include <stdint.h>
#include <platform.h>
#include <sound_engine.h>

extern const uint8_t* const sounds[];

uint8_t* segaSoundPtr = NULL;

void playSound(soundType sound)
{
    segaSoundPtr = sounds[sound];
}

void loopSound()
{
    if(segaSoundPtr != NULL)
    {
        uint8_t volume = *segaSoundPtr;
        PSG = PSG_LATCH | PSG_VOLUME | (volume & 0xf);
        segaSoundPtr++;
        if((volume & 0xf0) == 0x20)
        {
            PSG = PSG_LATCH | *segaSoundPtr;
            segaSoundPtr++;
            PSG = *segaSoundPtr;
            segaSoundPtr++;
        }
        if(*segaSoundPtr == 0xff)
            segaSoundPtr = NULL;
    }
}

