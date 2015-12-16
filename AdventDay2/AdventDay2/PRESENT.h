#pragma once
#include "Main.h"

class PRESENT {

public:

	PRESENT(uint16_t len = 1, 
			uint16_t wid = 1, 
			uint16_t hgt = 1);
	
	~PRESENT();

	uint32_t getPaperSize();
	uint32_t getRibbonLength();
	PRESENT& operator=(const PRESENT&);

private:

	uint16_t length;
	uint16_t width;
	uint16_t height;

	uint16_t getSmallSide();
	uint32_t getSurfaceArea();
	uint32_t getVolume();
	uint32_t getSmallPerimeter();

};

