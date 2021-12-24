#include <stdint.h>
#include <types.h>
#include "tiles.h"

#define NONE 0

__at(0x200) const uint8_t const map_to_tiles1[] =
{
	NONE, tiles_trans_gun_right, NONE, NONE, tiles_trans_gun_left, tiles_trans_wall1, tiles_trans_box_push, NONE, //0
	NONE, NONE, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NONE, tiles_trans_wall1, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NONE, NONE, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NONE, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NONE, NONE,

	tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, //3
	tiles_trans_teleport, tiles_trans_teleport, NONE, NONE, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, 
	tiles_trans_mob_left, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, //4
	tiles_trans_mob_right, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird, 
	tiles_trans_mob_bird_shooting, tiles_trans_mob_bird_shooting, tiles_projectile_horizontal,

	tiles_projectile_horizontal, tiles_projectile_vertical, tiles_projectile_vertical, tiles_projectile_horizontal, tiles_projectile_horizontal, tiles_projectile_vertical, tiles_projectile_vertical, tiles_explosion4, //5
	tiles_explosion4, tiles_explosion4, tiles_explosion4, tiles_projectile_vertical, tiles_trans_wall2, tiles_projectile_horizontal, tiles_trans_gun_up, NULL,

	NONE, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//7
	NONE, NONE, NONE, NONE, tiles_trans_door, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//8
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//9
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	tiles_trans_wall1, //a
};

__at(0x300) const uint8_t const map_to_tiles2[] =
{
	NONE, tiles_trans_gun_right, NONE, NONE, tiles_trans_gun_left, tiles_trans_wall1, tiles_trans_box_push, NONE, //0
	NONE, NONE, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NONE, tiles_trans_wall1, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NONE, NONE, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NONE, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NONE, NONE,

	tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, //3
	tiles_trans_teleport, tiles_trans_teleport, NONE, NONE, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_left2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, //4
	tiles_trans_mob_right2, tiles_trans_mob_bird2, tiles_trans_mob_bird2, tiles_trans_mob_bird2, tiles_trans_mob_bird2,
	tiles_trans_mob_bird_shooting2, tiles_trans_mob_bird_shooting2, tiles_projectile_horizontal,

	tiles_projectile_horizontal, tiles_projectile_vertical, tiles_projectile_vertical, tiles_projectile_horizontal, tiles_projectile_horizontal, tiles_projectile_vertical, tiles_projectile_vertical, tiles_explosion4, //5
	tiles_explosion4, tiles_explosion4, tiles_explosion4, tiles_projectile_vertical, tiles_trans_wall2, tiles_projectile_horizontal, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//7
	NONE, NONE, NONE, NONE, tiles_trans_door, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//8
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//9
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	tiles_trans_wall1, //a
};

__at(0x400) const uint8_t const map_to_tiles3[] =
{
	NONE, tiles_trans_gun_right, NONE, NONE, tiles_trans_gun_left, tiles_trans_wall1, tiles_trans_box_push, NONE, //0
	NONE, NONE, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NONE, tiles_trans_wall1, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NONE, NONE, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NONE, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes2, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NONE, NONE,

	tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, //3
	tiles_trans_teleport2, tiles_trans_teleport2, NONE, NONE, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left,
	tiles_trans_mob_left, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, //4
	tiles_trans_mob_right, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird,
	tiles_trans_mob_bird_shooting, tiles_trans_mob_bird_shooting, tiles_projectile_horizontal2,

	tiles_projectile_horizontal2, tiles_projectile_vertical2, tiles_projectile_vertical2, tiles_projectile_horizontal2, tiles_projectile_horizontal2, tiles_projectile_vertical2, tiles_projectile_vertical2, tiles_explosion4, //5
	tiles_explosion4, tiles_explosion4, tiles_explosion4, tiles_projectile_vertical2, tiles_trans_wall2, tiles_projectile_horizontal2, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//7
	NONE, NONE, NONE, NONE, tiles_trans_door, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//8
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//9
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	tiles_trans_wall1, //a
};

__at(0x500) const uint8_t const map_to_tiles4[] =
{
	NONE, tiles_trans_gun_right, NULL, NULL, tiles_trans_gun_left, tiles_trans_wall1, tiles_trans_box_push, NONE, //0
	NONE, NONE, NONE, NONE, NONE, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NONE, tiles_trans_wall1, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NONE, NONE, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NONE, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes2, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NONE, NONE,

	tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, //3
	tiles_trans_teleport2, tiles_trans_teleport2, NONE, NONE, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_left2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, //4
	tiles_trans_mob_right2, tiles_trans_mob_bird2, tiles_trans_mob_bird2, tiles_trans_mob_bird2, tiles_trans_mob_bird2,
	tiles_trans_mob_bird_shooting2, tiles_trans_mob_bird_shooting2, tiles_projectile_horizontal2,

	tiles_projectile_horizontal2, tiles_projectile_vertical2, tiles_projectile_vertical2, tiles_projectile_horizontal2, tiles_projectile_horizontal2, tiles_projectile_vertical2, tiles_projectile_vertical2, tiles_explosion4, //5
	tiles_explosion4, tiles_explosion4, tiles_explosion4, tiles_projectile_vertical2, tiles_trans_wall2, tiles_projectile_horizontal2, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//7
	NONE, NONE, NONE, NONE, tiles_trans_door, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//8
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,//9
	NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE,

	tiles_trans_wall1, //a
};