#ifndef __COLLIDABLE_HPP__
#define __COLLIDABLE_HPP__

class Collidable
{
public:
	Collidable();
	~Collidable();

	virtual void checkCollision(Collidable *collidable);
	virtual void hasCollided(Collidable *with) = 0; 

	virtual double getRadius() = 0;
	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual int getId() = 0;
private:
};

#endif