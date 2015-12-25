#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include <map>
#include <forward_list>
#include "Guest.h"
#include "Table.h"

int main() {

	std::ifstream input("input.txt");
	std::regex parser("(.+)\\s.+\\s(.+)\\s([0-9]+)\\shappiness\\sunits\\sby\\ssitting\\snext\\sto\\s(.+)\\.");
	std::smatch matches;
	std::string buffer;
	std::map<std::string, Guest*> guests;
	Table table;
	
	while(getline(input, buffer)) {
		
		regex_match(buffer, matches, parser);
		
		int value = 1;
		if(matches[2] == "lose")
			value = -1;
		value *= std::stoi(matches[3]);
		
		std::map<std::string, Guest*>::iterator element = guests.find(matches[1]);
		
		if( element == guests.end() ) {
			Guest* temp = new Guest(matches[1]);
			temp->addPreference(matches[4], value);
			table.addGuest(temp);
			guests.insert( std::pair<std::string, Guest*>(matches[1], temp) );
		} else {
			(*element).second->addPreference(matches[4], value);
		}
		
	}
	
	Guest* temp = new Guest("Owen");
	for(std::map<std::string, Guest*>::iterator i = guests.begin(); i != guests.end(); ++i) {
		temp->addPreference( (*i).first, 0);
		(*i).second->addPreference( "Owen", 0 );
	}
	guests.insert( std::pair<std::string, Guest*>("Owen", temp) );
	table.addGuest( temp );
	
	std::vector<int> perms(guests.size());
	std::iota(perms.begin(), perms.end(), 0);
	int optimal = 0;
	do {
		
		int score = 0;
		if(table.setOrder(perms)) {
			table.updateNeighbors();
			score = table.getScore();
			if(score > optimal)
				optimal = score;
		} else {
			return -1;
		}
		
	} while(next_permutation(perms.begin(), perms.end()));
	
	std::cout << "The optimal score is: " << optimal << std::endl;
	
}