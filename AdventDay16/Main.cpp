#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <functional>
#include "Sue.h"

int main() {

	std::ifstream input("input.txt");	
	std::string expressionHead = ".*";
	std::string expressionTail = ":\\s([0-9]+).*";
	std::string categories[] = {"children","cats","samoyeds","pomeranians","akitas","vizslas","goldfish","trees","cars","perfumes"};
	int targets[] = {3,7,2,3,0,0,5,3,2,1};
	std::smatch matches;
	std::string buffer;
	std::regex parser;
	std::vector<Sue> myAunts;
	int sueCount = 1;
	
	while(getline(input, buffer)) {
		
		std::vector<int> traits;
		
		for( auto i : categories ) {
			
			parser.assign(expressionHead + i + expressionTail);
			regex_match(buffer, matches, parser);
			
			if(matches.size())
				traits.push_back(std::stoi(matches[1]));
			else
				traits.push_back(-1);
			
		}
		
		Sue thisSue(sueCount);
		thisSue.setTraits(traits);
		myAunts.push_back(thisSue);
		++sueCount;
		
	}
	
	for( size_t i = 0; i < (sizeof(targets)/sizeof(int)); ++i ) {
		
		for( auto& sue : myAunts ) {
			
			std::vector<int> temp = sue.getTraits();
			
			if(targets[i]) {
				if( temp[i] != -1 ) {
					sue.incScore(1);
				}
			} else {
				if( temp[i] != -1 )
					sue.decScore(1);
			}
			
			if( i == 1 || i == 7 ) {
				
				if( temp[i] != -1 )
					if( temp[i] > targets[i] )
						sue.incScore(1);
				
			} else if ( i == 3 || i == 6 ) {
				
				if( temp[i] != -1 )
					if( temp[i] < targets[i] )
						sue.incScore(1);
				
			} else {
				
				if( temp[i] != -1 )
					if( temp[i] == targets[i] )
							sue.incScore(1);
					
			}
			
		}
		
	}
	
	std::sort(myAunts.begin(), myAunts.end(), std::greater<Sue>());
	
	std::cout << "Will the real Aunt Sue please stand up? " << myAunts[0].getId() << std::endl;
	
}