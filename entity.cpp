#include "entity.hpp"

Entity::Entity()
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