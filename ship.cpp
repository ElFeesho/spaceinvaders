#include "ship.hpp"

#include <SDL/SDL.h>

Ship::Ship()
{

}

Ship::~Ship()
{

}

bool Ship::update()
{
	return true;
}

void Ship::render()
{
	SDL_Surface *screen = SDL_GetVideoSurface();
	SDL_Rect rect = { X(), Y(), 32, 32 };
	SDL_FillRect(screen, &rect, 0xffffffff);
}

double Ship::getRadius()
{
	return 16;
}

double Ship::getX()
{
	return X();
}

double Ship::getY()
{
	return Y();
}

void Ship::hasCollided(Collidable *with)
{

}