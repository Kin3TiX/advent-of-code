#pragma once
#include "MAIN.h"

class FILE_FACTORY {

public:

	FILE_FACTORY(string path = "");
	~FILE_FACTORY();

	bool startFactory();
	bool moreElements();
	bool getNextElement();
	bool checkElement();
	uint64_t getLit();

private:

	string inputPath;
	string currentElement;
	ifstream myFile;
	uint16_t * grid[1000];

	bool readElement();
	bool checkRegex(string, uint8_t&, uint16_t&, uint16_t&, uint16_t&, uint16_t&);
	bool processCommand(uint8_t, uint16_t, uint16_t, uint16_t, uint16_t);

};

