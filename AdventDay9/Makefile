all: adventDay9

adventDay9: Main.o Map.o City.o
	g++ Main.o City.o Map.o -o adventDay9
	
Main.o: Main.cpp
	g++ -g -O0 -std=c++11 -c Main.cpp
	
City.o: City.cpp
	g++ -g -O0 -std=c++11 -c City.cpp
	
Map.o: Map.cpp
	g++ -g -O0 -std=c++11 -c Map.cpp
	
clean:
	rm -rf *.o adventDay9
