OBJS=main.o ship.o \
bullet.o badguy.o bugguy.o skullguy.o \
octoguy.o enemyarray.o score.o \
gamescene.o startgame.o ufoship.o number.o

LIBS=`pkg-config --libs sdl SDL_gfx` -L../sge -lsge
CFLAGS=`pkg-config --cflags sdl SDL_gfx` -g -O0 -I../sge
PROG=spaceinvaders

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CFLAGS) $< -c

clean:
	rm -f $(OBJS) $(PROG)
