#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
	distanceFromOrigin = 0;
	next = NULL;
}
Point::Point(float _x, float _y) {
	x = _x;
	y = _y;
	distanceFromOrigin = calculateDistance(Point());
	next = NULL;
}
void Point::setX(float _x) {
	x = _x;
	distanceFromOrigin = calculateDistance(Point());
}
void Point::setY(float _y) {
	y = _y;
	distanceFromOrigin = calculateDistance(Point());
}
float Point::calculateDistance(Point p) {
	float d = pow(x - p.x, 2) + pow(y - p.y, 2);
	return sqrt(d);
}

float Point::getX() {
	return x;
}
float Point::getY() {
	return y;
}
float Point::distanceFromPoint(Point p) {
	float f = calculateDistance(p);
	return f;
}
void Point::print() {
	std::cout << "X " << x << " Y " << y << " Distance " << distanceFromOrigin << std::endl;
}
void Point::translate(float deltaX, float deltaY) {
	x += deltaX;
	y += deltaY;
	distanceFromOrigin = calculateDistance(Point(0,0));
}

void Point::setNext(Point* &_p) {
	next = _p;
}
Point* Point::getNext() {
	return next;
}