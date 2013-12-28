#ifndef __OCTOGUY_HPP__
#define __OCTOGUY_HPP__

#include "badguy.hpp"

class OctoGuy : public BadGuy
{
public:
	OctoGuy();
	~OctoGuy();

	bool render();
};
#endif