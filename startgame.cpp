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
}