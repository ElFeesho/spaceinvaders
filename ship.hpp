#ifndef __SHIP_HPP__
#define __SHIP_HPP__

#include "entity.hpp"
#include "collidable.hpp"
#include "renderable.hpp"

class Ship : public Renderable, public Entity
{
public:
	Ship();
	~Ship();

	bool update();
	bool render();

	void hasCollided(Collidable *victim);

	int getId();

private:
	long lastShot;
};

#endif