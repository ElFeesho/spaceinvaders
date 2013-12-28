#include "collidable.hpp"

Collidable::~Collidable()
{
	
}

void Collidable::checkCollision(Collidable *target)
{
	if (!target)
	{
		return;
	}
	
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