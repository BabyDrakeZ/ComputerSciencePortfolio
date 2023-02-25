#pragma once



class T {
private:
	int f;
	T* next;
public:
	T();
	T(int f);
	int getF();
	void setF(int f);
	T* getNext();
	void setNext(T* _next);
	void print();
	~T();
	//if you have time implement an << operator.
};

typedef T* tPtr;