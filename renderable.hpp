#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

class Renderable
{
public:
	Renderable();
	virtual ~Renderable() = 0;

	virtual bool render() = 0;
protected:
	void renderPixels(const short *data, int count, double x, double y, int colour = 0xffffffff);
	void renderPixels(const char *data, int count, double x, double y, int colour = 0xffffffff);
private:

};

#endif