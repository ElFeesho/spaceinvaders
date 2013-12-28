#ifndef __ENEMYARRAY_HPP__
#define __ENEMYARRAY_HPP__

#include "entity.hpp"
#include "renderable.hpp"
#include "badguy.hpp"

#include <vector>

using std::vector;

typedef vector<BadGuy*> BadGuyList;

class EnemyArray : public Entity, public Renderable
{
public:
	EnemyArray();
	~EnemyArray();

	int getId();
	void checkCollision(Collidable *target);
	void hasCollided(Collidable *victim);
	bool update();
	bool render();

private:
	vector<BadGuyList*> badGuyLists;
	bool movingRight;
	long lastUpdate;
};

#endif