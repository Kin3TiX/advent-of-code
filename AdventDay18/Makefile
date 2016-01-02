DEBUG =
TARGET = adventDay18

all: $(TARGET)

debug: DEBUG += -g -O0
debug: $(TARGET)

$(TARGET): Main.o
	g++ Main.o -o $(TARGET)
	
Main.o: Main.cpp
	g++ $(DEBUG) -std=c++11 -Wall -c Main.cpp
	
clean:
	rm -rf *.o $(TARGET)