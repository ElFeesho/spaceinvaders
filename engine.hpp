#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <vector>

using std::vector;

typedef vector<Renderable*> RenderableList;
typedef vector<Collidable*> CollidableList;
typedef vector<Entity*> EntityList;

class Engine
{
public:
	Engine();
	~Engine();

	void update();
	void render();
	void processCollisions();
private:

};

#endif