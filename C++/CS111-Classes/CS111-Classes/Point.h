#pragma once


#define Point_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

class Point {
private:
	float x;
	float y;
	float distanceFromOrigin;
	float calculateDistance(Point p);
	Point* next;
public:
	Point();
	Point(float _x, float _y);
	void setX(float _x);
	void setY(float _y);
	float getX();
	float getY();
	//Pointer setter/getter;
	void setNext(Point* &_p);
	Point* getNext();
	float distanceFromPoint(Point p);
	void print();
	void translate(float deltaX, float deltaY);
};

typedef Point* PointPtr;