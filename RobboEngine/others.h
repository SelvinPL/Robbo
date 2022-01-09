#pragma once

#include "stdbool.h"
#include "globals.h"
#include "fields.h"

bool forceField();
bool forceFieldEnd();

extern const uint8_t const nextField[];

inline bool blinkOnOdd()
{
    return (animCounter & 1);
}

inline bool next()
{
    if (animCounter & 1)
    {
        *mapPtr = nextField[*mapPtr - FIELD_TYPES_NEXT_START];
        return true;
    }
    return false;
}