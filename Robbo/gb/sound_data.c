#include <stdint.h>
#include "../platform.h"

#define CHANNEL1		0x0
#define CHANNEL2		0x1
#define CHANNEL3		0x2
#define CHANNEL4		0x3

#define PLAY			0x01
#define MUTE			0x02
#define WAIT			0x03
#define STOP			0xff

#ifdef GAMEBOY
#pragma bank 1
#else
#pragma bank 0
#endif

const uint8_t teleportSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x67, 0x46, 0x87,
	PLAY, 0x81, 0x67, 0xc7, 0x86,
	PLAY, 0x81, 0x67, 0x43, 0x86,
	PLAY, 0x81, 0x67, 0x52, 0x87,
	PLAY, 0x81, 0x57, 0xd1, 0x86,
	PLAY, 0x81, 0x57, 0x50, 0x86,
	PLAY, 0x81, 0x57, 0x5f, 0x87,
	PLAY, 0x81, 0x57, 0xde, 0x86,
	PLAY, 0x81, 0x47, 0x5e, 0x86,
	PLAY, 0x81, 0x47, 0x6b, 0x87,
	PLAY, 0x81, 0x47, 0xeb, 0x86,
	PLAY, 0x81, 0x47, 0x6a, 0x86,
	PLAY, 0x81, 0x37, 0x77, 0x87,
	PLAY, 0x81, 0x37, 0xf3, 0x86,
	PLAY, 0x81, 0x37, 0x6f, 0x86,
	MUTE,
	STOP
};

const uint8_t ammoSound[] =
{
	CHANNEL2,	
	PLAY, 0x81, 0x37, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x47, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x57, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x67, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x57, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x47, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x37, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x37, 0xc2, 0x87,
	MUTE,
	STOP
};

const uint8_t openExitSound[] =
{
	CHANNEL4,
	PLAY, 0x01, 0xf5, 0x6c, 0x80,
	STOP
};

const uint8_t explosionSound[] =
{
	CHANNEL4,
	PLAY, 0x00, 0xf5, 0x5d, 0x80,
	STOP
};

const uint8_t walkSound[] =
{
	CHANNEL3,
	PLAY, 0xfb, 0x20, 0xa0, 0xc0,
	STOP
};


const uint8_t openDoorSound[] =
{
	CHANNEL1,
	PLAY, 0x23, 0x40, 0x82, 0x00, 0x80,
	PLAY, 0x23, 0x40, 0x72, 0x00, 0x80,
	PLAY, 0x23, 0x40, 0x82, 0x00, 0x80,
	PLAY, 0x23, 0x40, 0x82, 0x00, 0x81,
	PLAY, 0x23, 0x40, 0x72, 0x00, 0x81,
	PLAY, 0x23, 0x40, 0x62, 0x00, 0x81,
	PLAY, 0x23, 0x40, 0x52, 0x00, 0x82,
	PLAY, 0x23, 0x40, 0x32, 0x00, 0x82,
	PLAY, 0x23, 0x40, 0x22, 0x00, 0x82,
	PLAY, 0x2b, 0x40, 0x12, 0x80, 0x82,
	STOP,
};

const uint8_t screwSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x67, 0x4f, 0x87,
	PLAY, 0x81, 0x57, 0x4b, 0x87,
	PLAY, 0x81, 0x47, 0x4f, 0x87,
	PLAY, 0x81, 0x37, 0x4b, 0x87,
	MUTE,
	STOP
};

const uint8_t keySound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x87, 0xa3, 0x87,
	PLAY, 0x81, 0x77, 0xa7, 0x87,
	PLAY, 0x81, 0x67, 0xac, 0x87,
	PLAY, 0x81, 0x57, 0xb0, 0x87,
	PLAY, 0x81, 0x47, 0xb4, 0x87,
	PLAY, 0x81, 0x37, 0xb8, 0x87,
	MUTE,
	STOP
};

const uint8_t extraLifeSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x87, 0xc5, 0x85,
	PLAY, 0x81, 0x57, 0xbd, 0x85,
	PLAY, 0x81, 0x87, 0xc5, 0x85,
	PLAY, 0x81, 0x57, 0xbd, 0x85,
	PLAY, 0x81, 0x87, 0xc5, 0x85,
	PLAY, 0x81, 0x57, 0xbd, 0x85,
	PLAY, 0x81, 0x87, 0xe2, 0x86,
	PLAY, 0x81, 0x57, 0xde, 0x86,
	PLAY, 0x81, 0x47, 0xe2, 0x86,
	PLAY, 0x81, 0x37, 0xde, 0x86,
	PLAY, 0x81, 0x87, 0xb0, 0x86,
	PLAY, 0x81, 0x57, 0xac, 0x86,
	PLAY, 0x81, 0x87, 0xe2, 0x86,
	PLAY, 0x81, 0x57, 0xde, 0x86,
	PLAY, 0x81, 0x47, 0xe2, 0x86,
	PLAY, 0x81, 0x37, 0xde, 0x86,
	MUTE,
	STOP
};

const uint8_t nextLevelSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0xa7, 0xbc, 0x87,
	PLAY, 0x81, 0x97, 0xbc, 0x87,
	PLAY, 0x81, 0x77, 0xbc, 0x87,
	PLAY, 0x81, 0x57, 0xbc, 0x87,
	PLAY, 0x81, 0x47, 0xbc, 0x87,
	PLAY, 0x81, 0x77, 0xbc, 0x87,
	PLAY, 0x81, 0x67, 0xbc, 0x87,
	PLAY, 0x81, 0x57, 0xbc, 0x87,
	PLAY, 0x81, 0x47, 0xbc, 0x87,
	PLAY, 0x81, 0x37, 0xbc, 0x87,
	PLAY, 0x81, 0x67, 0xbc, 0x87,
	PLAY, 0x81, 0x57, 0xbc, 0x87,
	PLAY, 0x81, 0x47, 0xbc, 0x87,
	PLAY, 0x81, 0x37, 0xbc, 0x87,
	PLAY, 0x81, 0x37, 0xbc, 0x87,
	MUTE,
	STOP
};


const uint8_t magnetSound[] =
{
	CHANNEL4,

	PLAY, 0x00, 0x3f, 0x20, 0xc0,
	PLAY, 0x00, 0x3f, 0x20, 0xc0,
	PLAY, 0x00, 0x4f, 0x20, 0xc0,
	PLAY, 0x00, 0x4f, 0x60, 0xc0,

	PLAY, 0x00, 0x5f, 0x20, 0xc0,
	PLAY, 0x00, 0x5f, 0x20, 0xc0,
	PLAY, 0x00, 0x6f, 0x20, 0xc0,
	PLAY, 0x00, 0x6f, 0x60, 0xc0,

	PLAY, 0x00, 0x7f, 0x20, 0xc0,
	PLAY, 0x00, 0x7f, 0x20, 0xc0,
	PLAY, 0x00, 0x8f, 0x20, 0xc0,
	PLAY, 0x00, 0x8f, 0x60, 0xc0,

	PLAY, 0x00, 0x9f, 0x20, 0xc0,
	PLAY, 0x00, 0x9f, 0x20, 0xc0,
	PLAY, 0x00, 0xaf, 0x20, 0xc0,
	PLAY, 0x00, 0xaf, 0x60, 0xc0,
	MUTE,
	STOP
};