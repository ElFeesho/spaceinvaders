#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

class Renderable
{
public:
	Renderable();
	~Renderable();

	virtual void render() = 0;
private:

};

#endif