#pragma once

#include <stdio.h>
#include <string>
#include <iostream>


class ContainerT {
private:
	std::string name;
public:
	ContainerT();
	ContainerT(std::string _name);
	void print();
};