#pragma once

#include <platform.h>
#include <stdint.h>

BANKREF_EXTERN(tiles_data)

extern const uint8_t const main_tiles[];
extern const uint8_t* const walls_tiles[];

#define TILE_EMPTY					0x00

#define TILE_BLACK_WALL				0x04
#define TILE_WALLS_START			0x08
#define TILE_WALL					0x08
#define TILE_WALL2					0x0c

#define TILE_BOX					0x10
#define TILE_INERT_BOX				0x14
#define TILE_GROUND					0x18
#define TILE_BOMB					0x1c

#define TILE_KEY					0x20
#define TILE_SCREW					0x24
#define TILE_AMMO					0x28
#define TILE_LIFE					0x2c

#define TILE_SURPRISE				0x30
#define TILE_DOOR					0x34
#define TILE_MAGNET_RIGHT			0x38
#define TILE_MAGNET_LEFT			0x3c

#define TILE_BAT					0x40
#define TILE_BAT_SHOOTING			0x44
#define TILE_RIGHT_HAND				0x48
#define TILE_LEFT_HAND				0x4c
#define TILE_EYES					0x50

#define TILE_SHIP					0x54
#define TILE_TELEPORT				0x58
#define TILE_FORCE_FIELD			0x5c

#define TILE_BAT2					0x60
#define TILE_BAT_SHOOTING2			0x64
#define TILE_RIGHT_HAND2			0x68
#define TILE_LEFT_HAND2				0x6c
#define TILE_EYES2					0x70

#define TILE_SHIP2					0x74
#define TILE_TELEPORT2				0x78
#define TILE_FORCE_FIELD2			0x7c

#define TILE_EXPLOSION4				0x80
#define TILE_EXPLOSION3				0x84
#define TILE_EXPLOSION1				0x8c
#define TILE_EXPLOSION2				0x88

#define TILE_PROJECTILE_HORIZONTAL	0x90
#define TILE_PROJECTILE_HORIZONTAL2	0x94
#define TILE_PROJECTILE_VERTICAL	0x98
#define TILE_PROJECTILE_VERTICAL2	0x9c

#define TILE_GUN_RIGHT				0xa0
#define TILE_GUN_DOWN				0xa4
#define TILE_GUN_LEFT				0xa8
#define TILE_GUN_UP					0xac

#define TILE_GUN_UP2				0xb0

#define TILE_ROBBO					0xfc

#define TILE_ROBBO_RIGHT			0xc0
#define TILE_ROBBO_RIGHT2			0xc4
#define TILE_ROBBO_DOWN				0xc8
#define TILE_ROBBO_DOWN2			0xcc
#define TILE_ROBBO_LEFT				0xd0
#define TILE_ROBBO_LEFT2			0xd4
#define TILE_ROBBO_UP				0xd8
#define TILE_ROBBO_UP2				0xdc


#define TILE_NUM_PART0				0xb4
#define TILE_NUM_PART1				0xb5
#define TILE_NUM_PART2				0xb6
#define TILE_NUM_PART3				0xb7
#define TILE_NUM_PART4				0xb8
#define TILE_NUM_PART5				0xb9
#define TILE_NUM_PART6				0xba
#define TILE_NUM_PART7				0xbb
#define TILE_NUM_PART8				0xbc
#define TILE_NUM_PART9				0xbd
#define TILE_NUM_PARTA				0xbe
#define TILE_NUM_PARTB				0xbf
#define TILE_NUM_PARTC				0xf4


#define TILE_HUD_SCREW				0xe0
#define TILE_HUD_LIFE				0xe4
#define TILE_HUD_KEY				0xe8
#define TILE_HUD_AMMO				0xec
#define TILE_HUD_LEVEL				0xf0