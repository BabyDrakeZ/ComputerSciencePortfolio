#include "StackTV.h"

template <class T>
StackTV<T>::StackTV() {			
	stack.resize(0);
	topOfStack = 0;
}

template <class T>
T StackTV<T>::Pop() {
	T temp;
	try {
		temp = stack.at(--topOfStack);
	}
	catch (std::out_of_range& e) {
		std::cout << "Stack empty!\n";
		topOfStack++;
		T t2;
		return t2;
	}
	return temp;
}

template <class T>
void StackTV<T>::Push(T _item) {
	try {
		stack.at(topOfStack++) = _item;
	}
	catch (std::out_of_range& e) {
		std::cout << "Stack full... resizing +5 \n";
		stack.resize(stack.size() + 5);
		stack.at(topOfStack) = _item;
		//topOfStack--;
		//Push(_item)
	}
}

template <class T>
bool StackTV<T>::empty() {
	return stack.empty();
}