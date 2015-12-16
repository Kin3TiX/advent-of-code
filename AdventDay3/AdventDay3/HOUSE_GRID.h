#pragma once
#include "Main.h"

class HOUSE_GRID {

public:

	HOUSE_GRID(string name = "santa");
	~HOUSE_GRID();

	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void resetGrid();
	uint32_t getGridUniques();
	void mergeGrids(HOUSE_GRID&);
	bool operator==(const HOUSE_GRID& rhs);

private:

	typedef struct coordinates {
		int x;
		int y;
	};

	typedef unordered_map<string, bool> grid;

	string locationKey;
	coordinates myLocation;
	grid myGrid;
	string myName;

	void markGrid();
	void updateKey();

};

