#include "collidable.hpp"

Collidable::Collidable()
{

}

Collidable::~Collidable()
{

}

void Collidable::checkCollision(Collidable *target)
{
	double xdiff = target->getX() - getX();
	double ydiff = target->getY() - getY();
	xdiff *= xdiff;
	ydiff *= ydiff;
	double radius = getRadius()+target->getRadius();

	if(xdiff + ydiff < radius)
	{
		this->hasCollided(target);
	}

}