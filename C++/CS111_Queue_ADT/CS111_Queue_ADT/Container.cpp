

#include "Container.h"
Container::Container() {
	name = "~Unassigned";
	next = NULL;
}

Container::Container(std::string _name) {
	name = _name;
	next = NULL;
}

void Container::print() {
	std::cout << name;
}