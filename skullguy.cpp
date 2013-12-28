#include "skullguy.hpp"

#include <SDL/SDL.h>

static const short SPRITE_ONE[] = { 0x0f00,   // 0000 xxxx 0000 0000 
									0x7fe0,   // 0xxx xxxx xxx0 0000 
									0xfff0,   // xxxx xxxx xxxx 0000
									0xe670,   // xxx0 0xx0 0xxx 0000
									0xfff0,   // xxxx xxxx xxxx 0000
									0x1980,   // 000x x00x x000 0000
									0x36c0,   // 00xx 0xx0 0xx0 0000
									0xc030 }; // xx00 0000 00xx 0000

SkullGuy::SkullGuy()
{

}

SkullGuy::~SkullGuy()
{

}

bool SkullGuy::render()
{
	renderPixels(SPRITE_ONE, 8);
	return isAlive();
}