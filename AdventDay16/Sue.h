#ifndef SUE_H
#define SUE_H

#include <string>
#include <vector>

class Sue {
	
public:
	
	Sue(int);
	~Sue();
	
	int getId();
	void setTraits(std::vector<int>);
	std::vector<int> getTraits();
	void incScore(int);
	void decScore(int);
	int getScore();
	bool operator<(const Sue&) const;
	bool operator>(const Sue&) const;
	
private:
	
	int id;
	int score;
	std::vector<int> traits;

};

#endif