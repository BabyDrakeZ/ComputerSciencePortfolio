#include "ContainerT.h"
ContainerT::ContainerT() {
	name = "~Unassigned";
}

ContainerT::ContainerT(std::string _name) {
	name = _name;
}

void ContainerT::print() {
	std::cout << name << std::endl;
}