#include <stdint.h>

#define CHANNEL1		0x0
#define CHANNEL2		0x1
#define CHANNEL3		0x2
#define CHANNEL4		0x3

#define PLAY			0x01
#define MUTE			0x02
#define WAIT			0x03
#define STOP			0xff

#pragma bank 1

const uint8_t teleportSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x47, 0x4b, 0x87,
	PLAY, 0x81, 0x47, 0xcc, 0x86,
	PLAY, 0x81, 0x47, 0x4d, 0x86,
	PLAY, 0x81, 0x47, 0x58, 0x87,
	PLAY, 0x81, 0x37, 0xd9, 0x86,
	PLAY, 0x81, 0x37, 0x5a, 0x86,
	PLAY, 0x81, 0x37, 0x64, 0x87,
	PLAY, 0x81, 0x37, 0xe5, 0x86,
	PLAY, 0x81, 0x27, 0x66, 0x86,
	PLAY, 0x81, 0x27, 0x70, 0x87,
	PLAY, 0x81, 0x27, 0xf1, 0x86,
	PLAY, 0x81, 0x27, 0x72, 0x86,
	PLAY, 0x81, 0x17, 0x7c, 0x87,
	PLAY, 0x81, 0x17, 0xf9, 0x86,
	PLAY, 0x81, 0x17, 0x76, 0x86,
	MUTE,
	STOP
};

const uint8_t ammoSound[] =
{
	CHANNEL2,	
	PLAY, 0x81, 0x17, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x27, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x37, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x47, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x37, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x27, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x17, 0xc2, 0x87,
	MUTE,
	PLAY, 0x81, 0x17, 0xc2, 0x87,
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
	PLAY, 0x0a, 0xf4, 0x80, 0x80,
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
	PLAY, 0x81, 0x47, 0x53, 0x87,
	PLAY, 0x81, 0x37, 0x4f, 0x87,
	PLAY, 0x81, 0x27, 0x53, 0x87,
	PLAY, 0x81, 0x17, 0x4f, 0x87,
	MUTE,
	STOP
};

const uint8_t keySound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x67, 0xa5, 0x87,
	PLAY, 0x81, 0x57, 0xa9, 0x87,
	PLAY, 0x81, 0x47, 0xae, 0x87,
	PLAY, 0x81, 0x37, 0xb2, 0x87,
	PLAY, 0x81, 0x27, 0xb6, 0x87,
	PLAY, 0x81, 0x17, 0xba, 0x87,
	MUTE,
	STOP
};

const uint8_t extraLifeSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x67, 0xd2, 0x85,
	PLAY, 0x81, 0x37, 0xca, 0x85,
	PLAY, 0x81, 0x67, 0xd2, 0x85,
	PLAY, 0x81, 0x37, 0xca, 0x85,
	PLAY, 0x81, 0x67, 0xd2, 0x85,
	PLAY, 0x81, 0x37, 0xca, 0x85,
	PLAY, 0x81, 0x67, 0xe9, 0x86,
	PLAY, 0x81, 0x37, 0xe5, 0x86,
	PLAY, 0x81, 0x27, 0xe9, 0x86,
	PLAY, 0x81, 0x17, 0xe5, 0x86,
	PLAY, 0x81, 0x67, 0xb8, 0x86,
	PLAY, 0x81, 0x37, 0xb4, 0x86,
	PLAY, 0x81, 0x67, 0xe9, 0x86,
	PLAY, 0x81, 0x37, 0xe5, 0x86,
	PLAY, 0x81, 0x27, 0xe9, 0x86,
	PLAY, 0x81, 0x17, 0xe5, 0x86,
	MUTE,
	STOP
};

const uint8_t nextLevelSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0x87, 0xbe, 0x87,
	PLAY, 0x81, 0x77, 0xbe, 0x87,
	PLAY, 0x81, 0x57, 0xbe, 0x87,
	PLAY, 0x81, 0x37, 0xbe, 0x87,
	PLAY, 0x81, 0x27, 0xbe, 0x87,
	PLAY, 0x81, 0x57, 0xbe, 0x87,
	PLAY, 0x81, 0x47, 0xbe, 0x87,
	PLAY, 0x81, 0x37, 0xbe, 0x87,
	PLAY, 0x81, 0x27, 0xbe, 0x87,
	PLAY, 0x81, 0x17, 0xbe, 0x87,
	PLAY, 0x81, 0x47, 0xbe, 0x87,
	PLAY, 0x81, 0x37, 0xbe, 0x87,
	PLAY, 0x81, 0x27, 0xbe, 0x87,
	PLAY, 0x81, 0x17, 0xbe, 0x87,
	PLAY, 0x81, 0x17, 0xbe, 0x87,
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

const uint8_t smallExplosionSound[] =
{
	CHANNEL4,
	PLAY, 0x3f, 0x35, 0x21, 0x80,		
	STOP
};

const uint8_t startLevelSound[] =
{
	CHANNEL2,
	PLAY, 0x81, 0xa7, 0xdf, 0x87,
	PLAY, 0x81, 0xa7, 0x9d, 0x87,
	PLAY, 0x81, 0x87, 0xdf, 0x87,
	PLAY, 0x81, 0x87, 0x9d, 0x87,
	PLAY, 0x81, 0x67, 0xdf, 0x87,
	PLAY, 0x81, 0x67, 0x9d, 0x87,
	PLAY, 0x81, 0x57, 0xdf, 0x87,
	PLAY, 0x81, 0x57, 0x9d, 0x87,
	PLAY, 0x81, 0x47, 0xdf, 0x87,
	PLAY, 0x81, 0x47, 0x9d, 0x87,
	PLAY, 0x81, 0x37, 0xdf, 0x87,
	PLAY, 0x81, 0x37, 0x9d, 0x87,
	PLAY, 0x81, 0x27, 0xdf, 0x87,
	PLAY, 0x81, 0x27, 0x9d, 0x87,
	PLAY, 0x81, 0x17, 0xdf, 0x87,
	PLAY, 0x81, 0x17, 0x9d, 0x87,
	MUTE,
	STOP,
};


const uint8_t* const sounds[] =
{
	openExitSound, walkSound, nextLevelSound, extraLifeSound, 
	openDoorSound, teleportSound, ammoSound, screwSound, 
	keySound, magnetSound, explosionSound, smallExplosionSound,
	startLevelSound
};