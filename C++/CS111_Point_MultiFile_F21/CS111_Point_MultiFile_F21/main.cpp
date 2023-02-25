//
// main.cpp
// CS111_Point_MultiFile_F21
//
// Created by David, Richman on 10/13/21

#include <iostream>
#include "Point.h"

Point add(Point p1, Point p2);

void sortPointsOnX(Points p, const int size); //even better sort Points OnX(Points p, const int size
void swap(Point& p1, Point& p2);

int main() {
    Point p1(-1, -1, "Point 1");
    Point p2;

    Points points;
    srand(99);
    for (int i = 0; i < 10; i++) {
        points[i].x = rand() % 10;
        points[i].y = rand() % 20 + 10;
        points[i].print();
    }

    sortPointsOnX(points, 10);

    cout << "After Sort\n";

    for (int i = 0; i < 10; i++) {
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
void swap(Point& p1, Point& p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}