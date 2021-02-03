CC=g++
LINK-FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all: game

game: main.o
	 $(CC) main.o -o game $(LINK-FLAGS)

main.o: main.cpp
	 $(CC) -c main.cpp

clean:
	 rm main.o game
