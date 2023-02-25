#pragma once


#include <stdio.h>
#include <iostream>
#include "Point.h"

class Character: public Point {
private:
	std::string name;
	double health;
public:
	Character();
	Character(std::string _name);
	Character(std::string _name, Point initialPosition);
	//Destructor
	~Character();

	void printCharacter();
};