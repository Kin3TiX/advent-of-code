#ifndef MAP_H
#define MAP_H

#include <vector>
#include "City.h"

class Map {

public:	

	void addCity(City*);
	bool setOrder(std::vector<int>);
	void updateNeighbors();
	int getScore();
	
private:
	
	std::vector<City*> route;
	std::vector<City*> seed;

};

#endif