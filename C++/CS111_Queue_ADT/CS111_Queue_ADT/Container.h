#pragma once

#include <stdio.h>
#include <string>
#include <iostream>


class Container {
private:
	std::string name;
	Container* next;
public:
	Container();
	Container(std::string _name);
	void print();
	Container* getNext();
	void setNext(Container* _next);
};

typedef Container* cPtr;