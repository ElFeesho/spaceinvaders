#include "bullet.hpp"

#include <SDL/SDL.h>

Bullet::Bullet()
{
	setRadius(4);
}

Bullet::~Bullet()
{

}

bool Bullet::update()
{
	Y(Y()-3);
	
	if((Y()+getRadius()<0))
	{
		kill();
	}

	return isAlive();
}

bool Bullet::render()
{
	SDL_Rect rect = { X()-2, Y(), 4, getRadius()*2 };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, 0xffffffff);
	return isAlive();
}

int Bullet::getId()
{
	return 1;
}

void Bullet::hasCollided(Collidable *collidable)
{
	if(collidable->getId() == 2)
	{
		kill();
	}
}