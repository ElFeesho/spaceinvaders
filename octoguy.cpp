#include "octoguy.hpp"

#include <SDL/SDL.h>

static const short SPRITE_ONE[] = { 0x1800, // 000x x000 0000 0000
									0x3c00,	// 00xx xx00 0000 0000
									0x7e00, // 0xxx xxx0 0000 0000
									0xdb00, // xx0x x0xx 0000 0000
									0xff00, // xxxx xxxx 0000 0000
									0x2400, // 00x0 0x00 0000 0000
									0x5a00, // 0x0x x0x0 0000 0000
									0xa500  // x0x0 0x0x 0000 0000
								  };

OctoGuy::OctoGuy()
{

}

OctoGuy::~OctoGuy()
{

}

bool OctoGuy::render()
{
	renderPixels(SPRITE_ONE, 8, X()+4, Y());
	return isAlive();
}