#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include <math.h>

#include "engine.hpp"
#include "ship.hpp"
#include "bugguy.hpp"
#include "skullguy.hpp"
#include "octoguy.hpp"

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Surface *screen = SDL_SetVideoMode(640, 320, 0, SDL_SWSURFACE);

	int done = 0;
	SDL_Event event;
	long delay = 0;
	long start = 0;
	double angle = 0;

	Engine *engine = Engine::getInstance();

	Ship *ship = new Ship();
	BugGuy *baddie = new BugGuy();
	baddie->X(160);
	baddie->Y(100);

	SkullGuy *baddie2 = new SkullGuy();
	baddie2->X(200);
	baddie2->Y(100);

	OctoGuy *baddie3 = new OctoGuy();
	baddie3->X(260);
	baddie3->Y(100);

	engine->addEntity(ship);
	engine->addRenderable(ship);

	engine->addEntity(baddie);
	engine->addRenderable(baddie);

	engine->addEntity(baddie2);
	engine->addRenderable(baddie2);

	engine->addEntity(baddie3);
	engine->addRenderable(baddie3);

	while (!done)
	{
		start = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				done = 1;
			}
		}

		SDL_FillRect(screen, NULL, 0x00000000);

		engine->update();
		engine->render();

		SDL_Flip(screen);

		delay = (1000/60) - (SDL_GetTicks()-start);
		if (delay > 0)
		{
			SDL_Delay(delay);
		}
	}

	Engine::shutdown();

	SDL_FreeSurface(screen);

	SDL_Quit();
	return 0;
}
