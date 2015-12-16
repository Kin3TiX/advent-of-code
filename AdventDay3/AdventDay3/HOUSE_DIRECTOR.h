#pragma once
#include "Main.h"
#include "HOUSE_GRID.h"

class HOUSE_DIRECTOR {

public:

	typedef enum direction {
		NORTH, SOUTH, EAST, WEST, END, ERROR
	};

	HOUSE_DIRECTOR(string path = "");
	~HOUSE_DIRECTOR();

	bool startDirector();
	direction getNextDirection();

private:

	ifstream myFile;
	string myDirections;

};

