#pragma once
#include <string>
#include <iostream>




struct Boat {
	std::string boatOwnerName;
	std::string boatName;
	double boatSize;
	Boat* next;
	//-- Constructor
	Boat();
	Boat(std::string _owner, std::string _name, double _size);
	//-- public functions
	void print();
};
typedef Boat* BoatStructPtr;