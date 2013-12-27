#include "engine.hpp"

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::addEntity(Entity *entity)
{
	entities.push_back(entity);
}

void Engine::addRenderable(Renderable *renderable)
{
	renderables.push_back(renderable);
}

void Engine::addCollidable(Collidable *collidable)
{
	collidables.push_back(collidable);
}

void Engine::update()
{
	for(EntityList::iterator it = entities.begin(); it != entities.end();)
	{
		if(!(*it)->update())
		{
			it = entities.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Engine::render()
{
	for(RenderableList::iterator it = renderables.begin(); it != renderables.end(); ++it)
	{
		(*it)->render();
	}
}

void Engine::processCollisions()
{
	for(CollidableList::iterator it = collidables.begin(); it != collidables.end(); ++it)
	{
		for(CollidableList::iterator target = collidables.begin(); target != collidables.end(); ++target)
		{
			if(it == target)
			{
				continue;
			}	

			(*it)->checkCollision((*target));
		}		
	}
}

Engine *Engine::getInstance()
{
	if(!Engine::instance)
	{
		Engine::instance = new Engine();
	}
	return Engine::instance;
}

Engine *Engine::instance = 0;
