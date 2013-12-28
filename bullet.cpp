#include "bullet.hpp"

#include <SDL/SDL.h>

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

bool Bullet::update()
{
	Y(Y()-3);

	return (Y()+getRadius()>0);
}

void Bullet::render()
{
	SDL_Rect rect = { X(), Y(), getRadius()*2, getRadius()*2 };
	SDL_FillRect(SDL_GetVideoSurface(), &rect, 0xffffffff);
}

double Bullet::getRadius()
{
	return 4;
}

double Bullet::getX()
{
	return X();
}

double Bullet::getY()
{
	return Y();
}

int Bullet::getId()
{
	return 1;
}

void Bullet::hasCollided(Collidable *collidable)
{

}