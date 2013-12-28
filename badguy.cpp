#include "badguy.hpp"

#include <SDL/SDL.h>

BadGuy::BadGuy()
{
	setRadius(16);
}

BadGuy::~BadGuy()
{

}

bool BadGuy::render()
{
	SDL_Rect rect = { X(), Y(), getRadius()*2, getRadius()*2 };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, 0xffffff00);
	return isAlive();
}

bool BadGuy::update()
{
	return isAlive();
}

int BadGuy::getId()
{
	return 2;
}

void BadGuy::hasCollided(Collidable *collidable)
{
	if(collidable->getId() == 1)
	{
		kill();
	}
}

void BadGuy::renderPixels(const short *data, int count)
{
	SDL_Rect brush = { X(), Y(), 4, 4 };
	for(int i = 0; i < count; i++)
	{
		brush.x = X();
		for(int x = 0; x < 16; x++)
		{
			if(((data[i] >> (15-x)) & 0x1) == 1)
			{
				SDL_FillRect(SDL_GetVideoSurface(), &brush, 0xffffffff);
			}
			brush.x += brush.w;
		}
		brush.y += brush.h;
	}
}