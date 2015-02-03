The Dining Philosophers
=======================

_Killing some dudes in a spaghetti dinner._

This is just a very simple implementation of the [dining philosophers problem](http://en.wikipedia.org/wiki/Dining_philosophers_problem), which is used to teach the concepts of multithreaded programming.

This program does not make use of any advanced solution. Instead, each Philosopher spends time thinking (1 to 4 seconds) and eating (2 seconds). Upon completion of the thinking task, a philosopher will try to gain control over the two forks that are adjacent to him. He will drop any fork he holds if control can't be achieved. Maybe that'll work.
