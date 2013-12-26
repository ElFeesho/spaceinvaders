#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <vector>

#include "renderable.hpp"
#include "collidable.hpp"
#include "entity.hpp"

using std::vector;

typedef vector<Renderable*> RenderableList;
typedef vector<Collidable*> CollidableList;
typedef vector<Entity*> EntityList;

class Engine
{
public:
	Engine();
	~Engine();

	void addEntity(Entity *entity);
	void addRenderable(Renderable *renderable);
	void addCollidable(Collidable *collidable);

	void update(); // Entities
	void render(); // Renderables
	void processCollisions(); // Collidables
private:
	EntityList entities;
	RenderableList renderables;
	CollidableList collidables;
};

#endif