#pragma once
#include "Main.h"
#include "PRESENT.h"

class PRESENT_FACTORY {

public:

	PRESENT_FACTORY(string path = "");
	~PRESENT_FACTORY();

	bool startFactory();
	bool morePresents();
	bool getNextPresent(PRESENT&);

private:

	string inputPath;
	string currentPresent;
	ifstream myFile;

	bool readPresent();
	vector<uint16_t> getDimensions();

};

