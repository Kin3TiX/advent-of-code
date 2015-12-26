all: adventDay14

adventDay14: Main.o Reindeer.o
	g++ Main.o Reindeer.o -lpthread -o adventDay14
	
Main.o: Main.cpp
	g++ -g -O0 -std=c++11 -c Main.cpp
	
Reindeer.o: Reindeer.cpp
	g++ -g -O0 -std=c++11 -c Reindeer.cpp
	
clean:
	rm -rf *.o adventDay14