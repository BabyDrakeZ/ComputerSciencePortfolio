#pragma once
#include <string>
#include <iostream>




class Boat {
private:
	std::string owner;
	std::string name;
	double size;
	Boat* next;
public:
	//-- Constructors
	Boat();
	Boat(std::string _owner, std::string _name, double _size);
	//-- Public Functions
	void print();
	std::string getBoatOwnerName();
	double getBoatSize();
	Boat* getNext();
	void setNext(Boat* boatPtr);
	//-- Deconstructor
	~Boat();
};
typedef Boat* BoatPtr;