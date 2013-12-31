#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <vector>
#include "entity.hpp"
#include "renderable.hpp"

using std::vector;
using std::string;

typedef vector<Renderable*> RenderableList;
typedef vector<Entity*> EntityList;

class Scene
{
public:
	Scene();
	~Scene();

	void addEntity(Entity *entity);
	void addRenderable(Renderable *renderable);

	virtual void update();
	virtual void render();
	
	Entity *findEntityByName(const string &name);
private:
	EntityList entities;
	RenderableList renderables;
};

#endif