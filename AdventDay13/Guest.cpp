#include "Guest.h"

Guest::Guest(std::string n = "") : name(n) {}

Guest::~Guest() {}

void Guest::setLneighbor(Guest* l) {
	leftNeighbor = l;
}

void Guest::setRneighbor(Guest* r) {
	rightNeighbor = r;
}

std::string Guest::getName() {
	return name;
}

int Guest::getHappiness() {
	return preferences[leftNeighbor->getName()] + preferences[rightNeighbor->getName()];
}

void Guest::addPreference(std::string n, int h) {
	preferences.insert(std::pair<std::string, int>(n,h));
}