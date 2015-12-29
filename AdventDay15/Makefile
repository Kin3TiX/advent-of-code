DEBUG =

all: adventDay15

debug: DEBUG += -g -O0
debug: adventDay15

adventDay15: Main.o Recipe.o
	g++ Main.o Recipe.o -o adventDay15
	
Main.o: Main.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Main.cpp
	
Recipe.o: Recipe.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Recipe.cpp
	
clean:
	rm -rf *.o adventDay15