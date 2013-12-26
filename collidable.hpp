#ifndef __COLLIDABLE_HPP__
#define __COLLIDABLE_HPP__

class Collidable
{
public:
	Collidable();
	~Collidable();

	virtual void checkCollision(Collidable *collidable);
	virtual void hasCollided(Collidable *with) = 0; 
private:
};

#endif