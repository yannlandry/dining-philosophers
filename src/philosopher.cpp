#include "philosopher.hpp"
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>


Philosopher::Philosopher(std::string n): name(n), leftFork(nullptr), rightFork(nullptr) {}

void Philosopher::setLeftFork(Fork* f) {
	leftFork = f;
}

void Philosopher::setRightFork(Fork* f) {
	rightFork = f;
}

void Philosopher::philosophize() {
	std::stringstream str;
	str << "Init " << name << std::endl;
	std::cout << str.str();

	// offset everyone
	think();

	// loop this shit
	while(1) {
		
		// if forks are available, pick em
		if(leftFork->isAvailable() && rightFork->isAvailable()) {
			leftFork->pick(this);
			rightFork->pick(this);

			// are we having the forks?
			if(leftFork->belongsTo(this) && rightFork->belongsTo(this)) {
				eat();
				
				leftFork->drop();
				rightFork->drop();

				think();
			}

			// oops, try again
			else {
				leftFork->drop();
				rightFork->drop();
			}
		}

	}
	// endloop
}

void Philosopher::think() {
	// dude got to think a bit, 1-4 seconds
	std::stringstream str;
	str << name << " thinks." << std::endl;
	std::cout << str.str();
	std::this_thread::sleep_for(std::chrono::seconds(rand() % 4 + 1));
}

void Philosopher::eat() {
	// eat 2 seconds
	std::stringstream str;
	str << name << " eats." << std::endl;
	std::cout << str.str();
	std::this_thread::sleep_for(std::chrono::seconds(2));
}