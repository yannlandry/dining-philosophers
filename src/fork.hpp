#ifndef FORK_HPP
#define FORK_HPP

#include "philosopher.hpp"
class Philosopher;


class Fork {

private:
	Philosopher* holder;

public:
	Fork();

	bool isAvailable();
	bool belongsTo(Philosopher*);
	bool pick(Philosopher*);
	void drop();

};


#endif