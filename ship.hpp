#ifndef __SHIP_HPP__
#define __SHIP_HPP__

#include "entity.hpp"
#include "collidable.hpp"
#include "renderable.hpp"

class Ship : public Renderable, public Collidable, public Entity
{
public:
	Ship();
	~Ship();

	bool update();
	void render();

	double getRadius();
	double getX();
	double getY();

	void hasCollided(Collidable *victim);

	int getId();
};

#endif