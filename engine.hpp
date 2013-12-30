#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <vector>
#include <string>

#include "renderable.hpp"
#include "collidable.hpp"
#include "entity.hpp"

using std::vector;
using std::string;

typedef vector<Renderable*> RenderableList;
typedef vector<Collidable*> CollidableList;
typedef vector<Entity*> EntityList;

class Engine
{
public:
	static Engine *getInstance();
	static void shutdown();

	void addEntity(Entity *entity);
	void addRenderable(Renderable *renderable);

	void update(); // Entities
	void render(); // Renderables

	Entity *findEntityByName(const string &name);
private:
	Engine();
	~Engine();

	static Engine *instance;

	EntityList entities;
	RenderableList renderables;
};

#endif