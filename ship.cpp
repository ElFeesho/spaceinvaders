#include "ship.hpp"

#include <SDL/SDL.h>

#include "engine.hpp"
#include "bullet.hpp"

Ship::Ship() : lastShot(0)
{
	setRadius(16);
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
	if(keystate[SDLK_SPACE] && SDL_GetTicks() > lastShot+333 && !Engine::getInstance()->findEntityByName("bullet"))
	{
		Bullet *bullet = new Bullet();
		bullet->X(X()+getRadius());
		bullet->Y(Y());

		Engine::getInstance()->addEntity(bullet);
		Engine::getInstance()->addRenderable(bullet);

		lastShot = SDL_GetTicks();
	}

	if(X()<10)
	{
		X(10);
	}
	else if(X()>screen->w-(getRadius()*2)-10)
	{
		X(screen->w-(getRadius()*2)-10);
	}
	
	return isAlive();
}

int Ship::getId()
{
	return 0;
}

bool Ship::render()
{
	SDL_Surface *screen = SDL_GetVideoSurface();
	SDL_Rect body = { X(), Y()+getRadius(), getRadius()*2, getRadius()};
	SDL_Rect upperBody = { X()+5, Y()+getRadius()/2, getRadius()*2-10, getRadius()/2 };
	SDL_Rect funnel = { X()+getRadius()-2, Y(), 4, getRadius() };
	SDL_FillRect(screen, &body, 0xffffffff);
	SDL_FillRect(screen, &upperBody, 0xffffffff);
	SDL_FillRect(screen, &funnel, 0xffffffff);

	return isAlive();
}

void Ship::hasCollided(Collidable *with)
{

}