#ifndef __BULLET_HPP__
#define __BULLET_HPP__

#include "collidable.hpp"
#include "entity.hpp"
#include "renderable.hpp"

class Bullet : public Renderable, public Entity
{
public:
	Bullet();
	~Bullet();

	int getId();

	bool render();
	bool update();

	void hasCollided(Collidable *collidable);

	void entityAdded();
	void entityRemoved();
};

#endif
