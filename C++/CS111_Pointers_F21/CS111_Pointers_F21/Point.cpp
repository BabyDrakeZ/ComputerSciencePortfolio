
#include "Point.h"

Point::Point() {
	y = 0;
	y = 0;
	name = "foo";
	next = NULL;
}

Point::Point(double _x, double _y, string _name) {
	x = _x;
	y = _y;
	name = _name;
	next = NULL;
}

// -- Functions
void Point::add(Point p) {
	x += p.x;
	y += p.y;
}
void Point::print() {
	std::cout << "X " << x << " Y " << y << " Name " << name << std::endl;
}