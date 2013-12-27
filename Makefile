OBJS=main.o engine.o entity.o collidable.o ship.o renderable.o bullet.o
LIBS=`pkg-config --libs sdl SDL_gfx`
CFLAGS=`pkg-config --cflags sdl SDL_gfx` -g
PROG=spaceinvaders

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(PROG)
