#pragma once

#include <iostream>
#include <string>

template <class T>
class StackT {
private:
	struct S {
		T item;
		S* next;
		S(T _item, S* _next) {
			item = _item;
			next = _next;
		}
	};
	S* head;
	int count;
public:
	StackT();
	T Pop();
	void Push(T _item);
	bool empty();
};