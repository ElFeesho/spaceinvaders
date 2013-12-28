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
	for(int i = 0; i < entities.size();)
	{
		if(!entities[i]->update())
		{
			entities.erase(entities.begin()+i);
		}
		else
		{
			++i;
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

void Engine::shutdown()
{
	if(!Engine::instance)
	{
		Engine::instance->entities.clear();
		Engine::instance->renderables.clear();
		Engine::instance->collidables.clear();
		delete Engine::instance;
	}
}

Engine *Engine::instance = 0;
