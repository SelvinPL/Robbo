#pragma once
#include "platform.h"
#include <stdint.h>

BANKREF_EXTERN(tiles_data)

extern const uint8_t const map_tiles[];

#define TILE_EMPTY					0x00

#define TILE_WALL					0x08
#define TILE_WALL2					0x0c
#define TILE_BLACK_WALL				0x04

#define TILE_ROBBO					0xac
#define TILE_ROBBO_RIGHT			0xe0
#define TILE_ROBBO_RIGHT2			0xe4
#define TILE_ROBBO_DOWN				0xe8
#define TILE_ROBBO_DOWN2			0xec
#define TILE_ROBBO_LEFT				0xf0
#define TILE_ROBBO_LEFT2			0xf4
#define TILE_ROBBO_UP				0xf8
#define TILE_ROBBO_UP2				0xfc

#define TILE_SHIP					0x54
#define TILE_SHIP2					0xc4

#define TILE_MAGNET_LEFT			0x3c
#define TILE_MAGNET_RIGHT			0x38

#define TILE_PROJECTILE_HORIZONTAL	0x90
#define TILE_PROJECTILE_HORIZONTAL2	0x94
#define TILE_PROJECTILE_VERTICAL	0x98
#define TILE_PROJECTILE_VERTICAL2	0x9c

#define TILE_BOMB					0x7c

#define TILE_FORCE_FIELD			0x5c
#define TILE_FORCE_FIELD2			0xcc

#define TILE_EYES					0x50
#define TILE_EYES2					0xc0
#define TILE_LEFT_HAND				0x4c
#define TILE_LEFT_HAND2				0xbc
#define TILE_RIGHT_HAND				0x48
#define TILE_RIGHT_HAND2			0xb8
#define TILE_BAT					0x40
#define TILE_BAT2					0xb0
#define TILE_BAT_SHOOTING			0x44
#define TILE_BAT_SHOOTING2			0xb4

#define TILE_BOX					0x70
#define TILE_INERT_BOX				0x74

#define TILE_TELEPORT				0x58
#define TILE_TELEPORT2				0xc8

#define TILE_GUN_LEFT				0x68
#define TILE_GUN_RIGHT				0x60
#define TILE_GUN_UP					0x6c
#define TILE_GUN_DOWN				0x64

#define TILE_DOOR					0x34

#define TILE_SCREW					0x24
#define TILE_KEY					0x20
#define TILE_AMMO					0x28
#define TILE_GROUND					0x78
#define TILE_LIFE					0x2c

#define TILE_SURPRISE				0x30


#define TILE_EXPLOSION1				0x8c
#define TILE_EXPLOSION2				0x88
#define TILE_EXPLOSION3				0x84
#define TILE_EXPLOSION4				0x80