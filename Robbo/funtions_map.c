#include "stdbool.h"
#include "functions_map.h"
#include <types.h>
#include "globals.h"
#include "monsters.h"
#include "guns.h"
#include "others.h"
#include "changes.h"
#include "bombs.h"
#include "robbo.h"

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
	next, next, next, next, next, next, screw,
};