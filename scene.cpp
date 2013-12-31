#include "scene.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::addEntity(Entity *entity)
{
	entities.push_back(entity);
}

void Scene::addRenderable(Renderable *renderable)
{
	renderables.push_back(renderable);
}

void Scene::update()
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

void Scene::render()
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


Entity *Scene::findEntityByName(const string &name)
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