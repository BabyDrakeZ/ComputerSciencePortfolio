#pragma once

#include <iostream>
#include <string>
#include <vector>

template <class T>
class StackTV {
private:
	std::vector<T> stack;
	int topOfStack;
public:
	StackTV();
	T Pop();
	void Push(T _item);
	bool empty();
};