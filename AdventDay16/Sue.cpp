#include "Sue.h"

Sue::Sue(int i = 0) : id(i), score(0) { }

Sue::~Sue() {}

int Sue::getId() {
	return id;
}

void Sue::setTraits(std::vector<int> t) {
	traits = t;
}

std::vector<int> Sue::getTraits() {
	return traits;
}

void Sue::incScore(int v) {
	score = score+v;
}

void Sue::decScore(int v) {
	score = score-v;
}

int Sue::getScore() {
	return score;
}

bool Sue::operator<(const Sue& other) const {
	return score < other.score;
}

bool Sue::operator>(const Sue& other) const {
	return score > other.score;
	
}

