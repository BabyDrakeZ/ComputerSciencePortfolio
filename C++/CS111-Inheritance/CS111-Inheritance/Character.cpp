



#include "Character.h"

Character::Character() {
	name = "Undefined";
	health = 0;
	std::cout << "Don't use this one\n";
}
Character::Character(std::string _name) {
	name = _name;
	health = 10;
}
Character::Character(std::string _name, Point initialPosition) {
	name = _name;
	health = 10;
	this->x = initialPosition.getX();
	this->y = initialPosition.getY();
}


void Character::printCharacter() {
	std::cout << "health: " << health << ", name: " << name << " ";
	Point::print();
}

Character::~Character() {
	std::cout << "I'm here!";
	//this->Point::setNext(NULL);
}

//Friends

bool equal(Point a, Point b) {
	return a.x == b.x && a.y == b.y;
}