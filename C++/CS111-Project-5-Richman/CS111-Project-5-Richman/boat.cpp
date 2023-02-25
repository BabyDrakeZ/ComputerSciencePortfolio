#include "boat.h"

Boat::Boat() {
	owner = "~Not-Assigned!";
	name = "~Not-Assigned!";
	size = -1;
	next = NULL;
}
Boat::Boat(std::string _owner, std::string _name, double _size) {
	next = NULL;
	owner = _owner;
	name = _name;
	size = _size;
}
void Boat::print() {
	std::cout << "Boat " << name << " owned by " << owner << " size " << size << "\n";
}

std::string Boat::getBoatOwnerName() {
	return owner;
}
double Boat::getBoatSize() {
	return size;
}
Boat* Boat::getNext() {
	return next;
}
void Boat::setNext(Boat* boatPtr) {
	next = boatPtr;
}
Boat::~Boat() {
	next = NULL;
	//std::cout << "removing: ";
	//print();
}