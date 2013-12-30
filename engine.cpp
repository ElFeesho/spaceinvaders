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

	for(EntityList::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		for(EntityList::iterator target = entities.begin(); target != entities.end(); ++target)
		{
			if(it == target)
			{
				continue;
			}	

			(*it)->checkCollision((*target));
		}		
	}
}

void Engine::render()
{
	for(int i = 0; i < renderables.size();)
	{
		if(!renderables[i]->render())
		{
			renderables.erase(renderables.begin()+i);
		}
		else
		{
			++i;
		}
	}
}

Entity *Engine::findEntityByName(const string &name)
{
	for(int i = 0; i<entities.size(); i++)
	{
		if(entities[i]->getName() == name)
		{
			return entities[i];
		}
	}

	return 0;
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
		delete Engine::instance;
	}
}

Engine *Engine::instance = 0;
