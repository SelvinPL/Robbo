#include "platform.h"
#include <stdint.h>

#ifdef GAMEBOY
#pragma bank 1
#else
#pragma bank 0
#endif

BANKREF(tiles_data)

const uint8_t main_tiles[1949] =
{
    0x5f, 0x00, 0xff, 0x3f, 0xff, 0x7f, 0x00, 0xff, 0xc5, 0x3c, 0xff, 0x3c, 0xff, 0xff, 0xc3, 0x85,
    0x39, 0xff, 0x43, 0x3c, 0xff, 0x8f, 0xf0, 0xff, 0x9f, 0xe0, 0xff, 0xc0, 0xc3, 0x8f, 0xf0, 0xff,
    0x9f, 0xe0, 0xff, 0x8a, 0x90, 0xff, 0xd8, 0xf3, 0xff, 0x3c, 0xff, 0xfc, 0xff, 0x33, 0xff, 0xcf,
    0xff, 0xf3, 0xff, 0xfc, 0xff, 0xc3, 0xff, 0xfc, 0xff, 0xf3, 0xff, 0xcf, 0xff, 0x3f, 0xff, 0xcc,
    0x84, 0xe6, 0xff, 0x83, 0xf6, 0xff, 0xc6, 0xcf, 0xff, 0xf0, 0xff, 0xcf, 0xff, 0x33, 0x84, 0xd6,
    0xff, 0x87, 0xea, 0xff, 0xc0, 0xcc, 0x84, 0xce, 0xff, 0xc2, 0xff, 0xff, 0xcc, 0x86, 0x42, 0xfe,
    0xdb, 0x01, 0xff, 0x00, 0xff, 0x07, 0xff, 0x1f, 0xff, 0x79, 0xf9, 0x00, 0xff, 0x18, 0xff, 0x66,
    0xff, 0x80, 0xff, 0x00, 0xff, 0xe0, 0xff, 0xf8, 0xff, 0xfe, 0xff, 0x67, 0xe7, 0x42, 0x7f, 0xff,
    0xc2, 0x1f, 0xff, 0x07, 0x84, 0x16, 0xfe, 0x43, 0xfe, 0xff, 0xc2, 0xf8, 0xff, 0xe0, 0x89, 0x06,
    0xfe, 0xca, 0xf0, 0x00, 0xc0, 0x0c, 0xc3, 0x0c, 0xc3, 0x00, 0xc0, 0x00, 0xf0, 0x84, 0xf0, 0xfd,
    0xc2, 0x0f, 0x0c, 0x03, 0x83, 0xf0, 0xff, 0xc9, 0x0c, 0x03, 0x30, 0x0f, 0x00, 0xfc, 0x00, 0xfc,
    0x0c, 0xf0, 0x83, 0xfc, 0xff, 0x85, 0xd6, 0xfd, 0x44, 0xc0, 0x3f, 0x89, 0xc6, 0xfd, 0x43, 0x0f,
    0xc0, 0xc2, 0x00, 0xff, 0x03, 0x84, 0xc0, 0xff, 0x43, 0xfc, 0x0f, 0xc3, 0x00, 0xff, 0xf0, 0x3f,
    0x85, 0xec, 0xff, 0x83, 0xe8, 0xff, 0xc1, 0x03, 0xfc, 0x85, 0x94, 0xfd, 0x83, 0xec, 0xff, 0x83,
    0xe8, 0xff, 0xc0, 0xc0, 0x8e, 0x86, 0xfd, 0xc4, 0x3f, 0xff, 0x30, 0xf0, 0x30, 0x86, 0x9a, 0xff,
    0x84, 0x96, 0xff, 0xc7, 0xff, 0x30, 0x3f, 0x0c, 0x0f, 0x30, 0xf0, 0x3f, 0x8c, 0x5e, 0xfd, 0xc1,
    0x30, 0x3f, 0x8f, 0xc8, 0xff, 0x88, 0x3e, 0xfd, 0xc1, 0xfc, 0x00, 0x86, 0x9e, 0xff, 0x86, 0x2c,
    0xfd, 0xc1, 0x3f, 0x00, 0x83, 0x5c, 0xff, 0xc0, 0xf0, 0x84, 0xe8, 0xff, 0xc0, 0xf3, 0x88, 0x18,
    0xfd, 0xc0, 0x0f, 0x84, 0xe8, 0xff, 0xc0, 0xcf, 0x8c, 0x08, 0xfd, 0xc5, 0xf0, 0x00, 0xc0, 0x03,
    0xc3, 0x0f, 0x89, 0xbe, 0xff, 0xcf, 0x3f, 0x00, 0x0f, 0x0c, 0x0f, 0x0c, 0x0f, 0x3c, 0x3f, 0x30,
    0x3f, 0x00, 0xf0, 0x00, 0xf0, 0x03, 0x83, 0xde, 0xfe, 0x83, 0xfa, 0xff, 0x83, 0x42, 0xff, 0xc1,
    0xff, 0xc0, 0x84, 0x46, 0xff, 0x85, 0xfa, 0xff, 0x84, 0x02, 0xff, 0xc2, 0xf3, 0x3f, 0xf3, 0x43,
    0xff, 0x33, 0xc1, 0xf3, 0x33, 0x83, 0x0c, 0xff, 0xc0, 0xfc, 0x4b, 0x33, 0xff, 0xc2, 0x33, 0x00,
    0xff, 0x8f, 0xf0, 0xff, 0xca, 0x00, 0xff, 0x00, 0xc3, 0xfc, 0xc0, 0xfc, 0xc0, 0xf3, 0xc0, 0x0f,
    0x83, 0xa7, 0xff, 0xc5, 0xc3, 0x00, 0xff, 0x00, 0xc0, 0x3c, 0x85, 0x35, 0xff, 0x84, 0x16, 0xff,
    0xcc, 0xfc, 0xc0, 0xff, 0xc0, 0x3f, 0xf0, 0xff, 0xcc, 0xff, 0xc3, 0xff, 0xc3, 0x3c, 0x86, 0x28,
    0xff, 0xc0, 0xc0, 0x42, 0x00, 0xfc, 0xc0, 0xc0, 0x86, 0xe6, 0xfe, 0xc1, 0x03, 0x3c, 0x85, 0x15,
    0xff, 0xc0, 0xfc, 0x85, 0x5e, 0xff, 0xcb, 0x00, 0xc3, 0x3f, 0x03, 0x3f, 0x03, 0xcf, 0x03, 0xf0,
    0x03, 0xff, 0x03, 0x84, 0xb0, 0xff, 0xc1, 0xfc, 0x03, 0x42, 0x00, 0x3f, 0xc1, 0x03, 0xfc, 0x83,
    0x9a, 0xfe, 0xc6, 0x03, 0xff, 0x03, 0xfc, 0x0f, 0xff, 0x33, 0x8a, 0xb0, 0xff, 0xc0, 0xf3, 0x83,
    0xe2, 0xfe, 0xc5, 0x3c, 0xff, 0xff, 0xff, 0xcf, 0xff, 0x84, 0x1c, 0xff, 0xc0, 0xcf, 0x83, 0xe2,
    0xfe, 0x83, 0xf0, 0xff, 0xc0, 0xf3, 0x84, 0x5c, 0xfe, 0xc0, 0x0c, 0x8e, 0xde, 0xfb, 0xc0, 0x30,
    0x8e, 0xce, 0xfb, 0xc2, 0x0c, 0xf3, 0x0c, 0x8c, 0xc0, 0xff, 0xc2, 0x30, 0xcf, 0x30, 0xaa, 0xc0,
    0xff, 0xc9, 0x18, 0xff, 0x67, 0xff, 0x1f, 0xff, 0x1f, 0xf9, 0x1f, 0xf9, 0x83, 0x5e, 0xfd, 0xcb,
    0x01, 0xfe, 0x18, 0xff, 0xe6, 0xff, 0xf8, 0xff, 0xf8, 0x9f, 0xf8, 0x9f, 0x83, 0x5e, 0xfd, 0xd0,
    0x80, 0x7f, 0x1f, 0xff, 0x7f, 0xff, 0x67, 0xf8, 0x07, 0xff, 0x67, 0xff, 0x79, 0xff, 0x18, 0xff,
    0x00, 0x84, 0x2c, 0xfd, 0xc8, 0xe6, 0x1f, 0xe0, 0xff, 0xe0, 0xff, 0x98, 0xff, 0x7e, 0x84, 0xc0,
    0xff, 0xc2, 0x06, 0xff, 0x00, 0x84, 0x06, 0xfd, 0xc2, 0x79, 0xf9, 0x1f, 0x84, 0xc0, 0xff, 0xc0,
    0x60, 0x84, 0xda, 0xff, 0xc4, 0x9e, 0x9f, 0x9e, 0x9f, 0xf8, 0x83, 0xc0, 0xff, 0xcb, 0xf8, 0x7f,
    0xf8, 0x67, 0xf8, 0x07, 0xf8, 0x01, 0xfe, 0x06, 0xff, 0x1e, 0x83, 0xc0, 0xff, 0xc9, 0x1f, 0xfe,
    0x1f, 0xe6, 0x1f, 0xe0, 0x1f, 0x98, 0x7f, 0x78, 0x84, 0xd6, 0xff, 0x86, 0x00, 0xfb, 0xc8, 0xe1,
    0x00, 0x80, 0x00, 0x80, 0x06, 0x86, 0x1e, 0x9e, 0x86, 0xf0, 0xfa, 0xce, 0x87, 0x00, 0x01, 0x00,
    0x01, 0x60, 0x61, 0x78, 0x79, 0x1e, 0x9e, 0x00, 0x80, 0x00, 0xe1, 0x89, 0xda, 0xfa, 0xc5, 0x78,
    0x79, 0x00, 0x01, 0x00, 0x87, 0x91, 0xca, 0xfa, 0xc7, 0x03, 0xfc, 0x0f, 0xf0, 0x3f, 0xc0, 0x3f,
    0x80, 0x88, 0x42, 0xfd, 0xce, 0x3f, 0xf0, 0x3f, 0xfc, 0x0f, 0xfc, 0x0c, 0xc0, 0x00, 0x3f, 0xc0,
    0x0f, 0xf0, 0x33, 0xcf, 0x87, 0xd0, 0xfc, 0xc2, 0x03, 0x03, 0xfc, 0x84, 0x31, 0xfe, 0x86, 0x54,
    0xfe, 0xc9, 0xff, 0x3c, 0xc3, 0x3f, 0xf0, 0xcf, 0x3c, 0xf0, 0x0f, 0xf0, 0x42, 0xcc, 0x30, 0xc9,
    0xcc, 0x3c, 0xc3, 0xfc, 0x0f, 0xf3, 0x3c, 0x0f, 0xf0, 0x0f, 0x42, 0x33, 0x0c, 0xc0, 0x33, 0x85,
    0xea, 0xff, 0xc9, 0xf0, 0x0c, 0xf0, 0x3f, 0xcf, 0xf0, 0x3f, 0xc0, 0x3c, 0xcf, 0x85, 0xea, 0xff,
    0xc9, 0x0f, 0x30, 0x0f, 0xfc, 0xf3, 0x0f, 0xfc, 0x03, 0x3c, 0xf3, 0x83, 0x48, 0xfe, 0xc1, 0xff,
    0xc3, 0x84, 0x3b, 0xfb, 0xc2, 0xc3, 0x3c, 0x3c, 0x83, 0x3c, 0xfb, 0x8d, 0xf0, 0xff, 0x8d, 0xe2,
    0xff, 0x84, 0x17, 0xfb, 0x8c, 0xf0, 0xff, 0x87, 0xfe, 0xfd, 0xc5, 0x03, 0xff, 0x0f, 0xff, 0x3f,
    0xff, 0x86, 0x9e, 0xfd, 0xcb, 0xcf, 0x00, 0xcf, 0xc0, 0xff, 0xf0, 0xff, 0xfc, 0xff, 0x3c, 0xff,
    0x33, 0x8e, 0x10, 0xfe, 0xc0, 0xcc, 0x90, 0xf0, 0xfd, 0x85, 0xfe, 0xfd, 0x8b, 0xc0, 0xff, 0x83,
    0xfe, 0xfd, 0xa7, 0xc0, 0xff, 0x85, 0x00, 0xfe, 0xc2, 0x19, 0xf9, 0x19, 0x84, 0x00, 0xfe, 0xc0,
    0x79, 0x86, 0x00, 0xfe, 0xc2, 0x98, 0x9f, 0x98, 0x84, 0x00, 0xfe, 0xc1, 0x9e, 0x7f, 0x83, 0x48,
    0xfb, 0xc6, 0x07, 0xf8, 0x07, 0xff, 0x07, 0xff, 0x19, 0x84, 0x10, 0xfe, 0x83, 0x48, 0xfb, 0xc6,
    0xe0, 0x1f, 0xe0, 0xff, 0xe6, 0xff, 0x9e, 0x84, 0xf0, 0xfd, 0xc0, 0x00, 0x84, 0x2a, 0xfe, 0x83,
    0xda, 0xfd, 0x85, 0x00, 0xfe, 0xc2, 0x00, 0xff, 0x78, 0x86, 0xda, 0xfd, 0x8d, 0x00, 0xfe, 0xc2,
    0x19, 0xfe, 0x1e, 0x84, 0xd6, 0xfd, 0x87, 0x00, 0xfe, 0xc2, 0x80, 0x7f, 0x60, 0x84, 0xd6, 0xff,
    0x8b, 0x00, 0xfe, 0xc1, 0x1e, 0x9e, 0x8d, 0x00, 0xfe, 0xc5, 0x78, 0x79, 0x78, 0x79, 0x06, 0x86,
    0x8d, 0x00, 0xfe, 0xc1, 0x60, 0x61, 0x9c, 0x00, 0xfe, 0xc0, 0xc0, 0x8e, 0x00, 0xfe, 0xc2, 0x0f,
    0xc0, 0x3f, 0x8e, 0x00, 0xfe, 0xc0, 0xff, 0x95, 0x00, 0xfe, 0xc0, 0xf3, 0x42, 0xcf, 0x33, 0xc0,
    0xcf, 0x87, 0x00, 0xfe, 0xc0, 0xcf, 0x42, 0xf3, 0xcc, 0xc0, 0xf3, 0x85, 0xea, 0xff, 0xc1, 0xf3,
    0x0f, 0x87, 0x00, 0xfe, 0x85, 0xea, 0xff, 0xc1, 0xcf, 0xf0, 0x87, 0x00, 0xfe, 0x83, 0x45, 0xf9,
    0xc1, 0x3c, 0x3c, 0x84, 0x7e, 0xf9, 0xc0, 0x3c, 0x83, 0x38, 0xf9, 0x8f, 0xf0, 0xff, 0x8d, 0xe2,
    0xff, 0x83, 0x1a, 0xfc, 0x8d, 0xf0, 0xff, 0xc3, 0x00, 0xcf, 0x30, 0x03, 0x84, 0xf2, 0xfa, 0xc6,
    0xc3, 0x3c, 0x00, 0x3c, 0x00, 0x00, 0xc3, 0x8b, 0xf4, 0xff, 0x86, 0xe4, 0xf7, 0x8b, 0xf2, 0xff,
    0xc0, 0xf3, 0x8a, 0xe4, 0xff, 0xc2, 0xf3, 0x0c, 0xc0, 0x86, 0xa8, 0xfa, 0x83, 0xb2, 0xfa, 0xc2,
    0xf3, 0x0c, 0xc0, 0x89, 0xf0, 0xff, 0xc1, 0x30, 0x03, 0x86, 0xaa, 0xff, 0x8d, 0xf2, 0xff, 0x8f,
    0xe4, 0xff, 0x89, 0x6a, 0xfa, 0x8b, 0xb2, 0xff, 0x89, 0x6c, 0xff, 0x8d, 0xf2, 0xff, 0x93, 0xe4,
    0xff, 0x8b, 0x42, 0xf7, 0x8b, 0xb2, 0xff, 0x8d, 0x20, 0xfa, 0x8d, 0x12, 0xfa, 0x95, 0xc2, 0xff,
    0x88, 0x06, 0xfb, 0x8e, 0xf0, 0xff, 0x8f, 0xaa, 0xf9, 0x8f, 0x9a, 0xf9, 0x9b, 0x7e, 0xf9, 0x83,
    0x6e, 0xf9, 0x93, 0xac, 0xff, 0x9d, 0x48, 0xf9, 0x8d, 0x40, 0xf9, 0x9f, 0xe0, 0xff, 0x91, 0x00,
    0xf9, 0x8f, 0xe8, 0xff, 0x9f, 0xe0, 0xff, 0x83, 0xc6, 0xf8, 0xc1, 0xf0, 0x03, 0x88, 0x3c, 0xf8,
    0x85, 0x00, 0xf9, 0xc0, 0xc0, 0x83, 0xda, 0xf9, 0xc2, 0x0c, 0xff, 0x0c, 0x85, 0x24, 0xf8, 0xc2,
    0x3f, 0xfc, 0x0f, 0x86, 0x4e, 0xfb, 0x83, 0xec, 0xff, 0xc1, 0xfc, 0x0f, 0x83, 0x3c, 0xfb, 0x8a,
    0x40, 0xf8, 0x96, 0xc0, 0xff, 0x83, 0xf8, 0xf7, 0x8b, 0xc0, 0xff, 0xc3, 0x03, 0xfc, 0x03, 0xfc,
    0x86, 0xe4, 0xf7, 0x84, 0xc0, 0xff, 0x88, 0xba, 0xf7, 0x86, 0x80, 0xff, 0x83, 0x87, 0xf9, 0x8f,
    0xc0, 0xff, 0x83, 0x73, 0xf9, 0x8b, 0x80, 0xff, 0x8b, 0xc0, 0xff, 0x85, 0x88, 0xfa, 0xc0, 0x03,
    0x83, 0x08, 0xf8, 0x88, 0x40, 0xff, 0x84, 0x66, 0xf7, 0x96, 0x80, 0xff, 0x97, 0xc0, 0xff, 0x84,
    0x04, 0xfb, 0xc0, 0xfc, 0x42, 0x3f, 0xf0, 0x84, 0x20, 0xf7, 0x83, 0x04, 0xfb, 0x84, 0x42, 0xfc,
    0xc1, 0xfc, 0x0f, 0x85, 0xea, 0xff, 0x99, 0x80, 0xff, 0xc5, 0xff, 0xff, 0x83, 0x83, 0x45, 0x45,
    0x07, 0x39, 0xc5, 0x7d, 0x7d, 0xff, 0xff, 0x7d, 0x7d, 0x87, 0xf2, 0xff, 0xc3, 0x45, 0x45, 0x83,
    0x83, 0x83, 0xdf, 0xf4, 0xc1, 0xfd, 0xfd, 0x07, 0xf9, 0xc1, 0xfd, 0xfd, 0x8d, 0xf2, 0xff, 0x83,
    0xc1, 0xf4, 0xc3, 0x83, 0x83, 0xc5, 0xc5, 0x89, 0xe0, 0xff, 0xc3, 0x83, 0x83, 0x47, 0x47, 0x07,
    0x3f, 0xc1, 0x47, 0x47, 0x03, 0x83, 0x89, 0xe2, 0xff, 0xc1, 0xc5, 0xc5, 0x85, 0xb0, 0xff, 0x8d,
    0x9e, 0xff, 0x8b, 0xc2, 0xff, 0x85, 0xb0, 0xff, 0x8d, 0xbe, 0xff, 0x89, 0x62, 0xff, 0x85, 0x70,
    0xff, 0x8d, 0xae, 0xff, 0xdf, 0x00, 0xf9, 0x00, 0xf9, 0x01, 0xfe, 0x1e, 0xe0, 0x18, 0xe0, 0x18,
    0xe0, 0x07, 0xf8, 0x1e, 0xe0, 0x00, 0xe7, 0x00, 0x9f, 0x80, 0x7f, 0x00, 0x07, 0x60, 0x67, 0x00,
    0x07, 0x80, 0x1f, 0x00, 0x07, 0x43, 0x19, 0xe0, 0xc7, 0x18, 0xe0, 0x00, 0xff, 0x06, 0xf8, 0x06,
    0xf8, 0x43, 0x80, 0x07, 0xc9, 0x00, 0x07, 0x00, 0xff, 0x00, 0x7f, 0x00, 0x1f, 0x00, 0xff, 0x85,
    0xc0, 0xff, 0xc1, 0x19, 0xe1, 0x83, 0xc0, 0xff, 0x83, 0xda, 0xff, 0x85, 0xc0, 0xff, 0xc1, 0x98,
    0x9f, 0x85, 0xc0, 0xff, 0x43, 0x1e, 0xe0, 0x83, 0xc0, 0xff, 0xc3, 0x1e, 0xe1, 0x1e, 0xe0, 0x44,
    0x00, 0x07, 0xc5, 0x00, 0xff, 0x60, 0x9f, 0x60, 0x07, 0x83, 0xea, 0xff, 0x83, 0x80, 0xff, 0xc1,
    0x1e, 0xe6, 0x86, 0x80, 0xff, 0xc2, 0xff, 0x00, 0x87, 0x8b, 0x80, 0xff, 0x43, 0x18, 0x80, 0x83,
    0x80, 0xff, 0xc3, 0x18, 0xe1, 0x18, 0xe1, 0x42, 0x06, 0x01, 0xcc, 0x00, 0x07, 0x00, 0x7f, 0x60,
    0x87, 0x60, 0x87, 0x00, 0xff, 0x18, 0xe7, 0x06, 0x84, 0x40, 0xff, 0x88, 0xc0, 0xff, 0x8e, 0x40,
    0xff, 0x88, 0xc2, 0xff, 0xc0, 0xfe, 0x83, 0xc2, 0xff, 0xc1, 0x00, 0xff, 0x43, 0x06, 0x01, 0x84,
    0x80, 0xff, 0x83, 0xbe, 0xff, 0xc0, 0xe7, 0x85, 0x00, 0xff, 0x88, 0x80, 0xff, 0xc0, 0x9f, 0x85,
    0x00, 0xff, 0x83, 0x58, 0xff, 0x8f, 0x00, 0xff, 0xc2, 0x01, 0xfe, 0x07, 0x8c, 0x00, 0xff, 0xc2,
    0x80, 0x1f, 0x80, 0x89, 0x00, 0xff, 0xc1, 0xf9, 0x00, 0x87, 0x40, 0xff, 0x84, 0xc0, 0xfe, 0xc1,
    0x80, 0x87, 0x86, 0x40, 0xff, 0x43, 0xe0, 0x18, 0x83, 0xe6, 0xfe, 0xc2, 0xf9, 0x19, 0xe0, 0x43,
    0x60, 0x07, 0x85, 0x80, 0xff, 0xc0, 0xe0, 0x88, 0x00, 0xff, 0x88, 0x80, 0xfe, 0x86, 0x00, 0xff,
    0x87, 0x80, 0xff, 0x98, 0x00, 0xff, 0x84, 0x40, 0xff, 0x89, 0x00, 0xff, 0x8f, 0x40, 0xfe, 0x95,
    0xc0, 0xff, 0x87, 0x00, 0xff, 0x87, 0xc0, 0xff, 0xc1, 0x60, 0x87, 0x85, 0x3f, 0xf2, 0xc7, 0xc0,
    0xc0, 0xc5, 0xc5, 0xc2, 0xc2, 0xc0, 0xc0, 0x87, 0x31, 0xf2, 0xcb, 0x03, 0x03, 0x5b, 0x5b, 0xab,
    0xab, 0x03, 0x03, 0xff, 0xff, 0xf0, 0xf0, 0x83, 0xfc, 0xff, 0x85, 0xf8, 0xff, 0xc5, 0xfc, 0xfc,
    0xff, 0xff, 0x2f, 0x2f, 0x83, 0xfc, 0xff, 0x85, 0xf8, 0xff, 0xcd, 0xbf, 0xbf, 0xff, 0xff, 0xe7,
    0xe7, 0xf3, 0xf3, 0xff, 0xff, 0xe0, 0xe0, 0xe6, 0xe6, 0x03, 0xe0, 0xcb, 0xff, 0xff, 0xcf, 0xcf,
    0x9f, 0x9f, 0xff, 0xff, 0x0f, 0x0f, 0xcf, 0xcf, 0x03, 0x0f, 0xd3, 0xff, 0xff, 0xa0, 0xa0, 0x30,
    0x30, 0x28, 0x28, 0x35, 0x35, 0xea, 0xea, 0xff, 0xff, 0xe3, 0xe3, 0xc3, 0xc3, 0x0b, 0x0b, 0x03,
    0x09, 0xc8, 0x59, 0x59, 0xaf, 0xaf, 0xff, 0xff, 0x8f, 0x8f, 0x87, 0x86, 0x80, 0xff, 0xc9, 0xff,
    0xff, 0xf1, 0xf1, 0xe0, 0xe0, 0xc4, 0xc4, 0x8e, 0x8e, 0x89, 0xaf, 0xf1, 0xcf, 0xf5, 0xf5, 0x75,
    0x75, 0x01, 0x01, 0x9f, 0x9f, 0x8e, 0x8e, 0xc4, 0xc4, 0xe0, 0xe0, 0xf1, 0xf1, 0x85, 0x95, 0xf1,
    0x03, 0x01, 0xc1, 0x7f, 0x7f, 0x97, 0x89, 0xf1, 0x83, 0x52, 0xff, 0x89, 0x6d, 0xf1, 0xcf, 0xf7,
    0xf7, 0x01, 0x01, 0xef, 0xef, 0xf0, 0xf0, 0xc0, 0xc0, 0xc1, 0xc1, 0x83, 0x83, 0x80, 0x80, 0x83,
    0x72, 0xfc, 0x03, 0xfd, 0xc5, 0x01, 0x01, 0x5f, 0x5f, 0xbf, 0xbf, 0x89, 0xba, 0xff, 0xcb, 0xf0,
    0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x88, 0x88, 0x81, 0x81, 0xaa, 0xaa, 0x83, 0x76, 0xff, 0xe3, 0x29,
    0x29, 0x39, 0x39, 0x53, 0x53, 0xa3, 0xa3, 0x47, 0x47, 0x8b, 0x8b, 0x85, 0x85, 0x8a, 0x8a, 0xd4,
    0xd4, 0xa8, 0xa8, 0x51, 0x51, 0x02, 0x02, 0x1f, 0x1f, 0xff, 0xff, 0x17, 0x17, 0x2b, 0x2b, 0x57,
    0x57, 0xaf, 0xaf, 0x83, 0xbe, 0xff, 0x85, 0x03, 0xf1, 0x8d, 0x9e, 0xfc, 0x00,
};

const uint8_t walls_tiles1[42] =
{
	0xc0, 0x00, 0x46, 0x00, 0x3f, 0xc1, 0x00, 0x03, 0x46, 0x03, 0xff, 0xc0, 0x03, 0x8d, 0xe2, 0xff,
	0x02, 0xff, 0x8d, 0xe0, 0xff, 0xc1, 0xff, 0xff, 0x46, 0x00, 0xc0, 0xc1, 0x00, 0xff, 0x0e, 0x03,
	0x8e, 0xe2, 0xff, 0x8e, 0xe1, 0xff, 0xc1, 0xff, 0xff, 0x00,
};

const uint8_t walls_tiles2[33] =
{
	0x42, 0xff, 0xc0, 0x02, 0xff, 0x42, 0x0c, 0xff, 0xc0, 0xff, 0x8f, 0xf0, 0xff, 0x9f, 0xe0, 0xff,
	0x05, 0xc0, 0xc1, 0xff, 0xff, 0x05, 0x0c, 0x8f, 0xf0, 0xff, 0x9f, 0xe0, 0xff, 0xc1, 0xff, 0xff,
	0x00,
};

const uint8_t walls_tiles3[71] =
{
	0xcf, 0xff, 0x03, 0xff, 0x0c, 0xff, 0x33, 0xff, 0xcc, 0xff, 0x30, 0xff, 0xc0, 0xff, 0x00, 0xff,
	0x00, 0x87, 0xf8, 0xff, 0x47, 0xff, 0x00, 0x86, 0xd8, 0xff, 0xc0, 0xff, 0x88, 0xd0, 0xff, 0xc2,
	0x33, 0xff, 0xcf, 0x03, 0xff, 0xcb, 0x03, 0x03, 0x0c, 0x0c, 0x33, 0x33, 0xcc, 0xcc, 0x30, 0x30,
	0xc0, 0xc0, 0x03, 0x00, 0x87, 0xf8, 0xff, 0x0f, 0x00, 0x85, 0xd8, 0xff, 0x89, 0xd0, 0xff, 0xc2,
	0x33, 0x33, 0xcf, 0x84, 0xc0, 0xff, 0x00,
};

const uint8_t walls_tiles4[63] =
{
	0xc2, 0x0f, 0x00, 0x3f, 0x43, 0x00, 0xff, 0xc2, 0x0c, 0xff, 0x33, 0x02, 0xff, 0x42, 0x03, 0xff,
	0xc4, 0x0f, 0xff, 0x33, 0xff, 0xcf, 0x8f, 0xf0, 0xff, 0x83, 0xe0, 0xff, 0x8f, 0xd0, 0xff, 0xc2,
	0xf0, 0x00, 0xc0, 0x06, 0x00, 0xc5, 0x0c, 0x0c, 0x33, 0x33, 0xff, 0xff, 0x05, 0x03, 0xc5, 0x0f,
	0x0f, 0x33, 0x33, 0xcf, 0xcf, 0x8f, 0xf0, 0xff, 0x83, 0xe0, 0xff, 0x8f, 0xd0, 0xff, 0x00,
};

const uint8_t walls_tiles5[44] =
{
	0xcf, 0xff, 0x3f, 0xff, 0xf0, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0xf3, 0xff, 0x0f, 0xff, 0x0c, 0xff,
	0x0c, 0x8f, 0xf0, 0xff, 0x9f, 0xe0, 0xff, 0xc3, 0x3f, 0x3f, 0xf0, 0xf0, 0x03, 0xc0, 0xc3, 0xf3,
	0xf3, 0x0f, 0x0f, 0x03, 0x0c, 0x8f, 0xf0, 0xff, 0x9f, 0xe0, 0xff, 0x00,
};

const uint8_t walls_tiles6[66] =
{
	0xc2, 0x0f, 0x00, 0x3f, 0x42, 0x00, 0xff, 0xc6, 0x00, 0xf3, 0x0c, 0xcc, 0x33, 0x00, 0xff, 0x42,
	0xfc, 0x03, 0xc5, 0xf0, 0x0f, 0xcc, 0x33, 0x30, 0xcf, 0x8f, 0xf0, 0xff, 0x83, 0xe0, 0xff, 0x8f,
	0xd0, 0xff, 0xc2, 0xf0, 0x00, 0xc0, 0x07, 0x00, 0xc4, 0x0c, 0x00, 0x33, 0x00, 0xff, 0x42, 0x00,
	0x03, 0xc5, 0x00, 0x0f, 0x00, 0x33, 0x00, 0xcf, 0x8f, 0xf0, 0xff, 0x83, 0xe0, 0xff, 0x8f, 0xd0,
	0xff, 0x00,
};

const uint8_t walls_tiles7[74] =
{
	0xc4, 0x03, 0xf0, 0x0f, 0xc0, 0x3f, 0x42, 0x00, 0xff, 0xc6, 0x00, 0x3f, 0xc0, 0x03, 0xff, 0xf0,
	0x0f, 0x43, 0xfc, 0x03, 0xc4, 0xfc, 0x0f, 0xf0, 0x3f, 0xc0, 0x8d, 0xf0, 0xff, 0xc2, 0xff, 0x00,
	0xff, 0x8d, 0xd0, 0xff, 0xc6, 0x0f, 0xff, 0x0c, 0xf0, 0x30, 0xc0, 0xc0, 0x07, 0x00, 0xc4, 0xc0,
	0x03, 0xff, 0x00, 0x0f, 0x43, 0x00, 0x03, 0xc4, 0x0c, 0x0f, 0x30, 0x3f, 0xc0, 0x8c, 0xf0, 0xff,
	0x83, 0xc0, 0xff, 0x8d, 0xd0, 0xff, 0xc1, 0x0f, 0xff, 0x00,
};

const uint8_t walls_tiles8[35] =
{
	0x46, 0xff, 0x00, 0xc2, 0x3f, 0xff, 0xfc, 0x46, 0x03, 0xff, 0x8f, 0xf0, 0xff, 0xc0, 0xff, 0x8f,
	0xd0, 0xff, 0x0d, 0x00, 0xc2, 0x3f, 0xff, 0x00, 0x0c, 0x03, 0xc0, 0xff, 0x8f, 0xf0, 0xff, 0x90,
	0xd0, 0xff, 0x00,
};

const uint8_t walls_tiles9[41] =
{
	0xc0, 0x3f, 0x42, 0x00, 0xff, 0xc0, 0xff, 0x42, 0xff, 0x03, 0x87, 0xf8, 0xff, 0xc1, 0xff, 0xff,
	0x87, 0xe8, 0xff, 0x9f, 0xe0, 0xff, 0xc0, 0xc0, 0x04, 0x00, 0xc1, 0xff, 0xff, 0x05, 0x03, 0x87,
	0xf8, 0xff, 0x89, 0xe8, 0xff, 0x9f, 0xe0, 0xff, 0x00,
};

const uint8_t walls_tiles10[50] =
{
	0xc8, 0x00, 0xff, 0x3f, 0xc0, 0x3f, 0xc0, 0x30, 0xc0, 0x33, 0x42, 0xc0, 0x3f, 0xc2, 0xc0, 0x00,
	0xff, 0x46, 0xff, 0x00, 0x47, 0x3f, 0xc0, 0x47, 0xff, 0x00, 0xc8, 0x00, 0xff, 0x00, 0xc0, 0x00,
	0xc0, 0x0f, 0xc0, 0x0c, 0x43, 0xc0, 0x00, 0xc0, 0xff, 0x0e, 0x00, 0x47, 0xc0, 0x00, 0x8e, 0xe1,
	0xff, 0x00,
};

const uint8_t walls_tiles11[38] =
{
	0xc7, 0xff, 0xc0, 0xff, 0x03, 0xff, 0x0c, 0xff, 0x30, 0x87, 0xf8, 0xff, 0x8f, 0xf0, 0xff, 0x9f,
	0xe0, 0xff, 0xc6, 0xc0, 0xc0, 0x03, 0x03, 0x0c, 0x0c, 0x30, 0x87, 0xf8, 0xff, 0x8f, 0xf0, 0xff,
	0x9f, 0xe0, 0xff, 0xc0, 0x30, 0x00,
};

const uint8_t walls_tiles12[69] =
{
	0xc5, 0x0f, 0xfc, 0x3f, 0xf0, 0xff, 0xc0, 0x42, 0xff, 0x00, 0xc9, 0xff, 0x03, 0xfc, 0x0f, 0xf0,
	0x3f, 0xfc, 0x0f, 0xff, 0x03, 0x86, 0xf0, 0xff, 0xc2, 0xc0, 0x3f, 0xf0, 0x8d, 0xf2, 0xff, 0x91,
	0xd2, 0xff, 0xc5, 0x0c, 0xfc, 0x30, 0xf0, 0xc0, 0xc0, 0x05, 0x00, 0xc9, 0x03, 0x03, 0x0c, 0x0f,
	0x30, 0x3f, 0x0c, 0x0f, 0x03, 0x03, 0x85, 0xf0, 0xff, 0xc3, 0xc0, 0xc0, 0x30, 0xf0, 0x8d, 0xf2,
	0xff, 0x91, 0xd2, 0xff, 0x00,
};

const uint8_t walls_tiles13[99] =
{
	0xcf, 0xff, 0x00, 0xff, 0x03, 0xff, 0x30, 0xff, 0x00, 0xff, 0xc0, 0xff, 0x0c, 0xff, 0x00, 0xff,
	0x30, 0x86, 0xf2, 0xff, 0xc6, 0x0c, 0xff, 0xc0, 0xff, 0x00, 0xff, 0x33, 0x84, 0xe2, 0xff, 0x83,
	0xf6, 0xff, 0x83, 0xe4, 0xff, 0x87, 0xde, 0xff, 0x85, 0xe2, 0xff, 0xc0, 0x03, 0x85, 0xcc, 0xff,
	0xcf, 0x00, 0x00, 0x03, 0x03, 0x30, 0x30, 0x00, 0x00, 0xc0, 0xc0, 0x0c, 0x0c, 0x00, 0x00, 0x30,
	0x30, 0x85, 0xf2, 0xff, 0xc7, 0x0c, 0x0c, 0xc0, 0xc0, 0x00, 0x00, 0x33, 0x33, 0x83, 0xe2, 0xff,
	0x83, 0xf6, 0xff, 0x83, 0xe4, 0xff, 0x87, 0xde, 0xff, 0x85, 0xe2, 0xff, 0xc1, 0x03, 0x03, 0x85,
	0xcc, 0xff, 0x00,
};

const uint8_t walls_tiles14[46] =
{
	0xc2, 0x03, 0x00, 0x3f, 0x45, 0x00, 0xff, 0xc0, 0xff, 0x44, 0xff, 0x03, 0xc1, 0xff, 0x0f, 0x04,
	0xff, 0x8e, 0xf0, 0xff, 0x8f, 0xd0, 0xff, 0xc2, 0xfc, 0x00, 0xc0, 0x0a, 0x00, 0xc1, 0xff, 0xff,
	0x09, 0x03, 0xc0, 0x0f, 0x85, 0xd0, 0xff, 0x8e, 0xf0, 0xff, 0x8f, 0xd0, 0xff, 0x00,
};

const uint8_t* const walls_tiles[] =
{
	walls_tiles1, walls_tiles2, walls_tiles3, walls_tiles4,
	walls_tiles5, walls_tiles6, walls_tiles7, walls_tiles8,
	walls_tiles9, walls_tiles10, walls_tiles11, walls_tiles12,
	walls_tiles13, walls_tiles14
};