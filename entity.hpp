#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>

using std::string;

#include "collidable.hpp"

class Entity : public Collidable
{
public:
	Entity();
	~Entity();

	virtual bool update() = 0;

	string getName();

	void X(double x);
	double X();
	
	void Y(double y);
	double Y();

	double getX();
	double getY();
	double getRadius();

	bool isAlive();
	void kill();

protected:
	void setRadius(double r);
	void setName(const string &name);
private:
	double x;
	double y;
	double radius;	
	bool alive;
	string name;
};

#endif