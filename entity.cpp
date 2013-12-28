#include "entity.hpp"

Entity::Entity() : x(0), y(0), radius(0), alive(true)
{
	
}

Entity::~Entity()
{

}

void Entity::X(double x)
{
	this->x = x;
}

void Entity::Y(double y)
{
	this->y = y;
}

double Entity::X()
{
	return x;
}

double Entity::Y()
{
	return y;
}

double Entity::getX()
{
	return X();
}

double Entity::getY()
{
	return Y();
}

double Entity::getRadius()
{
	return radius;
}

void Entity::setRadius(double r)
{
	radius = r;
}

bool Entity::isAlive()
{
	return alive;
}

void Entity::kill()
{
	alive = false;
}