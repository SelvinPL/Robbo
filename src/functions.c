#include <types.h>
#include <stdint.h>
#include <functions_map.h>
#include <functions_monsters.h>
#include <functions_guns.h>
#include <functions_others.h>
#include <functions_bombs.h>
#include <functions_robbo.h>

#pragma bank 1

const void_function functions_map[] =
{
    none, none, none, none, none, forceFieldEnd, robboDragLeft, robboDragRight, 
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
    next, next, next, next, none, none, none, none, 
    none, none, none, none, none, none,
};

const void_function functions_map_room_exploding[] = 
{
	none, none, none, none, none, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, next,
    next, next, next, next, next, next, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode,
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode
};

const uint8_t types[] =
{
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
    0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
};