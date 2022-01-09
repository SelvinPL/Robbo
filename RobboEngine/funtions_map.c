#include "stdbool.h"
#include "functions_map.h"
#include <types.h>
#include "globals.h"
#include "monsters.h"
#include "guns.h"
#include "others.h"
#include "changes.h"

bool robboDragLeft()
{
    return false;
}
bool robboDragRight()
{
    return false;
}

#define  forceFieldStart NULL

bool ship()
{
    return false;
}
bool shipBlink1()
{
    return false;
}
bool shipBlink2()
{
    return false;
}
bool robboStart()
{
    return false;
}
bool magnetLeft()
{
    return false;
}
bool magnetRight()
{
    return false;
}
bool robbo()
{
    return false;
}

bool bombExploding()
{
    return false;
}


bool inertBoxLeft()
{
    return false;
}
bool inertBoxRight()
{
    return false;
}
bool inertBoxUp()
{
    return false;
}
bool inertBoxDown()
{
    return false;
}
bool surpriseExplosion()
{
    return false;
}
bool teleport()
{
    return (animCounter & 1);
}

const function const functions_map[] =
{
    forceFieldEnd, robboDragLeft, robboDragRight, ship, shipBlink1, shipBlink2, robboStart, magnetLeft,
    magnetRight, projectileLeft, projectileRight, projectileUp, projectileDown, laserHeadLeft, laserHeadRight, laserHeadUp,
    laserHeadDown, blasterHeadLeft, blasterHeadRight, blasterHeadUp, blasterHeadDown, bombExploding, forceField, robbo,
    eyes, leftHandLeft, leftHandRight, leftHandUp, leftHandDown, rightHandLeft, rightHandRight, rightHandUp,
    rightHandDown, batLeft, batRight, batUp, batDown, batShootingLeft, batShootingRight, inertBoxLeft,
    inertBoxRight, inertBoxUp, inertBoxDown, surpriseExplosion, teleport, teleport, teleport, teleport,
    teleport, teleport, teleport, teleport, teleport, teleport, gunLeft, gunRight,
    gunUp, gunDown, laserLeft, laserRight, laserUp, laserDown, blasterLeft, blasterRight,
    blasterUp, blasterDown, rotatingGunLeft, rotatingGunRight, rotatingGunUp, rotatingGunDown, movableGunLeft, movableGunRight,
};