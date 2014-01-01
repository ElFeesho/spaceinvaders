#include <SDL/SDL.h>

#include "startgame.hpp"

#include "engine.hpp"
#include "gamescene.hpp"

StartGame::StartGame()
{
	SDL_Surface *screen = SDL_GetVideoSurface();

	skullguy = new SkullGuy();
	bugguy = new BugGuy();
	ufoship = new UfoShip();
	octoguy = new OctoGuy();

	skullguy->X(screen->w/3);
	bugguy->X(screen->w/3);
	ufoship->X(screen->w/3);
	octoguy->X(screen->w/3);

	skullguy->Y(screen->h/3);
	bugguy->Y(screen->h/3+30);
	octoguy->Y(screen->h/3+60);
	ufoship->Y(screen->h/3+90);

	scoreIndicator = new Number();
}

StartGame::~StartGame()
{

}

void StartGame::update()
{
	Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_SPACE])
	{
		Engine::getInstance()->popScene();

		GameScene *gameScene = new GameScene();

		Engine::getInstance()->pushScene(gameScene);
	}
}

void StartGame::render()
{
	skullguy->render();
	bugguy->render();
	ufoship->render();
	octoguy->render();

	scoreIndicator->setPosition(skullguy->X()+50, skullguy->Y());
	scoreIndicator->setNumber(10);
	scoreIndicator->render();

	scoreIndicator->setPosition(bugguy->X()+50, bugguy->Y());
	scoreIndicator->setNumber(20);
	scoreIndicator->render();

	scoreIndicator->setPosition(octoguy->X()+50, octoguy->Y());
	scoreIndicator->setNumber(30);
	scoreIndicator->render();

	scoreIndicator->setPosition(ufoship->X()+50, ufoship->Y());
	scoreIndicator->setNumber(1000);
	scoreIndicator->render();
}