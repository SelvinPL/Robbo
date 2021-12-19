#include <types.h>
#include "functions_map.h"
#include "monsters.h"
#include "guns.h"

#define REFRESH1_ONLY ((function)(0x0001))
#define REFRESH2_ONLY ((function)(0x0002))

const function functions_map[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, //0
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, //1
	NULL, NULL, NULL, NULL, NULL, NULL, gunL, gunR,
	
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, //2
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, REFRESH2_ONLY, //3
	REFRESH2_ONLY, REFRESH2_ONLY, NULL, NULL, laserL, NULL, laserR, NULL,

	NULL, monsterLL, monsterLR, monsterLU, monsterLD, monsterRL, monsterRR, monsterRU, //4
	monsterRD, NULL, NULL, NULL, NULL, NULL, NULL, projectileL,

	projectileR, NULL, NULL, laserBeamL, laserBeamR, NULL, NULL, NULL, //5
	NULL, NULL, NULL, NULL, NULL, REFRESH2_ONLY, NULL, NULL,

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