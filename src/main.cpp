#include <iostream>
#include <thread>
#include <chrono>
#include "philosopher.hpp"
#include "fork.hpp"


void philosophize(Philosopher* p) {
	p->philosophize();
}


int main() {
	Philosopher* Plato = new Philosopher("Plato");
	Philosopher* Kant = new Philosopher("Kant");

	Fork* ForkA = new Fork;
	Plato->setLeftFork(ForkA);
	Kant->setRightFork(ForkA);

	Fork* ForkB = new Fork;
	Plato->setRightFork(ForkB);
	Kant->setLeftFork(ForkB);

	std::thread t_Plato(philosophize, Plato);
	std::thread t_Kant(philosophize, Kant);

	t_Plato.join();
	t_Kant.join();

	delete Plato, Kant, ForkA, ForkB;

	return 0;
}