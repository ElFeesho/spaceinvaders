#include "score.hpp"


Score::Score() : score(0)
{
	setName("score");
}

Score::~Score()
{

}

bool Score::update()
{
	number.setPosition(X(), Y());
	return isAlive();
}

bool Score::render()
{
	number.render();
	return true;
}

int Score::getId()
{
	return -1;
}

void Score::incScore(int points)
{
	score += points;
	number.setNumber(score);
}