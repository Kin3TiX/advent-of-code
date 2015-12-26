#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <atomic>
#include "Reindeer.h"

int main() {
	
	std::regex parser("(.+)\\s.+fly\\s(.+)\\s.+for\\s(.+)\\ss.+for\\s(.+)\\s.+");
	std::smatch matches;
	std::string buffer;
	std::ifstream input("input.txt");
	std::vector<Reindeer*> deer;
	std::vector<int> distances;
	std::vector<int> points;
	std::atomic<int> threads(0);
	int time = 2503;
	
	while(getline(input, buffer)) {
		
		regex_match(buffer, matches, parser);
		Reindeer* next = new Reindeer(matches[1], std::stoi(matches[2]), std::stoi(matches[3]), std::stoi(matches[4]));
		next->setSync(&threads);
		next->start(time);
		deer.push_back(next);
		
	}
	
	distances.resize(deer.size());
	points.resize(deer.size());
	std::fill(points.begin(), points.end(), 0);
	
	while(true) {
		
		while(threads < deer.size()) { std::this_thread::yield(); }
		threads = 0;
		
		int count = 0;
		for( int i = 0; i < deer.size(); ++i ) {
			distances[i] = deer[i]->getDistance();
			if( deer[i]->getState() )
				count++;
		}
		
		int score = *std::max_element(distances.begin(), distances.end());
		for(int i = 0; i < distances.size(); ++i) {
			if(distances[i] == score)
				points[i] += 1;
		}
		
		if(count == 0) {
			
			break;
			
		} else {
			
			for( auto i: deer )
				i->setGo();
			
		}
		
	}
	
	int index = std::max_element(distances.begin(), distances.end()) - distances.begin();
	Reindeer* winner = deer[index];
	index = std::max_element(points.begin(), points.end()) - points.begin();
	Reindeer* winner2 = deer[index];
	
	std::cout << winner->getName() << " traveled the longest distance of " << winner->getDistance() << std::endl;
	std::cout << winner2->getName() << " won the most points of " << points[index] << std::endl;
	
}