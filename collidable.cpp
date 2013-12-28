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
	
	double xdiff = (target->getX()+target->getRadius()) - (getX()+getRadius());
	double ydiff = (target->getY()+target->getRadius()) - (getY()+getRadius());
	xdiff *= xdiff;
	ydiff *= ydiff;
	double radius = getRadius()+target->getRadius();

	if(xdiff + ydiff < radius)
	{
		this->hasCollided(target);
	}
}