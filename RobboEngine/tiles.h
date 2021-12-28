#pragma once
#include "platform.h"
#include <stdint.h>

BANKREF_EXTERN(tiles_data)

extern const uint8_t const map_tiles[];

#define tiles_trans_empty				0x00
#define tiles_trans_black_wall			0x04

#define tiles_trans_wall1				0x08
#define tiles_trans_wall2				0x0c
#define tiles_trans_box_normal			0x70
#define tiles_trans_box_push			0x74
#define tiles_trans_ground				0x78
#define tiles_trans_bomb				0x7c
#define tiles_trans_pickable_key		0x20
#define tiles_trans_pickable_screw		0x24
#define tiles_trans_pickable_ammo		0x28
#define tiles_trans_pickable_extra_life	0x2c
#define tiles_trans_questionmark		0x30
#define tiles_trans_door				0x34
#define tiles_trans_magnet_right		0x38
#define tiles_trans_magnet_left			0x3c

#define tiles_trans_mob_bird			0x40
#define tiles_trans_mob_bird_shooting	0x44
#define tiles_trans_mob_right			0x48
#define tiles_trans_mob_left			0x4c
#define tiles_trans_mob_eyes			0x50
#define tiles_trans_capsule				0x54
#define tiles_trans_teleport			0x58
#define tiles_trans_force_field			0x5c

#define tiles_trans_mob_bird2			0xb0
#define tiles_trans_mob_bird_shooting2	0xb4
#define tiles_trans_mob_right2			0xb8
#define tiles_trans_mob_left2			0xbc
#define tiles_trans_mob_eyes2			0xc0
#define tiles_trans_capsule2			0xc4
#define tiles_trans_teleport2			0xc8
#define tiles_trans_force_field2		0xcc

#define tiles_trans_robbo				0xac
#define tiles_trans_robbo_r				0xe0
#define tiles_trans_robbo_r2			0xe4
#define tiles_trans_robbo_d				0xe8
#define tiles_trans_robbo_d2			0xec
#define tiles_trans_robbo_l				0xf0
#define tiles_trans_robbo_l2			0xf4
#define tiles_trans_robbo_u				0xf8
#define tiles_trans_robbo_u2			0xfc

#define tiles_trans_gun_right			0x60
#define tiles_trans_gun_down			0x64
#define tiles_trans_gun_left			0x68
#define tiles_trans_gun_up				0x6c

#define tiles_projectile_horizontal		0x90
#define tiles_projectile_horizontal2	0x94

#define tiles_projectile_vertical		0x98
#define tiles_projectile_vertical2		0x9c


#define tiles_explosion1				0x80
#define tiles_explosion2				0x84
#define tiles_explosion3				0x88
#define tiles_explosion4				0x8c