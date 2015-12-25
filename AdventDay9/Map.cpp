#include "Map.h"

void Map::addCity(City* g) {
	seed.push_back(g);
}

bool Map::setOrder(std::vector<int> o) {
	
	if(o.size() == seed.size()) {
		
		route.clear();
		route.resize(seed.size());
		
		for(int i = 0; i < o.size(); ++i) {
			
			route[i] = seed[o[i]];
			
		}
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}

void Map::updateNeighbors() {
	
	for(int i = 0; i < route.size()-1; ++i) {
		
		route[i]->setNeighbor(route[i+1]);
		
	}
	
}

int Map::getScore() {
	
	int score = 0;
	
	for(int i = 0; i < route.size()-1; ++i) {
		
		score += route[i]->getDistance();
		
	}
	
	return score;
	
}