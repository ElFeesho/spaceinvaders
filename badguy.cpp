#include "badguy.hpp"

#include <SDL/SDL.h>

BadGuy::BadGuy() : isAlive(true)
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
	return isAlive;
}

bool BadGuy::update()
{
	return isAlive;
}

int BadGuy::getId()
{
	return 2;
}

void BadGuy::hasCollided(Collidable *collidable)
{
	if(collidable->getId() == 1)
	{
		isAlive = false;
	}
}