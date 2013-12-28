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

	bool render();
	bool update();

	void hasCollided(Collidable *collidable);

protected:
	void renderPixels(const short *data, int count);
};

#endif