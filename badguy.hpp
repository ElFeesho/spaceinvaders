#ifndef __BADGUY_HPP__
#define __BADGUY_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class BadGuy : public Entity, public Renderable
{
public:
	BadGuy();
	virtual ~BadGuy();

	int getId();

	virtual bool render();
	virtual bool update();

	void hasCollided(Collidable *collidable);
	void checkCollision(Collidable *target);
};

#endif