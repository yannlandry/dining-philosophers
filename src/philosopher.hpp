#ifndef PHILOSOPHER_HPP
#define PHILOSOPHER_HPP

#include <string>
#include "fork.hpp"
class Fork;


class Philosopher {

private:
	Fork* leftFork;
	Fork* rightFork;
	std::string name;

public:
	Philosopher(std::string);

	void setLeftFork(Fork*);
	void setRightFork(Fork*);

	void philosophize();
	void think();
	void eat();

};


#endif