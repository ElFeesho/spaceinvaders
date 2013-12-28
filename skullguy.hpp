#ifndef __SKULLGUY_HPP__
#define __SKULLGUY_HPP__

#include "badguy.hpp"

class SkullGuy : public BadGuy
{
public:
	SkullGuy();
	~SkullGuy();

	bool render();
};

#endif