#include "Recipe.h"
#include <cassert>

void Recipe::addIngredient(Ingredient n) {
	ingredients.push_back(n);
}

void Recipe::setRatios(std::vector<int> r) {
	ratios = r;
}

int Recipe::getScore() {
	
	assert(ingredients.size() == ratios.size());
	
	int capacity = 0;
	int durability = 0;
	int texture = 0;
	int flavor = 0;
	
	for(std::vector<Ingredient>::iterator i = ingredients.begin(); i!=ingredients.end(); ++i) {
		int position = i - ingredients.begin();
		capacity+= (*i).capacity * ratios[position];
		durability+= (*i).durability * ratios[position];
		texture+= (*i).texture * ratios[position];
		flavor+= (*i).flavor * ratios[position];
	}
	
	if(capacity < 0)
		capacity = 0;
	if(durability < 0)
		durability = 0;
	if(texture < 0)
		texture = 0;
	if(flavor < 0)
		flavor = 0;
	
	return capacity*durability*texture*flavor;
	
}

int Recipe::getCalorieScore() {
	
	assert(ingredients.size() == ratios.size());
	
	int calories = 0;
	
	for(std::vector<Ingredient>::iterator i = ingredients.begin(); i!=ingredients.end(); ++i) {
		int position = i - ingredients.begin();
		calories+= (*i).calories * ratios[position];
	}
	
	if(calories < 0)
		calories = 0;
	
	return calories;
	
}