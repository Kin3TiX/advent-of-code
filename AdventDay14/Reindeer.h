#ifndef REINDEER_H
#define REINDEER_H

#include <thread>
#include <string>
#include <chrono>
#include <atomic>

class Reindeer {
	
public:
	
	Reindeer(std::string, int, int, int);
	~Reindeer();
	
	void start(int);
	void stop();
	bool getState();
	int getDistance();
	std::string getName();
	void setSync(std::atomic<int>*);
	void setGo();
	
private:
	
	std::string name;
	int speed;
	int flyingTime;
	int restingTime;
	int distance;
	int time;
	bool run;
	bool quit;
	std::thread* myThread;
	std::atomic<int>* threads;
	bool go;
	
	void core();
	
};

#endif