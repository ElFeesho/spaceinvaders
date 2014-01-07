#include "ship.hpp"

#include <SDL/SDL.h>

#include "engine.hpp"
#include "bullet.hpp"

static const short SPRITE_SHIP[] = {
										0x0100,  // 0000 000x 0000 0000
										0x0380,  // 0000 00xx x000 0000
										0x0380,  // 0000 00xx x000 0000
										0x7ffc,  // 0xxx xxxx xxxx xx00
										0xfffe,  // xxxx xxxx xxxx xxx0
										0xfffe,  // xxxx xxxx xxxx xxx0
										0xfffe,  // xxxx xxxx xxxx xxx0
										0xfffe   // xxxx xxxx xxxx xxx0
};						

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
	if(keystate[SDLK_SPACE] && SDL_GetTicks() > lastShot+333 && !Engine::getInstance()->getActiveScene()->findEntityByName("bullet"))
	{
		Bullet *bullet = new Bullet();
		bullet->X(X()+getRadius());
		bullet->Y(Y());

		Engine::getInstance()->getActiveScene()->addEntity(bullet);

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
	renderPixels(SPRITE_SHIP, 8, X(), Y());

	return isAlive();
}

void Ship::hasCollided(Collidable *with)
{

}
