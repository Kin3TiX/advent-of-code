#include "Table.h"

void Table::addGuest(Guest* g) {
	seed.push_back(g);
}

bool Table::setOrder(std::vector<int> o) {
	
	if(o.size() == seed.size()) {
		
		table.clear();
		table.resize(seed.size());
		
		for(int i = 0; i < o.size(); ++i) {
			
			table[i] = seed[o[i]];
			
		}
		
		return true;
		
	} else {
		
		return false;
		
	}
	
}

void Table::updateNeighbors() {
	
	for(int i = 0; i < table.size(); ++i) {
		
		int left, right;
		if(i == 0) {
			left = table.size()-1;
			right = i+1;
		} else if(i == table.size()-1) {
			left = i-1;
			right = 0;
		} else {
			left = i-1;
			right = i+1;
		}
		
		table[i]->setLneighbor(table[left]);
		table[i]->setRneighbor(table[right]);
		
	}
	
}

int Table::getScore() {
	
	int score = 0;
	
	for(int i = 0; i < table.size(); ++i) {
		
		score += table[i]->getHappiness();
		
	}
	
	return score;
	
}