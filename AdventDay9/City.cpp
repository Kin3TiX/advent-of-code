#include "City.h"

City::City(std::string n = "") : name(n) {}

City::~City() {}

void City::setNeighbor(City* n) {
	neighbor = n;
}

std::string City::getName() {
	return name;
}

int City::getDistance() {
	return distances[neighbor->getName()];
}

void City::addDistance(std::string n, int h) {
	distances.insert(std::pair<std::string, int>(n,h));
}