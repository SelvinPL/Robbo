#include <functions_map.h>
#include <functions_monsters.h>
#include <functions_guns.h>
#include <functions_others.h>
#include <functions_bombs.h>
#include <functions_robbo.h>

#pragma bank 1

const void_function* current_functions_map;

const void_function functions_map[] =
{
    none, none, none, none, none, forceFieldEnd, robboDragLeft, robboDragRight, 
    ship, shipBlink1, shipBlink2, robboStart, magnetLeft, magnetRight, projectileLeft, projectileUp, 
    projectileRight, projectileDown, laserHeadLeft, laserHeadUp, laserHeadRight, laserHeadDown, blasterHeadLeft, blasterHeadUp, 
    blasterHeadRight, blasterHeadDown, bombExploding, blinkOnOdd, blinkOnOdd, forceField, robbo, eyes, 
    leftHandLeft, leftHandUp, leftHandRight, leftHandDown, rightHandLeft, rightHandUp, rightHandRight, rightHandDown, 
    batLeft, batRight, batUp, batDown, batShootingLeft, batShootingRight, inertBoxLeft, inertBoxUp, 
    inertBoxRight, inertBoxDown, surpriseExplosion, teleport, teleport, teleport, teleport, teleport, 
    teleport, teleport, teleport, teleport, teleport, gunLeft, gunUp, gunRight, 
    gunDown, laserLeft, laserUp, laserRight, laserDown, blasterLeft, blasterUp, blasterRight, 
    blasterDown, rotatingGun, rotatingGun, rotatingGun, rotatingGun, movableGunLeft, movableGunRight, next, 
    next, next, next, next, next, next, next, next, 
    next, next, next, next, next, next, next, next, 
    next, next, next, next, screw, none, none, none, 
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
    explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode, explode
};