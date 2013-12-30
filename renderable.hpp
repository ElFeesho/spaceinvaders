#ifndef __RENDERABLE_HPP__
#define __RENDERABLE_HPP__

class Renderable
{
public:
	Renderable();
	virtual ~Renderable() = 0;

	virtual bool render() = 0;
protected:
	void renderPixels(const short *data, int count, double x, double y);
	void renderPixels(const char *data, int count, double x, double y);
private:

};

#endif