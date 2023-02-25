#pragma once
#include <string>
#include <iostream>


using namespace std;

struct Point {
    double x;
    double y;
    string name;

    //-- Constructors
    Point();
    Point(double _x, double _y, string _name);
    // -- Functions
    void add(Point p);
    void print();
};

typedef Point Points[10];
typedef Point Triangle[3];
typedef Point Plane[3];
typedef Point Line[2];
