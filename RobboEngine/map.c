#include <stdint.h>
#include <types.h>
#include "tiles.h"

__at(0x200) const uint8_t const map_to_tiles1[] =
{
    NULL, TILE_WALL, TILE_BLACK_WALL, TILE_WALL2, TILE_WALL, TILE_WALL, TILE_ROBBO, TILE_ROBBO,
    TILE_SHIP, TILE_SHIP, TILE_SHIP2, TILE_SHIP, TILE_MAGNET_LEFT, TILE_MAGNET_RIGHT, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_HORIZONTAL,
    TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_VERTICAL, TILE_EXPLOSION1, TILE_EXPLOSION1,
    TILE_EXPLOSION1, TILE_EXPLOSION1, TILE_BOMB, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_VERTICAL, TILE_FORCE_FIELD, TILE_ROBBO, TILE_EYES,
    TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND,
    TILE_BAT, TILE_BAT, TILE_BAT, TILE_BAT, TILE_BAT_SHOOTING, TILE_BAT_SHOOTING, TILE_INERT_BOX, TILE_INERT_BOX,
    TILE_INERT_BOX, TILE_INERT_BOX, TILE_EMPTY, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT,
    TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_UP, TILE_GUN_UP, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_EMPTY, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EMPTY, TILE_EXPLOSION1, TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4,
    TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_DOOR, TILE_ROBBO, TILE_ROBBO, TILE_SCREW, TILE_KEY,
    TILE_EMPTY, TILE_INERT_BOX, TILE_DOOR, TILE_BOX, TILE_SURPRISE, TILE_BOMB, TILE_AMMO, TILE_GROUND,
    TILE_LIFE,
};

__at(0x300) const uint8_t const map_to_tiles2[] =
{
    NULL, TILE_WALL, TILE_BLACK_WALL, TILE_WALL2, TILE_WALL, TILE_WALL, TILE_ROBBO, TILE_ROBBO,
    TILE_SHIP, TILE_SHIP, TILE_SHIP2, TILE_SHIP, TILE_MAGNET_LEFT, TILE_MAGNET_RIGHT, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_HORIZONTAL,
    TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_VERTICAL, TILE_PROJECTILE_VERTICAL, TILE_EXPLOSION1, TILE_EXPLOSION1,
    TILE_EXPLOSION1, TILE_EXPLOSION1, TILE_BOMB, TILE_PROJECTILE_HORIZONTAL, TILE_PROJECTILE_VERTICAL, TILE_FORCE_FIELD2, TILE_ROBBO, TILE_EYES,
    TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2,
    TILE_BAT2, TILE_BAT2, TILE_BAT2, TILE_BAT2, TILE_BAT_SHOOTING2, TILE_BAT_SHOOTING2, TILE_INERT_BOX, TILE_INERT_BOX,
    TILE_INERT_BOX, TILE_INERT_BOX, TILE_EMPTY, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT,
    TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_TELEPORT, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_UP, TILE_GUN_UP, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_EMPTY, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EMPTY, TILE_EXPLOSION1, TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4,
    TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_DOOR, TILE_ROBBO, TILE_ROBBO, TILE_SCREW, TILE_KEY,
    TILE_EMPTY, TILE_INERT_BOX, TILE_DOOR, TILE_BOX, TILE_SURPRISE, TILE_BOMB, TILE_AMMO, TILE_GROUND,
    TILE_LIFE,
};

__at(0x400) const uint8_t const map_to_tiles3[] =
{
    NULL, TILE_WALL, TILE_BLACK_WALL, TILE_WALL2, TILE_WALL, TILE_WALL, TILE_ROBBO, TILE_ROBBO,
    TILE_SHIP, TILE_SHIP, TILE_SHIP2, TILE_SHIP, TILE_MAGNET_LEFT, TILE_MAGNET_RIGHT, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_HORIZONTAL2,
    TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_VERTICAL2, TILE_EXPLOSION1, TILE_EXPLOSION1,
    TILE_EXPLOSION1, TILE_EXPLOSION1, TILE_BOMB, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_VERTICAL2, TILE_FORCE_FIELD, TILE_ROBBO, TILE_EYES2,
    TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_LEFT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND, TILE_RIGHT_HAND,
    TILE_BAT, TILE_BAT, TILE_BAT, TILE_BAT, TILE_BAT_SHOOTING, TILE_BAT_SHOOTING, TILE_INERT_BOX, TILE_INERT_BOX,
    TILE_INERT_BOX, TILE_INERT_BOX, TILE_EMPTY, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2,
    TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_UP, TILE_GUN_UP, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_EMPTY, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EMPTY, TILE_EXPLOSION1, TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4,
    TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_DOOR, TILE_ROBBO, TILE_ROBBO, TILE_SCREW, TILE_KEY,
    TILE_EMPTY, TILE_INERT_BOX, TILE_DOOR, TILE_BOX, TILE_SURPRISE, TILE_BOMB, TILE_AMMO, TILE_GROUND,
    TILE_LIFE,
};

__at(0x500) const uint8_t const map_to_tiles4[] =
{
    NULL, TILE_WALL, TILE_BLACK_WALL, TILE_WALL2, TILE_WALL, TILE_WALL, TILE_ROBBO, TILE_ROBBO,
    TILE_SHIP, TILE_SHIP, TILE_SHIP2, TILE_SHIP, TILE_MAGNET_LEFT, TILE_MAGNET_RIGHT, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_HORIZONTAL2,
    TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_VERTICAL2, TILE_PROJECTILE_VERTICAL2, TILE_EXPLOSION1, TILE_EXPLOSION1,
    TILE_EXPLOSION1, TILE_EXPLOSION1, TILE_BOMB, TILE_PROJECTILE_HORIZONTAL2, TILE_PROJECTILE_VERTICAL2, TILE_FORCE_FIELD2, TILE_ROBBO, TILE_EYES2,
    TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_LEFT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2, TILE_RIGHT_HAND2,
    TILE_BAT2, TILE_BAT2, TILE_BAT2, TILE_BAT2, TILE_BAT_SHOOTING2, TILE_BAT_SHOOTING2, TILE_INERT_BOX, TILE_INERT_BOX,
    TILE_INERT_BOX, TILE_INERT_BOX, TILE_EMPTY, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2,
    TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_TELEPORT2, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP,
    TILE_GUN_DOWN, TILE_GUN_LEFT, TILE_GUN_RIGHT, TILE_GUN_UP, TILE_GUN_DOWN, TILE_GUN_UP, TILE_GUN_UP, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_EMPTY, TILE_EXPLOSION1,
    TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4, TILE_EMPTY, TILE_EXPLOSION1, TILE_EXPLOSION2, TILE_EXPLOSION3, TILE_EXPLOSION4,
    TILE_EXPLOSION3, TILE_EXPLOSION2, TILE_EXPLOSION1, TILE_DOOR, TILE_ROBBO, TILE_ROBBO, TILE_SCREW, TILE_KEY,
    TILE_EMPTY, TILE_INERT_BOX, TILE_DOOR, TILE_BOX, TILE_SURPRISE, TILE_BOMB, TILE_AMMO, TILE_GROUND,
    TILE_LIFE,
};

const uint8_t const types[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
    0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x02, 0x02,
    0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01,
    0x01,
};