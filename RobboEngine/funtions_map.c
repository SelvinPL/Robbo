#include "stdbool.h"
#include "functions_map.h"
#include <types.h>
#include "globals.h"
#include "monsters.h"
#include "guns.h"
#include "others.h"
#include "changes.h"

bool blinkOnOdd()
{
	return (animCounter & 1);
}

const function const functions_map[] =
{
	NULL, blasterR, NULL, NULL, blasterL, forceFieldEnd, NULL, NULL, //0
	NULL, NULL, NULL, NULL, NULL, movableGunL, movableGunR, forceField,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, blasterD, //1
	blasterU, NULL, NULL, NULL, gunU, gunD, gunL, gunR,
	
	NULL, NULL, NULL, NULL, NULL, NULL, eyes, laserD, //2
	NULL, NULL, NULL, NULL, rotatingGunL, rotatingGunR, rotatingGunU, rotatingGunD,

	blinkOnOdd, blinkOnOdd, blinkOnOdd, blinkOnOdd, blinkOnOdd, blinkOnOdd, blinkOnOdd, blinkOnOdd, //3
	blinkOnOdd, blinkOnOdd, NULL, NULL, laserL, NULL, laserR, NULL,

	NULL, monsterLL, monsterLR, monsterLU, monsterLD, monsterRL, monsterRR, monsterRU, //4
	monsterRD, birdL, birdR, birdU, birdD, shootingL, shootingR, projectileL,

	projectileR, projectileU, projectileD, laserBeamL, laserBeamR, laserBeamU, laserBeamD, blasterHeadL, //5
	blasterHeadR, blasterHeadU, blasterHeadD, blinkOnOdd, NULL, blinkOnOdd, laserU, NULL,

	NULL, expolosion, expolosion, expolosion, expolosion, expolosion, expolosion, expolosion,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};