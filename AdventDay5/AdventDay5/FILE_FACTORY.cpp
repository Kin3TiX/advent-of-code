#include "FILE_FACTORY.h"

FILE_FACTORY::FILE_FACTORY(string path) { 

	inputPath = path;

}

FILE_FACTORY::~FILE_FACTORY() { }

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

	//bool doubles	= ( checkRegex("((.)\\2)") >= 1 );
	//bool vowels		= ( checkRegex("([aeiou])") >= 3 );
	//bool excludes	= ( checkRegex("(ab|cd|pq|xy)") == 0 );

	bool newDoubles = (checkRegex("((.).\\2)") >= 1);
	bool newRepeats = (checkRegex("((..).*\\2)") >= 1);

	return newDoubles && newRepeats;
	//return doubles && vowels && excludes;

}

uint16_t FILE_FACTORY::checkRegex(string exp) {

	uint16_t count = 0;
	regex parser(exp, regex_constants::ECMAScript | regex_constants::icase);
	sregex_token_iterator end;
	sregex_token_iterator pos(currentElement.begin(), currentElement.end(), parser);

	while( pos != end ) {

		++count;
		++pos;

	}

	return count;

}

