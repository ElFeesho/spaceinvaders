OBJS=main.o engine.o entity.o \
collidable.o ship.o renderable.o \
bullet.o badguy.o bugguy.o skullguy.o \
octoguy.o enemyarray.o score.o scene.o \
gamescene.o startgame.o ufoship.o

LIBS=`pkg-config --libs sdl SDL_gfx`
CFLAGS=`pkg-config --cflags sdl SDL_gfx` -g -O0
PROG=spaceinvaders

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(PROG)
