#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Guest.h"

class Table {

public:	

	void addGuest(Guest*);
	bool setOrder(std::vector<int>);
	void updateNeighbors();
	int getScore();
	
private:
	
	std::vector<Guest*> table;
	std::vector<Guest*> seed;

};

#endif