#ifndef __STARTGAME_HPP__
#define __STARTGAME_HPP__

#include "scene.hpp"

#include "skullguy.hpp"
#include "octoguy.hpp"
#include "bugguy.hpp"
#include "ufoship.hpp"

#include "number.hpp"

class StartGame : public Scene
{
public:
	StartGame();
	~StartGame();

	void render();
	void update();

private:
	SkullGuy *skullguy;
	BugGuy *bugguy;
	OctoGuy *octoguy;
	UfoShip *ufoship;
	Number *scoreIndicator;
};

#endif