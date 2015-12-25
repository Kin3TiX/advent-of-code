#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <set>
#include <stack>

std::ifstream myFile("input.txt");

bool isNumber(char c) {
	
	return (c >= '0') && (c <= '9');
	
}

bool isSign(char c) {
	
	return (c == '-') && std::isdigit(myFile.peek());
	
}

long int process() {
	
	char c = '\0';
	long int total = 0;
	int count = 0;
	int level = 0;
	std::string buffer = "";
	std::string marker = ":\"red";
	bool watching = false;
	bool counting = false;
	
	while(myFile.get(c)) {
		
		if(c == '{')
			total += process();
		
		if(counting) {
			
			if(isNumber(c)) {
				buffer.push_back(c);
			} else {
				total += std::stoi(buffer);
				buffer.clear();
				counting = false;
			}
			
		} else if(watching) {
			
			buffer.push_back(c);
			if(buffer[count] != marker[count]) {
				buffer.clear();
				watching = false;
				count = 0;
			} else {
				count++;
			}
			
			if(count == 4) {
				
				if(buffer == marker) {
					
				while(myFile.get(c)) {
					if(c == '{') {
						level++;
					} else if(c == '}') {
						if(level == 0)
							break;
						else
							level--;
					}
				}
				
				return 0;
				
				} else {
					buffer.clear();
					watching = false;
					count = 0;
				}
				
			}
			
		} else {
			
			if( isNumber(c) || isSign(c) ) {
				buffer.push_back(c);
				if(isNumber(myFile.peek()))
					counting = true;
				else {
					total += std::stoi(buffer);
					buffer.clear();
				}
			} else if (c == ':') {
				if(myFile.peek() == '\"') {
					buffer.push_back(c);
					watching = true;
				}
			}
			
		}
		
		if(c == '}')
			return total;
		
	}
	
	return total;
	
}

int main() {
	
	std::cout << "The sum of the numbers is " <<  process() << std::endl;
	
	return 0;
	
}