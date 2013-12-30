#include <SDL/SDL.h>
#include "bugguy.hpp"

static const short SPRITE_ONE[] = { 0x2080, // 00x0 0000 x000 0000
									0x1100,	// 000x 000x 0000 0000
									0x3f80, // 00xx xxxx x000 0000
									0x6ec0, // 0xx0 xxx0 xx00 0000
									0xffe0, // xxxx xxxx xxx0 0000
									0xbfa0, // x0xx xxxx x0x0 0000
									0xa0a0, // x0x0 0000 x0x0 0000
									0x1b00  // 000x x0xx 0000 0000
								  };

BugGuy::BugGuy()
{

}

BugGuy::~BugGuy()
{

}

bool BugGuy::render()
{
	renderPixels(SPRITE_ONE, 8, X(), Y());
	return isAlive();
}