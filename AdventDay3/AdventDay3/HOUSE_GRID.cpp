#include "HOUSE_GRID.h"

HOUSE_GRID::HOUSE_GRID(string name) {

	myName = name;
	myLocation.x = 0;
	myLocation.y = 0;
	markGrid();

}

HOUSE_GRID::~HOUSE_GRID() { }

void HOUSE_GRID::moveNorth() { 

	myLocation.y++;
	markGrid();

}

void HOUSE_GRID::moveSouth() { 

	myLocation.y--;
	markGrid();

}

void HOUSE_GRID::moveEast() { 

	myLocation.x++;
	markGrid();

}

void HOUSE_GRID::moveWest() { 

	myLocation.x--;
	markGrid();

}

void HOUSE_GRID::resetGrid() { 

	myLocation.x = 0;
	myLocation.y = 0;
	myGrid.clear();

}

uint32_t HOUSE_GRID::getGridUniques() {

	return myGrid.size();

}

void HOUSE_GRID::mergeGrids(HOUSE_GRID & incoming) {

	myGrid.insert(incoming.myGrid.begin(), incoming.myGrid.end());

}

bool HOUSE_GRID::operator==(const HOUSE_GRID & rhs) {

	return myName == rhs.myName;

}

void HOUSE_GRID::markGrid() {

	updateKey();
	myGrid.emplace(locationKey, true);

}

void HOUSE_GRID::updateKey() {

	locationKey = "x" + to_string(myLocation.x) + "::" + to_string(myLocation.y) + "y";

}
