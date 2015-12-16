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

private:

	string inputPath;
	string currentElement;
	ifstream myFile;

	bool readElement();
	uint16_t checkRegex(string);

};

