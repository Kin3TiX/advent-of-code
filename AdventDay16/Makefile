DEBUG =

all: adventDay16

debug: DEBUG += -g -O0
debug: adventDay16

adventDay16: Main.o Sue.o
	g++ Main.o Sue.o -o adventDay16
	
Main.o: Main.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Main.cpp
	
Sue.o: Sue.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Sue.cpp
	
clean:
	rm -rf *.o adventDay16