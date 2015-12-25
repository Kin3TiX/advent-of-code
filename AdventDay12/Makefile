all: adventDay12

adventDay12: Main.o
	g++ Main.o -o adventDay12
	
Main.o: Main.cpp
	g++ -g -O0 -std=c++11 -c Main.cpp
	
clean:
	rm -rf *.o adventDay12
