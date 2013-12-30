#include "badguy.hpp"

#include <SDL/SDL.h>

BadGuy::BadGuy()
{
	setRadius(32);
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
		((Entity*)collidable)->kill();
	}
}

void BadGuy::checkCollision(Collidable *collidable)
{
	int rs = collidable->getX()+collidable->getRadius();
	int b = collidable->getY()+collidable->getRadius();
	int l = collidable->getX();
	int t = collidable->getY();
	if((rs > getX() && rs < getX()+getRadius()) || (l > getX() && l<getX()+getRadius()))
	{
		if ((t < getY()+getRadius() && t > getY()) || (b > getY() && b < getY()+getRadius()))
		{
			hasCollided(collidable);
		}
	}
}
