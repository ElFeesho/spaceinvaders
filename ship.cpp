#include "ship.hpp"

#include <SDL/SDL.h>

#include "engine.hpp"
#include "bullet.hpp"

Ship::Ship()
{
	SDL_Surface *screen = SDL_GetVideoSurface();
	X(screen->w / 2 - getRadius());
	Y(screen->h - getRadius()*2 - 10);
}

Ship::~Ship()
{

}

bool Ship::update()
{
	SDL_Surface *screen = SDL_GetVideoSurface();

	Uint8 *keystate = SDL_GetKeyState(NULL);
	if(keystate[SDLK_LEFT])
	{
		X(X()-3);
	}
	if(keystate[SDLK_RIGHT])
	{
		X(X()+3);
	}
	if(keystate[SDLK_SPACE])
	{
		Bullet *bullet = new Bullet();
		bullet->X(X()+getRadius());
		bullet->Y(Y());

		Engine::getInstance()->addEntity(bullet);
		Engine::getInstance()->addCollidable(bullet);
		Engine::getInstance()->addRenderable(bullet);
	}

	if(X()<10)
	{
		X(10);
	}
	else if(X()>screen->w-(getRadius()*2)-10)
	{
		X(screen->w-(getRadius()*2)-10);
	}
	
	return true;
}

int Ship::getId()
{
	return 0;
}

void Ship::render()
{
	SDL_Surface *screen = SDL_GetVideoSurface();
	SDL_Rect rect = { X(), Y(), 32, 32 };
	SDL_FillRect(screen, &rect, 0xffffffff);
}

double Ship::getRadius()
{
	return 16;
}

double Ship::getX()
{
	return X();
}

double Ship::getY()
{
	return Y();
}

void Ship::hasCollided(Collidable *with)
{

}