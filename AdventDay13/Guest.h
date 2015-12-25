#ifndef GUEST_H
#define GUEST_H

#include <string>
#include <map>

class Guest {

public:
	
	Guest(std::string);
	~Guest();
	
	void setLneighbor(Guest*);
	void setRneighbor(Guest*);
	std::string getName();
	int getHappiness();
	void addPreference(std::string, int);
	
private:
	
	std::string name;
	Guest* leftNeighbor;
	Guest* rightNeighbor;
	std::map<std::string, int> preferences;

};

#endif