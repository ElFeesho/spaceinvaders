#include "enemyarray.hpp"

#include "skullguy.hpp"
#include "bugguy.hpp"
#include "octoguy.hpp"

#include <SDL/SDL.h>

BadGuyList* createEnemyArray(int x)
{
	BadGuyList *list = new BadGuyList();
	OctoGuy *octoguy = new OctoGuy();
	octoguy->X(x);
	octoguy->Y(0);

	list->push_back(octoguy);

	BugGuy *bugguy = new BugGuy();

	bugguy->X(x);
	bugguy->Y(30);

	list->push_back(bugguy);

	bugguy = new BugGuy();
	bugguy->X(x);
	bugguy->Y(60);
	list->push_back(bugguy);

	SkullGuy *skullguy = new SkullGuy();
	skullguy->X(x);
	skullguy->Y(90);

	list->push_back(skullguy);

	skullguy = new SkullGuy();
	skullguy->X(x);
	skullguy->Y(120);
	list->push_back(skullguy);

	return list;
}

double getMaxX(vector<BadGuyList*> &list)
{
	vector<BadGuy*> *end = (*(list.end()-1));
	BadGuy *baddie = (*end)[0];
	return baddie->X();
}

double getMinX(vector<BadGuyList*> &list)
{
	vector<BadGuy*> *first = (*list.begin());
	return (*first)[0]->X();
}

EnemyArray::EnemyArray()
{
	badGuyLists.push_back(createEnemyArray(0));
	badGuyLists.push_back(createEnemyArray(40));
	badGuyLists.push_back(createEnemyArray(80));
	badGuyLists.push_back(createEnemyArray(120));
	badGuyLists.push_back(createEnemyArray(160));
	badGuyLists.push_back(createEnemyArray(200));
	badGuyLists.push_back(createEnemyArray(240));
	badGuyLists.push_back(createEnemyArray(280));
	badGuyLists.push_back(createEnemyArray(320));
	badGuyLists.push_back(createEnemyArray(360));
	badGuyLists.push_back(createEnemyArray(400));
	badGuyLists.push_back(createEnemyArray(440));
	movingRight = true;
	lastUpdate = 0;
}

EnemyArray::~EnemyArray()
{

}

bool EnemyArray::update()
{
	bool success = false;
	int xmove = 0;
	int ymove = 0;
	if(SDL_GetTicks() > lastUpdate+1000)
	{
		lastUpdate = SDL_GetTicks();
		if(movingRight)
		{
			if(getMaxX(badGuyLists) > SDL_GetVideoSurface()->w-30)
			{
				ymove = 30;
				movingRight = false;
			}
			else
			{
				xmove = 30;
			}
		}
		else
		{
			if(getMinX(badGuyLists) <= 0)
			{
				ymove = 30;
				movingRight = true;
			}
			else
			{
				xmove = -30;
			}
		}
	}

	for(int i = 0; i < badGuyLists.size(); i++)
	{
		for(int k = 0; k < badGuyLists[i]->size(); k++)
		{
			BadGuy *baddie = (*badGuyLists[i])[k];
			baddie->X(baddie->X()+xmove);
			baddie->Y(baddie->Y()+ymove);
			success |= baddie->update();
		}
	}

	return success;
}

bool EnemyArray::render()
{
	bool success = false;
	for(int i = 0; i < badGuyLists.size(); i++)
	{
		for(int k = 0; k < badGuyLists[i]->size(); k++)
		{
			success |= (*badGuyLists[i])[k]->render();
		}
	}
	return success;
}

void EnemyArray::checkCollision(Collidable *target)
{
	for(int i = 0; i < badGuyLists.size(); i++)
	{
		for(int k = 0; k < badGuyLists[i]->size(); k++)
		{
			(*badGuyLists[i])[k]->checkCollision(target);
		}
	}

	// Now that we've checked collision we need to purge all the
	// dead bad guys

	for(int i = 0; i < badGuyLists.size(); i++)
	{
		for(int k = 0; k < badGuyLists[i]->size(); k++)
		{
			if(!(*badGuyLists[i])[k]->isAlive())
			{
				(*badGuyLists[i]).erase((*badGuyLists[i]).begin()+k);	
			}

			// Check to see if this list is empty now

			if((*badGuyLists[i]).empty())
			{
				badGuyLists.erase(badGuyLists.begin()+i);
			}
		}
	}


}

void EnemyArray::hasCollided(Collidable *victim)
{

}

int EnemyArray::getId()
{
	return -1;
}