#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

class Entity
{
public:
	Entity();
	~Entity();

	virtual bool update() = 0;

	void X(double x);
	double X();
	
	void Y(double y);
	double Y();
private:
	double x;
	double y;	
};

#endif