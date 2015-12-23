#include <iostream>
#include <fstream>
#include <string>

int main() {
	
	std::ifstream myFIle("input.txt");
	std::string buffer;
	int codeCount = 0;
	int encodedCount = 0;
	int literalCount = 0;
	
	while(getline(myFIle, buffer)) {
		codeCount += buffer.size();
		encodedCount += buffer.size() + 4;
		bool wait = false;
		int hexWait = 0;
		for(std::string::iterator i = buffer.begin()+1; i != buffer.end()-1; ++i) {	
			const char next = *(i+1);
			if(wait) {
				if((*i) == '\\' || (*i) == '\"') {
					wait = false;
					literalCount += 1;
				} else {
					if(hexWait != 2) {
						hexWait += 1;
					}
					else {
						wait = false;
						hexWait = 0;
						literalCount += 1;
					}
				}
			} else {
				if((*i) == '\\') {
					if(next == 'x')
						encodedCount += 1;
					else
						encodedCount += 2;
					wait = true;
					hexWait = 0;
				} else {
					literalCount += 1;
				}
			}
		}
		continue;
	}
	
	std::cout << std::endl << "There are " << codeCount << " code characters." << std::endl;
	std::cout << "There are " << encodedCount << " encoded characters." << std::endl;
	std::cout << "There are " << literalCount << " literal characters." << std::endl;
	std::cout << "The difference between code & literal is " << codeCount-literalCount << std::endl;
	std::cout << "The difference between encoded & code is " << encodedCount-codeCount << std::endl << std::endl;
	
	return 0;

}