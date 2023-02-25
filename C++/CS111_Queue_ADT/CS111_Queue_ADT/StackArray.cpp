
#include "StackArray.h"

StackArray::StackArray() {
	//count = 0;
	topOfStack = 0;
	stack.resize(10);
	for (int i = 0; i < 10; stack[i++] = NULL);
}
cPtr StackArray::Pop() {
	cPtr t = NULL;
	try {
		t = stack.at(--topOfStack);
	}
	catch (std::out_of_range& e) {
		std::cout << "Stack empty\n";
		topOfStack++;
	}
	return t;
}
void StackArray::Push(cPtr _item) {
	try {
		stack.at(topOfStack++) = _item;
	}
	catch (std::out_of_range& e) {
		std::cout << "Stack full\n";
		topOfStack--;
	}
}