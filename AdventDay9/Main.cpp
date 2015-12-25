#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <map>
#include "City.h"
#include "Map.h"

int main() {

	std::ifstream input("input.txt");
	std::regex parser("(.+)\\sto\\s(.+)\\s=\\s(.+)");
	std::smatch matches;
	std::string buffer;
	std::map<std::string, City*> cities;
	Map map;
	
	while(getline(input, buffer)) {
		
		regex_match(buffer, matches, parser);
		
		int value = std::stoi(matches[3]);
		
		std::map<std::string, City*>::iterator element = cities.find(matches[1]);
		if( element == cities.end() ) {
			City* temp = new City(matches[1]);
			temp->addDistance(matches[2], value);
			map.addCity(temp);
			cities.insert( std::pair<std::string, City*>(matches[1], temp) );
		} else {
			(*element).second->addDistance(matches[2], value);
		}
		
		element = cities.find(matches[2]); 
		if( element == cities.end() ) {
			City* temp = new City(matches[2]);
			temp->addDistance(matches[1], value);
			map.addCity(temp);
			cities.insert( std::pair<std::string, City*>(matches[2], temp) );
		} else {
			(*element).second->addDistance(matches[1], value);
		}
		
	}
	
	std::vector<int> perms(cities.size());
	std::iota(perms.begin(), perms.end(), 0);
	int optimal = 0;
	bool start = true;
	do {
		
		int score = 0;
		if(map.setOrder(perms)) {
			map.updateNeighbors();
			score = map.getScore();
			/*
			if(start) {
				optimal = score;
				start = false;
			}
			*/
			if( score /*<*/ > optimal )
				optimal = score;
		} else {
			return -1;
		}
		
	} while(next_permutation(perms.begin(), perms.end()));
	
	std::cout << "The optimal score is: " << optimal << std::endl;
	
}