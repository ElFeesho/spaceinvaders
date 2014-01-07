#ifndef __UFOSHIP_HPP__
#define __UFOSHIP_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class UfoShip : public Entity, public Renderable
{
public:
	UfoShip();
	~UfoShip();

	bool update();
	bool render();

	void checkCollision(Collidable *target);
	void hasCollided(Collidable *target);
	int getId();

	void entityAdded();
	void entityRemoved();
private:
	int colour;
};

#endif
