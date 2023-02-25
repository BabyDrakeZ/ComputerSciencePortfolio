#pragma once


class QCArray {
private:
	int queue[10];
	int bottomOfStack;
	int topOfStack;
public:
	int Pop();
	void Push(int _item);
};