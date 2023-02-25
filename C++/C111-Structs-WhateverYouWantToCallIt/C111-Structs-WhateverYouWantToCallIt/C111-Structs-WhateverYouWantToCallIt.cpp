// C111-Structs-WhateverYouWantToCallIt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Point {
    double x;
    double y;
    string name;

    //-- Constructors
    Point() {
        x = 0;
        y = 0;
        name = to_string(x + y);
        //cout << "Default constructor\n";
    }
    Point(double _x, double _y, string _name) {
        x = _x;
        y = _y;
        name = _name;
        //cout << "Specific constructor\n";
    }
    // -- Functions
    void add(Point p) {
        x += p.x;
        y += p.y;
    }
    void print() {
        cout << "X: " << x << " Y: " << y << " Name " << name << endl;
    }
};

#define SIZE 10

typedef Point Points[SIZE];
typedef Point Triangle[3];
typedef Point Plane[3];
typedef Point Line[2];

Point add(Point p1, Point p2);

void sortPointsOnX(Points p, const int size); //even better sort Points OnX(Points p, const int size
void swap(Point &p1, Point &p2);

int main()
{
    Point p1(-1, -1, "Point 1");
    Point p2;

    Points points;
    srand(99);
    for (int i = 0; i < SIZE; i++) {
        points[i].x = rand() % 10;
        points[i].y = rand() % 20 + 10;
        points[i].print();
    }

    sortPointsOnX(points, SIZE);

    cout << "After Sort\n";

    for (int i = 0; i < SIZE; i++) {
        points[i].print();
    }

    p2.add(p1);
    p1.print();
    p2.print();
    return 0;
}

Point add(Point p1, Point p2) {
    double x = p1.x + p2.x;
    double y = p1.y + p2.y;
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}


void sortPointsOnX(Points p, const int size) {
    int minIndex = 0;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i; j < size; j++) {
            if (p[j].x < p[minIndex].x) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(p[minIndex], p[i]);
        }
    }
}
void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}