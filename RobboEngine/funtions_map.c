#include <types.h>
#include "functions_map.h"
#include "monsters.h"
#include "guns.h"

#define REFRESH1_ONLY ((function)(0x0001))
#define REFRESH2_ONLY ((function)(0x0002))

const function functions_map[] =
{
	NULL, blasterR, NULL, NULL, blasterL, NULL, NULL, NULL, //0
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, blasterD, //1
	blasterU, NULL, NULL, NULL, gunU, gunD, gunL, gunR,
	
	NULL, NULL, NULL, NULL, NULL, NULL, eyes, NULL, //2
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, laserD,

	REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, //3
	REFRESH2_ONLY, REFRESH2_ONLY, NULL, NULL, laserL, NULL, laserR, NULL,

	NULL, monsterLL, monsterLR, monsterLU, monsterLD, monsterRL, monsterRR, monsterRU, //4
	monsterRD, birdL, birdR, birdU, birdD, shootingL, shootingR, projectileL,

	projectileR, projectileU, projectileD, laserBeamL, laserBeamR, laserBeamU, laserBeamD, blasterHeadL, //5
	blasterHeadR, blasterHeadU, blasterHeadD, REFRESH2_ONLY, NULL, REFRESH2_ONLY, laserU, NULL,

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