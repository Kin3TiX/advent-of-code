#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

struct Ingredient {
	
	std::string name;
	int capacity;
	int durability;
	int texture;
	int flavor;
	int calories;
	
};

class Recipe {
	
public:
	
	void addIngredient(Ingredient);
	void setRatios(std::vector<int>);
	int getScore();
	int getCalorieScore();
	
private:
	
	std::vector<Ingredient> ingredients;
	std::vector<int> ratios;
	
};

#endif