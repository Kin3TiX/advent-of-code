#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

int main() {

	std::ifstream input("input.txt");
	std::string buffer;
	std::vector<int> containers;
	int targetSum = 150;
	
	while(getline(input, buffer)) {
		containers.push_back(stoi(buffer));
	}
	
	int count = 0;
	std::vector<int> sizeCounts;
	for(size_t i = 1; i <= containers.size(); ++i) {
		
		std::vector<bool> select(containers.size());
		std::fill(select.begin(), select.begin()+i, true);
		int sizeCount = 0;
		do {
			
			std::vector<int> choice;
			for(size_t j = 0; j < select.size(); ++j) {
				
				if( select[j] )
					choice.push_back( containers[j] );
				
			}
			
			if( std::accumulate(choice.begin(), choice.end(), 0) == targetSum ) {
				++sizeCount;
				++count;
			}
			
		} while( std::prev_permutation( select.begin(), select.end()) );
		
		sizeCounts.push_back(sizeCount);
		
	}
	
	int min = 0;
	int minCount = -1;
	for(size_t i = 0; i < sizeCounts.size(); ++i) {
		
		if(minCount == -1 && sizeCounts[i] > 0) {
			min = i;
			minCount = sizeCounts[i];
			break;
		}
		
	}
	
	std::cout << "There are " << count << " possible combinations" << std::endl;
	std::cout << "The minimum number of bins is " << min << " with " << minCount << " possibilities" << std::endl;
	
}