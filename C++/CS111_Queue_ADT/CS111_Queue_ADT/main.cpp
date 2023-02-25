


#include <iostream>
#include "Container.h"
#include "ContainerT.h"
#include "StackT.h"
#include "StackT.cpp"
#include "StackTV.h"
#include "StackTV.cpp"

int main(void) {
	/*StackT<ContainerT> stackT;
	ContainerT t = ContainerT("Test");
	stackT.Push(t);
	t = stackT.Pop();
	t = stackT.Pop();
	StackT<int> stackInt;
	for (int i = 0; i < 10; i++) {
		stackInt.Push(i);
	}
	std::cout << "Now popping\n";
	for (int i = 0; i < 10; i++) {
		std::cout << stackInt.Pop() << std::endl;
	}*/
	StackTV<ContainerT> stackT;
	ContainerT t = ContainerT("Test");
	stackT.Push(t);
	stackT.Push(t);
	t = stackT.Pop();
	t = stackT.Pop();
	StackTV<int> stackInt;
	for (int i = 0; i < 11; i++) {
		stackInt.Push(i);
	}
	std::cout << "Now popping\n";
	for (int i = 0; i < 16; i++) {
		std::cout << stackInt.Pop() << std::endl;
	}

}