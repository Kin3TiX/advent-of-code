#include <iostream>
#include <string>
#include <map>

bool checkSeries(char * input, int len) {
	
	for(int i = 0; i < len-3; ++i) {
		
		bool next = ( input[i+1] == (input[i]+1) );
		bool after = ( input[i+2] == (input [i+1]+1) );
		
		if(next && after)
			return true;
		
	}
	
	return false;
	
}

bool checkForbidden(char* input, int len) {
	
	for(int i = 0; i < len; ++i) {
		
		switch(input[i]) {
			
			case 'i':
			case 'o':
			case 'l':
				return false;
				
			default:
				break;
				
		}
		
	}
	
	return true;
	
}

bool checkDoubles(char* input, int len) {
	
	std::map<char, int> doubles;
	
	for(int i = 0; i < len-1; ++i) {
		
		if(input[i] == input[i+1]) {
			doubles.insert(std::pair<char, int>(input[i], i));
		}
	
	}
	
	if(doubles.size() > 1) {
		
		return true;
		
	}
	
	return false;
	
}

void updateCharacter(char* input, int index) {
	
	if(input[index] == 'z') {
		input[index] = 'a';
		if(index)
			updateCharacter(input, index-1);
	} else {
		input[index]++;
	}
	
}

int main() {

	int len = 8;
	char seed[len+1] = "hxbxxyzz";
	updateCharacter(seed, len-1);
	
	while( !( checkSeries(seed, len) && checkForbidden(seed, len) && checkDoubles(seed, len) ) ) {
		updateCharacter(seed, len-1);
	}
	
	std::cout << "The next possible password is " << std::string(seed) << std::endl;

	return 0;

}