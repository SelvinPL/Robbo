#include "stdbool.h"
#include "functions_map.h"
#include <types.h>
#include "globals.h"
#include "monsters.h"
#include "guns.h"
#include "others.h"
#include "changes.h"
#include "bombs.h"

bool robboDragLeft()
{
	return false;
}
bool robboDragRight()
{
	return false;
}

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

bool teleport()
{
	return (animCounter & 1);
}

const function const functions_map[] =
{
	NULL, NULL, NULL, NULL, NULL, forceFieldEnd, robboDragLeft, robboDragRight,
	ship, shipBlink1, shipBlink2, robboStart, magnetLeft, magnetRight, projectileLeft, projectileRight,
	projectileUp, projectileDown, laserHeadLeft, laserHeadRight, laserHeadUp, laserHeadDown, blasterHeadLeft, blasterHeadRight,
	blasterHeadUp, blasterHeadDown, bombExploding, blinkOnOdd, blinkOnOdd, forceField, robbo, eyes,
	leftHandLeft, leftHandRight, leftHandUp, leftHandDown, rightHandLeft, rightHandRight, rightHandUp, rightHandDown,
	batLeft, batRight, batUp, batDown, batShootingLeft, batShootingRight, inertBoxLeft, inertBoxRight,
	inertBoxUp, inertBoxDown, surpriseExplosion, teleport, teleport, teleport, teleport, teleport,
	teleport, teleport, teleport, teleport, teleport, gunLeft, gunRight, gunUp,
	gunDown, laserLeft, laserRight, laserUp, laserDown, blasterLeft, blasterRight, blasterUp,
	blasterDown, rotatingGun, rotatingGun, rotatingGun, rotatingGun, movableGunLeft, movableGunRight, next,
	next, next, next, next, next, next, next, next,
	next, next, next, next, next, next, next, next,
	next, next, next, next, next, next, 
};