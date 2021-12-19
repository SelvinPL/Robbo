#include <stdint.h>
#include <types.h>
#include "tiles.h"

const uint8_t const map_to_tiles1[] =
{
	NULL, tiles_trans_gun_right, NULL, NULL, tiles_trans_gun_right, tiles_trans_wall1, tiles_trans_box_push, NULL, //0
	NULL, NULL, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NULL, NULL, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NULL, NULL, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NULL, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NULL, NULL,

	tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, //3
	tiles_trans_teleport, tiles_trans_teleport, NULL, NULL, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, 
	tiles_trans_mob_left, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, //4
	tiles_trans_mob_right, NULL, NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal,

	tiles_projectile_horizontal, NULL, NULL, tiles_projectile_horizontal, tiles_projectile_horizontal, NULL, NULL, NULL, //5
	NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//7
	NULL, NULL, NULL, NULL, tiles_trans_door, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//8
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//9
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	tiles_trans_wall1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

const uint8_t const map_to_tiles2[] =
{
	NULL, tiles_trans_gun_right, NULL, NULL, tiles_trans_gun_right, tiles_trans_wall1, tiles_trans_box_push, NULL, //0
	NULL, NULL, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NULL, NULL, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NULL, NULL, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NULL, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NULL, NULL,

	tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, //3
	tiles_trans_teleport, tiles_trans_teleport, NULL, NULL, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_left2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, //4
	tiles_trans_mob_right2, NULL, NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal,

	tiles_projectile_horizontal, NULL, NULL, tiles_projectile_horizontal, tiles_projectile_horizontal, NULL, NULL, NULL, //5
	NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//7
	NULL, NULL, NULL, NULL, tiles_trans_door, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//8
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//9
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	tiles_trans_wall1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

const uint8_t const map_to_tiles3[] =
{
	NULL, tiles_trans_gun_right, NULL, NULL, tiles_trans_gun_right, tiles_trans_wall1, tiles_trans_box_push, NULL, //0
	NULL, NULL, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NULL, NULL, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NULL, NULL, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NULL, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NULL, NULL,

	tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, //3
	tiles_trans_teleport2, tiles_trans_teleport2, NULL, NULL, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left,
	tiles_trans_mob_left, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, //4
	tiles_trans_mob_right, NULL, NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal2,

	tiles_projectile_horizontal2, NULL, NULL, tiles_projectile_horizontal2, tiles_projectile_horizontal2, NULL, NULL, NULL, //5
	NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal2, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//7
	NULL, NULL, NULL, NULL, tiles_trans_door, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//8
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//9
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	tiles_trans_wall1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

const uint8_t const map_to_tiles4[] =
{
	NULL, tiles_trans_gun_right, NULL, NULL, tiles_trans_gun_right, tiles_trans_wall1, tiles_trans_box_push, NULL, //0
	NULL, NULL, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_up, tiles_trans_force_field,

	NULL, NULL, tiles_trans_door, tiles_trans_black_wall, tiles_trans_capsule, NULL, NULL, tiles_trans_gun_down, //1
	tiles_trans_gun_up, NULL, NULL, NULL, tiles_trans_gun_up, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_right,

	tiles_trans_empty, tiles_trans_pickable_ammo, NULL, tiles_trans_box_normal, tiles_trans_pickable_screw, tiles_trans_ground, tiles_trans_mob_eyes, tiles_trans_gun_down, //2
	tiles_trans_magnet_right, tiles_trans_magnet_left, tiles_trans_robbo, tiles_trans_pickable_extra_life, tiles_trans_gun_right, tiles_trans_gun_left, NULL, NULL,

	tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, tiles_trans_teleport2, //3
	tiles_trans_teleport2, tiles_trans_teleport2, NULL, NULL, tiles_trans_gun_left, tiles_trans_pickable_key, tiles_trans_gun_right, tiles_trans_questionmark,

	tiles_trans_bomb, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_left2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, //4
	tiles_trans_mob_right2, NULL, NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal2,

	tiles_projectile_horizontal2, NULL, NULL, tiles_projectile_horizontal2, tiles_projectile_horizontal2, NULL, NULL, NULL, //5
	NULL, NULL, NULL, NULL, NULL, tiles_projectile_horizontal2, tiles_trans_gun_up, NULL,

	NULL, tiles_explosion4, tiles_explosion3, tiles_explosion2, tiles_explosion1, //6
	tiles_explosion2, tiles_explosion3, tiles_explosion4,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//7
	NULL, NULL, NULL, NULL, tiles_trans_door, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//8
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,//9
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

	tiles_trans_wall1, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};