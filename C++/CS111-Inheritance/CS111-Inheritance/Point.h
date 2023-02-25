#pragma once


#define Point_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

class Point {
private:
	float distanceFromOrigin;
	float calculateDistance(Point p);
	Point* next;
protected:
	float x;
	float y;
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
	friend bool equal(const Point a, const Point b);
	friend bool operator==(const Point a, const Point b);
	friend std::ostream& operator<<(std::ostream & lhs, const Point& p);
	friend Point operator+(const Point p1, const Point p2);
};

typedef Point* PointPtr;