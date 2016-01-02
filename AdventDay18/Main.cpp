#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::ifstream input("input.txt");
	std::string buffer;
	std::vector<std::vector<bool>> current;
	std::vector<std::vector<bool>> next;
	size_t iterations = 100;
	
	int row = 0;
	while(getline(input, buffer)) {
		
		current.push_back( std::vector<bool>() );
		
		for(std::string::iterator i = buffer.begin(); i!=buffer.end(); ++i) {
			
			if( (*i) == '#' )
				current[row].push_back(true);
			else
				current[row].push_back(false);
			
		}
		
		++row;
		
	}
	
	current[0][0] = true;
	current[0][current[0].size()-1] = true;
	current[current.size()-1][0] = true;
	current[current.size()-1][current[current.size()-1].size()-1] = true;
	
	next.resize(current.size());
	for(size_t i = 0; i < current.size(); ++i)
		next[i].resize(current[i].size());
	
	for(size_t n = 0; n < iterations; ++n) {
		
		for(int y = 0; y < current.size(); ++y) {
			
			for(int x = 0; x < current[y].size(); ++x) {
				
				std::vector<bool> neighbors;
				
				bool up = (y-1) >= 0;
				bool down = (y+1) < current.size();
				bool left = (x-1) >= 0;
				bool right = (x+1) < current[y].size();
				
				if(up) {
					neighbors.push_back(current[y-1][x]);
					if(left)
						neighbors.push_back(current[y-1][x-1]);
					if(right)
						neighbors.push_back(current[y-1][x+1]);
				}
				if(down) {
					neighbors.push_back(current[y+1][x]);
					if(left)
						neighbors.push_back(current[y+1][x-1]);
					if(right)
						neighbors.push_back(current[y+1][x+1]);
				}
				if(left) {
					neighbors.push_back(current[y][x-1]);
				}
				if(right) {
					neighbors.push_back(current[y][x+1]);
				}
				
				int onCount = 0;
				int offCount = 0;
				for(std::vector<bool>::iterator i = neighbors.begin(); i!=neighbors.end(); ++i) {
					if(*i)
						++onCount;
					else
						++offCount;
				}
				
				if(current[y][x]) {
					
					if(onCount == 2 || onCount == 3) {
						next[y][x] = true;
					} else {
						next[y][x] = false;
					}
					
				} else {
					
					if(onCount == 3) {
						next[y][x] = true;
					} else {
						next[y][x] = false;
					}
					
				}
				
				
			}
			
		}
		
		current = next;
		next.clear();
		next.resize(current.size());
		for(size_t i = 0; i < current.size(); ++i)
			next[i].resize(current[i].size());
			
		current[0][0] = true;
		current[0][current[0].size()-1] = true;
		current[current.size()-1][0] = true;
		current[current.size()-1][current[current.size()-1].size()-1] = true;
		
	}
	
	int count;
	for(size_t i = 0; i < current.size(); ++i)
		for(size_t j = 0; j < current[i].size(); ++j)
			if(current[i][j])
				++count;
	
	std::cout << "There are " << count << " lights on" << std::endl;
	
}