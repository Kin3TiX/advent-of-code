#include "PRESENT.h"

PRESENT::PRESENT(uint16_t len, uint16_t wid, uint16_t hgt) { 

	length = len;
	width = wid;
	height = hgt;

}

PRESENT::~PRESENT() { }

uint32_t PRESENT::getPaperSize() {

	return getSmallSide() + getSurfaceArea();

}

uint32_t PRESENT::getRibbonLength() {

	return getSmallPerimeter() + getVolume();

}

PRESENT & PRESENT::operator=(const PRESENT & rhs) {
	
	length = rhs.length;
	width = rhs.width;
	height = rhs.height;

	return *this;

}

uint16_t PRESENT::getSmallSide() {

	list<uint16_t> dimensions;
	dimensions.push_front(length*width);
	dimensions.push_front(length*height);
	dimensions.push_front(width*height);
	dimensions.sort();

	return dimensions.front();

}

uint32_t PRESENT::getSurfaceArea() {

	return (2 * length*width) + (2 * width*height) + (2 * height*length);

}

uint32_t PRESENT::getVolume() {

	return length*width*height;

}

uint32_t PRESENT::getSmallPerimeter() {

	uint16_t perimeter = 0;
	list<uint16_t> dimensions;
	dimensions.push_front(length);
	dimensions.push_front(height);
	dimensions.push_front(width);
	dimensions.sort();

	perimeter = 2*dimensions.front();
	dimensions.pop_front();
	perimeter += 2*dimensions.front();

	return perimeter;

}
