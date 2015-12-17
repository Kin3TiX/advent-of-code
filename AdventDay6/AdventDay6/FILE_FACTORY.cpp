#include "FILE_FACTORY.h"

FILE_FACTORY::FILE_FACTORY(string path) { 

	inputPath = path;

	for( int i = 0; i < 1000; i++ )
		grid[i] = (uint16_t *) calloc(1000, sizeof(uint16_t));

}

FILE_FACTORY::~FILE_FACTORY() { 

	for( int i = 0; i < 1000; i++ )
		free(grid[i]);

}

bool FILE_FACTORY::startFactory() {

	myFile.open(inputPath);

	if(myFile)
		return true;
	else
		return false;

}

bool FILE_FACTORY::moreElements() {

	myFile.peek();
	return !myFile.eof();

}

bool FILE_FACTORY::getNextElement() {

	return readElement();

}

bool FILE_FACTORY::readElement() {

	char buffer[64];
	myFile.getline(buffer, 64);
	currentElement = string(buffer);

	return !currentElement.empty();

}

bool FILE_FACTORY::checkElement() {

	uint8_t		mode	= 0;
	uint16_t	startX	= 0;
	uint16_t	startY	= 0;
	uint16_t	endX	= 0;
	uint16_t	endY	= 0;

	bool success = checkRegex("(.+)\\s([0-9]+),([0-9]+).+\\s([0-9]+),([0-9]+)", mode, startX, startY, endX, endY);

	if( success ) {
		return processCommand(mode, startX, startY, endX, endY);
	} else {
		return false;
	}

}

uint64_t FILE_FACTORY::getLit() {

	uint64_t count = 0;

	for(int x = 0 ; x < 1000; x++ ) {

		for(int y = 0 ; y < 1000; y++ ) {

			count += grid[x][y];

		}

	}
	
	return count;

}

bool FILE_FACTORY::checkRegex(string exp, uint8_t & mode, uint16_t & x1, uint16_t & y1, uint16_t & x2, uint16_t & y2) {

	string temp;
	uint8_t count = 0;
	static regex parser(exp, regex_constants::ECMAScript | regex_constants::icase);
	smatch matches;
	regex_match(currentElement, matches, parser);
	
	if( matches.size() == 6 ) {

		if( matches[1].str() == "turn on" )
			mode = 1;
		else if( matches[1].str() == "turn off" )
			mode = 2;
		else if( matches[1].str() == "toggle" )
			mode = 3;
		else
			return false;

		x1 = stoi(matches[2].str());
		y1 = stoi(matches[3].str());
		x2 = stoi(matches[4].str());
		y2 = stoi(matches[5].str());

		return true;

	} else {

		return false;

	}

}

bool FILE_FACTORY::processCommand(uint8_t mode, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {

	for(int x = x1 ; x <= x2; x++ ) {

		for(int y = y1 ; y <= y2; y++ ) {

			switch( mode ) {

				case 1:
					grid[x][y] += 1;
					break;
				case 2:
					if( grid[x][y] > 0 )
						grid[x][y] -= 1;
					break;
				case 3:
					grid[x][y] += 2;
					break;

			}

		}

	}

	return true;

}

