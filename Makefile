CC=g++

all: dijkstras.cpp
	$(CC) -o dj dijkstras.cpp

dijkstras: dijkstras.cpp
	./dj
