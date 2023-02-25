#pragma once

#include <stdio.h>
#include <iostream>
#include <string>

#include "Container.h"

#include <vector> //HOMEWORK ASSIGNMENT

class StackArray {
private:
	//cPtr stack[10];
	std::vector<cPtr> stack;
	//int count;
	int topOfStack = 0;
public:
	//implement constuctor
	StackArray();
	cPtr Pop();
	void Push(cPtr _item);
	//stack.empty()
};