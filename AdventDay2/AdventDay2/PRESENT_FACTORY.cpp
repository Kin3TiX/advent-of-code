#include "PRESENT_FACTORY.h"

PRESENT_FACTORY::PRESENT_FACTORY(string path) { 

	inputPath = path;

}

PRESENT_FACTORY::~PRESENT_FACTORY() { }

bool PRESENT_FACTORY::startFactory() {

	myFile.open(inputPath);

	if(myFile)
		return true;
	else
		return false;

}

bool PRESENT_FACTORY::morePresents() {

	myFile.peek();
	return !myFile.eof();

}

bool PRESENT_FACTORY::getNextPresent(PRESENT & inputPresent) {

	if( readPresent() ) {

		vector<uint16_t> dims = getDimensions();
		if( dims.empty() )
			return false;
		PRESENT myPresent(dims[0], dims[1], dims[2]);
		inputPresent = myPresent;

		return true;

	} else {

		return false;

	}

}

bool PRESENT_FACTORY::readPresent() {

	char buffer[64];
	myFile.getline(buffer, 64);
	currentPresent = string(buffer);

	if( currentPresent.empty() )
		return false;
	else
		return true;

}

vector<uint16_t> PRESENT_FACTORY::getDimensions() {

	static regex parser( "([0-9]+)", regex_constants::ECMAScript | regex_constants::icase );
	static sregex_token_iterator end;

	sregex_token_iterator pos(currentPresent.begin(), currentPresent.end(), parser);
	vector<uint16_t> matches;

	while( pos != end ) {

		string test = (*pos).str();
		matches.push_back(stoul((*pos).str()));
		++pos;

	}

	if( !matches.empty() && (matches.size() == 3) )
		return matches;
	else
		return vector<uint16_t>();

}
