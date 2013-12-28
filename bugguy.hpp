#ifndef __BUGGUY_HPP__
#define __BUGGUY_HPP__

#include "badguy.hpp"

class BugGuy : public BadGuy
{
public:
	BugGuy();
	~BugGuy();

	bool render();
};

#endif