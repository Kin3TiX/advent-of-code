#include "Reindeer.h"

Reindeer::Reindeer(std::string n = "", int s = 0, int f = 0, int r = 0)
	: name(n)
	, speed(s)
	, flyingTime(f)
	, restingTime(r)  
{
	
	quit = false;
	run = false;
	myThread = new std::thread(&Reindeer::core, this);
	
}

Reindeer::~Reindeer() {
	
	if(myThread) {
		quit = true;
		myThread->join();
		delete(myThread);
	}
	
}

void Reindeer::start(int t) {
	
	time = t;
	distance = 0;
	run = true;
	
}

void Reindeer::stop() {
	
	run = false;
	
}

bool Reindeer::getState() {
	return run;
}

int Reindeer::getDistance() {

	return distance;
	
}

std::string Reindeer::getName() {
	
	return name;

}

void Reindeer::setSync(std::atomic<int>* t) {
	
	threads = t;
	
}

void Reindeer::setGo() {
	go = true;
}

void Reindeer::core() {
	
	int currentSecond = 0;
	int totalSeconds = 0;
	while(!quit) {
		
		if(run) {
				
			if(currentSecond < flyingTime) {
				distance += speed;
				currentSecond++;
				totalSeconds++;
			} else if (currentSecond < flyingTime+restingTime-1) {
				currentSecond++;
				totalSeconds++;
			} else if (currentSecond == flyingTime+restingTime-1) {
				currentSecond = 0;
				totalSeconds++;
			}
			
			(*threads)++;
			if(totalSeconds == time) {
				run = false;
			} else {
				while(!go) { std::this_thread::yield(); }
				go = false;
			}
			
		} else {
			
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			
		}
		
	}
	
}