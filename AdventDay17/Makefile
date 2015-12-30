DEBUG =

all: adventDay17

debug: DEBUG += -g -O0
debug: adventDay17

adventDay17: Main.o
	g++ Main.o -o adventDay17
	
Main.o: Main.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Main.cpp
	
clean:
	rm -rf *.o adventDay17