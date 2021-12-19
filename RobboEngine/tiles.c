#include "tiles.h"

const uint8_t const empty_group[1] = { tiles_trans_empty };
const uint8_t const wall_group[15] = { tiles_trans_wall1, tiles_trans_wall2, tiles_trans_black_wall, tiles_trans_wall1, tiles_trans_wall1, tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 ,tiles_trans_wall1 };
const uint8_t const teleport_group[10] = { tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport, tiles_trans_teleport };
const uint8_t const pickable_group[4] = { tiles_trans_pickable_screw, tiles_trans_pickable_ammo, tiles_trans_pickable_key, tiles_trans_pickable_extra_life };
const uint8_t const robbo_group[2] = { tiles_trans_robbo, tiles_trans_capsule };
const uint8_t const shootable_group[3] = { tiles_trans_questionmark, tiles_trans_bomb, tiles_trans_ground };
const uint8_t const box_group[5] = { tiles_trans_box_normal, tiles_trans_empty, tiles_trans_empty, tiles_trans_empty, tiles_trans_box_push };
const uint8_t const door_group[1] = { tiles_trans_door };
const uint8_t const gun_group[16] = { tiles_trans_gun_right, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_up, tiles_trans_gun_right, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_up, tiles_trans_gun_right, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_up, tiles_trans_gun_right, tiles_trans_gun_down, tiles_trans_gun_left, tiles_trans_gun_up };
const uint8_t const mob_group[8] = { tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left };
const uint8_t const mob2_group[9] = { tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird, tiles_trans_mob_bird_shooting, tiles_trans_mob_bird_shooting, tiles_trans_mob_bird_shooting, tiles_trans_mob_bird_shooting, tiles_trans_mob_eyes };
const uint8_t const magnet_group[3] = { tiles_trans_magnet_right, tiles_trans_empty, tiles_trans_magnet_left };
const uint8_t const force_field_group[1] = { tiles_trans_force_field };
const uint8_t const level_terminator_group[1] = { tiles_trans_black_wall };

const uint8_t* const tiles_trans[16] =
{
	empty_group, wall_group, teleport_group, pickable_group, robbo_group, shootable_group, box_group, door_group,
	gun_group, gun_group, mob_group, mob2_group, magnet_group, force_field_group, empty_group, level_terminator_group
};

const uint8_t* const ROBBO_STATE[8] =
{
	&map_tiles[tiles_trans_robbo_r * 0x10], &map_tiles[tiles_trans_robbo_r2 * 0x10],
	&map_tiles[tiles_trans_robbo_d * 0x10], &map_tiles[tiles_trans_robbo_d2 * 0x10],
	&map_tiles[tiles_trans_robbo_l * 0x10], &map_tiles[tiles_trans_robbo_l2 * 0x10],
	&map_tiles[tiles_trans_robbo_u * 0x10], &map_tiles[tiles_trans_robbo_u2 * 0x10],
};

const uint8_t* const ROBBO_TELEPORTING_STATE[4] =
{
	&map_tiles[0x80 * 0x10],
	&map_tiles[0x84 * 0x10],
	&map_tiles[0x88 * 0x10],
	&map_tiles[0x8c * 0x10],
};

const uint8_t* const ROBBO_DYING_STATE[7] =
{
	&map_tiles[0x8c * 0x10],
	&map_tiles[0x88 * 0x10],
	&map_tiles[0x84 * 0x10],
	&map_tiles[0x80 * 0x10],
	&map_tiles[0x84 * 0x10],
	&map_tiles[0x88 * 0x10],
	&map_tiles[0x8c * 0x10],
};

const uint8_t* const TELEPORT_STATE[2] = 
{ 
	&map_tiles[tiles_trans_teleport * 0x10], &map_tiles[tiles_trans_teleport2 * 0x10]
};

const uint8_t* const MOBS_STATE[2] = 
{ 
	&map_tiles[tiles_trans_mob_bird * 0x10], &map_tiles[tiles_trans_mob_bird2 * 0x10]
};

const uint8_t* const MOBS_STATE2[2] =
{
	&map_tiles[tiles_trans_mob_left * 0x10], &map_tiles[tiles_trans_mob_left2 * 0x10]
};

const uint8_t* const MOBS_STATE3[2] =
{
	&map_tiles[tiles_trans_mob_eyes * 0x10], &map_tiles[tiles_trans_mob_eyes2 * 0x10]
};

const uint8_t* const FORCEFIELD_STATE[2] = 
{ 
	&map_tiles[tiles_trans_force_field * 0x10], &map_tiles[tiles_trans_force_field2 * 0x10]
};

const uint8_t* const CAPSULE_STATE[2] =
{
	&map_tiles[tiles_trans_capsule * 0x10], &map_tiles[tiles_trans_capsule2 * 0x10]
};