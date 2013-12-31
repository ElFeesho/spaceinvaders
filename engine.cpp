#include "engine.hpp"

Engine::Engine()
{

}

Engine::~Engine()
{

}


void Engine::pushScene(Scene *scene)
{
	scenes.push_back(scene);
}

void Engine::popScene()
{
	scenes.pop_back();
}


void Engine::update()
{
	for(int i = 0; i<scenes.size(); i++)
	{
		scenes[i]->update();
	}
}

void Engine::render()
{
	for(int i = 0; i<scenes.size(); i++)
	{
		scenes[i]->render();
	}	
}

Scene *Engine::getActiveScene()
{
	return (*(scenes.end()-1));
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
		Engine::instance->scenes.clear();
		delete Engine::instance;
	}
}

Engine *Engine::instance = 0;
