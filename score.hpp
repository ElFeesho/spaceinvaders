#ifndef __SCORE_HPP__
#define __SCORE_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Score : public Entity, public Renderable
{
public:
	Score();
	~Score();

	bool update();
	bool render();

	int getId();

private:
	int score;
};

#endif