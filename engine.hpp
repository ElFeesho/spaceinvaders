#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <vector>
#include <string>

#include "scene.hpp"

class Engine
{
public:
	static Engine *getInstance();
	static void shutdown();

	void update(); // Entities
	void render(); // Renderables

	void pushScene(Scene *scene);
	void popScene();

	Scene *getActiveScene();
private:
	Engine();
	~Engine();

	static Engine *instance;

	vector<Scene*> scenes;

};

#endif