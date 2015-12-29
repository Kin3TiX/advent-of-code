#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
#include "Recipe.h"

void advancePerm(std::vector<int>& array, int choices, int index) {
	
	if(array[index] == choices) {
		
		array[index] = 0;
		if( (index-1) >= 0 )
			advancePerm(array, choices, (index-1) );
		
	} else {
		
		++array[index];
		
	}
	
}

std::vector<std::vector<int>> genRatios(int choices, int dimension, int targetSum) {
	
	std::vector<std::vector<int>> combinations;
	std::vector<int> temp(dimension);
	std::fill(temp.begin(), temp.end(), 0);
	
	do {
		
		advancePerm(temp, choices, temp.size()-1);
		if(std::accumulate(temp.begin(), temp.end(), 0) == targetSum) {
			combinations.push_back(temp);
		}
		
	} while(std::accumulate( temp.begin(), temp.end(), 0 ) < (choices*dimension) );
	
	return combinations;
	
}

int main() {

	std::ifstream input("input.txt");
	std::regex parser("(.+):.+\\s(-?[0-9]+).+\\s(-?[0-9]+).+\\s(-?[0-9]+).+\\s(-?[0-9]+).+\\s(-?[0-9]+)");
	std::smatch matches;
	std::string buffer;
	Recipe myRecipe;
	int ingredientCount = 0;
	
	while(getline(input, buffer)) {
		
		regex_match(buffer, matches, parser);
		
		Ingredient next;
		next.name 		= matches[1];
		next.capacity 	= stoi(matches[2]);
		next.durability 	= stoi(matches[3]);
		next.flavor 		= stoi(matches[4]);
		next.texture 		= stoi(matches[5]);
		next.calories 		= stoi(matches[6]);
		
		myRecipe.addIngredient(next);
		ingredientCount++;
		
	}
	
	std::vector<std::vector<int>> ratios = genRatios(100, ingredientCount, 100);
	int optimal = 0;
	for(std::vector<std::vector<int>>::iterator i = ratios.begin(); i!=ratios.end(); ++i) {
		myRecipe.setRatios(*i);
		int temp = myRecipe.getScore();
		int calories = myRecipe.getCalorieScore();
		if( calories == 500 )
			if(temp > optimal)
				optimal = temp;
	}
	
	std::cout << "The optimal score is: " << optimal << std::endl;
	
}