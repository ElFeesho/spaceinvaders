#include "renderable.hpp"

#include <SDL/SDL.h>

Renderable::Renderable()
{
	
}

Renderable::~Renderable()
{
	
}

void Renderable::renderPixels(const short *data, int count, double x, double y, int colour)
{
	SDL_Rect brush = { x, y, 2, 2 };
	for(int i = 0; i < count; i++)
	{
		brush.x = x;
		for(int x = 0; x < 16; x++)
		{
			if(((data[i] >> (15-x)) & 0x1) == 1)
			{
				SDL_FillRect(SDL_GetVideoSurface(), &brush, colour);
			}
			brush.x += brush.w;
		}
		brush.y += brush.h;
	}
}

void Renderable::renderPixels(const char *data, int count, double x, double y, int colour)
{
	SDL_Rect brush = { x, y, 2, 2 };
	for(int i = 0; i < count; i++)
	{
		brush.x = x;
		for(int x = 0; x < 8; x++)
		{
			if(((data[i] >> (7-x)) & 0x1) == 1)
			{
				SDL_FillRect(SDL_GetVideoSurface(), &brush, colour);
			}
			brush.x += brush.w;
		}
		brush.y += brush.h;
	}
}