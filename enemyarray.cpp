#include "enemyarray.hpp"

#include "skullguy.hpp"
#include "bugguy.hpp"
#include "octoguy.hpp"

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
	for(int i = 0; i < badGuyLists.size(); i++)
	{
		for(int k = 0; k < badGuyLists[i]->size(); k++)
		{
			success |= (*badGuyLists[i])[k]->update();
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

}

void EnemyArray::hasCollided(Collidable *victim)
{

}

int EnemyArray::getId()
{
	return -1;
}