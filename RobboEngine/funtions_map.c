#include <types.h>
#include <stdbool.h>
#include "globals.h"
#include "functions_map.h"
#include "monsters.h"
#include "guns.h"


const function functions_map[] =
{
	NULL, blasterR, NULL, NULL, blasterL, NULL, NULL, NULL, //0
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, blasterD, //1
	blasterU, NULL, NULL, NULL, gunU, gunD, gunL, gunR,
	
	NULL, NULL, NULL, NULL, NULL, NULL, eyes, laserD, //2
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	refreshEvery2, refreshEvery2, refreshEvery2, refreshEvery2, refreshEvery2, refreshEvery2, refreshEvery2, refreshEvery2, //3
	refreshEvery2, refreshEvery2, NULL, NULL, laserL, NULL, laserR, NULL,

	NULL, monsterLL, monsterLR, monsterLU, monsterLD, monsterRL, monsterRR, monsterRU, //4
	monsterRD, birdL, birdR, birdU, birdD, shootingL, shootingR, projectileL,

	projectileR, projectileU, projectileD, laserBeamL, laserBeamR, laserBeamU, laserBeamD, blasterHeadL, //5
	blasterHeadR, blasterHeadU, blasterHeadD, refreshEvery2, NULL, refreshEvery2, laserU, NULL,

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

bool refreshEvery2()
{
	return animCounter & 1;
}