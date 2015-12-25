#ifndef CITY_H
#define CITY_H

#include <string>
#include <map>

class City {

public:
	
	City(std::string);
	~City();
	
	void setNeighbor(City*);
	std::string getName();
	int getDistance();
	void addDistance(std::string, int);
	
private:
	
	std::string name;
	City* neighbor;
	std::map<std::string, int> distances;

};

#endif