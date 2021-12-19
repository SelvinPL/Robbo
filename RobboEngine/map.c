#include <stdint.h>
#include <types.h>
#include "tiles.h"

const uint8_t map1[] =
"!!!!!!!!!!!!!!!!"
"!              !"
"!#!#!#!#!#!#!# !"
"!  !!!!!!!!!!! !"
"!#!!!!!!!!!!!  !"
"!    \"   \"   \" !"
"!              !"
"! &!&!&!&!&!&!&!"
"! !!!!!!!!!!!! !"
"!  ! ! ! ! ! ! !"
"! ' ' ' ' ' '  !"
"!       #      !"
"!      *!      !"
"!      !!!     !"
"!              !"
"!              !"
"!              !"
"! &!&!&!&!&!&!&!"
"! !!!!!!!!!!!! !"
"!  ! ! ! ! ! ! !"
"! ' ' ' ' ' '  !"
"!              !"
//"! &!&!&!&!&!&!&!"
//"! !!!!!!!!!!!! !"
//"!  ! ! ! ! ! ! !"
//"! ' ' ' ' ' '  !"
"!              !"
"!              !"
"!              !"
"!              !"
"!              !"
"!              !"
"!        1     !"
"!.       *     !"
"!!!!!!!!!!!!!!!!"
"                ";

const uint8_t const map_to_tiles1[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1,
	tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left,
	tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right,
	tiles_trans_pickable_screw, tiles_missle_horizontal, tiles_missle_horizontal, tiles_missle_horizontal, tiles_trans_gun_right,
	tiles_explosion3, tiles_explosion4, tiles_trans_gun_left
};

const uint8_t const map_to_tiles2[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1,
	tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2,
	tiles_trans_pickable_screw, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_trans_gun_right,
	tiles_explosion3, tiles_explosion4, tiles_trans_gun_left
};

const uint8_t const map_to_tiles3[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1,
	tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left, tiles_trans_mob_left,
	tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right, tiles_trans_mob_right,
	tiles_trans_pickable_screw, tiles_missle_horizontal, tiles_missle_horizontal, tiles_missle_horizontal, tiles_trans_gun_right,
	tiles_explosion3, tiles_explosion4, tiles_trans_gun_left
};

const uint8_t const map_to_tiles4[] =
{
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	tiles_trans_empty, tiles_trans_wall1,
	tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2, tiles_trans_mob_left2,
	tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2, tiles_trans_mob_right2,
	tiles_trans_pickable_screw, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_missle_horizontal2, tiles_trans_gun_right,
	tiles_explosion3, tiles_explosion4, tiles_trans_gun_left

};