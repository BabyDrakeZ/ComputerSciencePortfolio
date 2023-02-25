
#include <iostream>
#include "linkedList.h"


T::T() {
	f = -1;
	next = NULL;
}
T::T(int f) {
	this->f = f;
	next = NULL;
}

int T::getF() {
	return f;
}
void T::setF(int f) {
	this->f = f;
}

tPtr T::getNext() {
	return next;
}
void T::setNext(T* _next) {
	next = _next;
}

void T::print() {
	std::cout << "Value f: " << f << "\n";
}

T::~T() {
	next = NULL;
}