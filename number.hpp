#ifndef __NUMBER_HPP__
#define __NUMBER_HPP__

#include "renderable.hpp"

class Number : public Renderable
{
public:
	Number();
	~Number();

	bool render();

	void setNumber(int number);

	void setPosition(int x, int y);
private:
	int number;
	int x;
	int y;
};

#endif