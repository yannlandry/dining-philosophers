#include "fork.hpp"


Fork::Fork(): holder(nullptr) {}

bool Fork::isAvailable() {
	return holder == nullptr;
}

bool Fork::belongsTo(Philosopher* p) {
	return holder == p;
}

bool Fork::pick(Philosopher* p) {
	if(isAvailable()) {
		holder = p;
		return true;
	}
	else
		return false;
}

void Fork::drop() {
	holder = nullptr;
}