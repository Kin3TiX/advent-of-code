all: adventDay13

adventDay13: Main.o Guest.o Table.o
	g++ Main.o Guest.o Table.o -o adventDay13 
	
Main.o: Main.cpp
	g++ -g -O0 -std=c++11 -c Main.cpp
	
Guest.o: Guest.cpp
	g++ -g -O0 -std=c++11 -c Guest.cpp
	
Table.o: Table.cpp
	g++ -g -O0 -std=c++11 -c Table.cpp
	
clean:
	rm -rf *.o adventDay13
