#include "ufoship.hpp"
#include "engine.hpp"
#include "scene.hpp"
#include "score.hpp"

#include <SDL/SDL.h>

static const short SPRITE[] = {
								0x07e0,  // 0000 0xxx xxx0 0000
								0x1ff8,  // 000x xxxx xxxx x000
								0x3ffc,  // 00xx xxxx xxxx xx00
								0x6db6,  // 0xx0 xx0x x0xx 0xx0
								0xffff,  // xxxx xxxx xxxx xxxx
								0x399c,  // 00xx x00x x00x xx00
								0x1008,  // 000x 0000 0000 x000
};

UfoShip::UfoShip()
{
	Y(32);
	X(-100);
	setRadius(32);
}

UfoShip::~UfoShip()
{
}

bool UfoShip::update()
{
	if(X()<SDL_GetVideoSurface()->w - 32)
	{
		X(X()+2);
	}
	else
	{
		kill();
	}
	return isAlive();
}

bool UfoShip::render()
{
	renderPixels(SPRITE, 8, X(), Y(), 0xffff0000);
	return isAlive();
}

void UfoShip::checkCollision(Collidable *collidable)
{
	int rs = collidable->getX()+collidable->getRadius();
	int b = collidable->getY()+collidable->getRadius();
	int l = collidable->getX();
	int t = collidable->getY();
	if((rs > getX() && rs < getX()+getRadius()) || (l > getX() && l<getX()+getRadius()))
	{
		if ((t < getY()+getRadius() && t > getY()) || (b > getY() && b < getY()+getRadius()))
		{
			hasCollided(collidable);
		}
	}
}

void UfoShip::hasCollided(Collidable *target)
{
	if(target->getId() == 1)
	{
		kill();
		Score *score = (Score*)Engine::getInstance()->getActiveScene()->findEntityByName("score");
		score->incScore(1000);
	}
}

int UfoShip::getId()
{
	return 5;
}