#include "HOUSE_DIRECTOR.h"

HOUSE_DIRECTOR::HOUSE_DIRECTOR(string path) { 

	myDirections = path;

}

HOUSE_DIRECTOR::~HOUSE_DIRECTOR() { }

bool HOUSE_DIRECTOR::startDirector() {

	myFile.open(myDirections);

	if( myFile )
		return true;
	else
		return false;

}

HOUSE_DIRECTOR::direction HOUSE_DIRECTOR::getNextDirection() {

	char symbol;
	myFile.peek();

	if( myFile.eof() ) {

		return END;

	}  else {

		symbol = myFile.get();

	}

	switch( symbol ) {

		case '^':
			return NORTH;

		case 'v':
			return SOUTH;

		case '>':
			return EAST;

		case '<':
			return WEST;

		default:
			return ERROR;

	}

}
