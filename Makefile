CC = g++
CFLAGS = -g -Wall -std=c++11

default: hw8

hw8: Zombieland.o Graph.o
	$(CC) $(CFLAGS) -o hw8 Zombieland.o Graph.o

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

Zombieland.o: Zombieland.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Zombieland.cpp

clean:
	$(RM) hw8 *o *~
