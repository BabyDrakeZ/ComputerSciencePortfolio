#include "boat.h"

Boat::Boat() {
	boatOwnerName = "~Not-Assigned!";
	boatName = "~Not-Assigned!";
	boatSize = -1;
	next = NULL;
}
Boat::Boat(std::string _owner, std::string _name, double _size) {
	next = NULL;
	boatOwnerName = _owner;
	boatName = _name;
	boatSize = _size;
}
void Boat::print() {
	std::cout << "Boat " << boatName << " owned by " << boatOwnerName << " size " << boatSize << "\n";
}