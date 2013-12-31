#include "gamescene.hpp"

#include "ship.hpp"
#include "score.hpp"
#include "enemyarray.hpp"
#include "ufoship.hpp"

GameScene::GameScene()
{
	Ship *ship = new Ship();
	Score *score = new Score();
	EnemyArray *enemyArray = new EnemyArray();

	addEntity(ship);
	addRenderable(ship);

	addEntity(enemyArray);
	addRenderable(enemyArray);

	addEntity(score);
	addRenderable(score);

	UfoShip *ufoship = new UfoShip();
	addEntity(ufoship);
	addRenderable(ufoship);
}

GameScene::~GameScene()
{

}