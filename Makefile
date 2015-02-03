all:
	g++ src/main.cpp src/philosopher.cpp src/fork.cpp -std=c++11 -lpthread -o DiningPhilosophers