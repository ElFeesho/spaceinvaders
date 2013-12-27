#ifndef __BULLET_HPP__
#define __BULLET_HPP__

#include "collidable.hpp"
#include "entity.hpp"
#include "renderable.hpp"

class Bullet : public Collidable, public Renderable, public Entity
{
public:
	Bullet();
	~Bullet();

	int getId();
	double getX();
	double getY();
	double getRadius();

	void render();
	bool update();

	void hasCollided(Collidable *collidable);
};

#endif