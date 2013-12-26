#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

class Renderable
{
public:
	Renderable();
	virtual ~Renderable() = 0;

	virtual void render() = 0;
private:

};

#endif