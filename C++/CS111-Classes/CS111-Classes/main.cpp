

#include <iostream>
#include "Point.h"

//void printTriangle(Point tri[]);


//List functions
void headInsert(PointPtr& head, PointPtr& newItem);
void printTriangle(PointPtr& h);
void translateTriangle(PointPtr& head, float deltaX, float deltaY);

int main(void) {
	PointPtr triangleHead = NULL;

	for (int i = 0; i < 3; i++) {
		PointPtr t = new Point(i * 2, i * 3);
		headInsert(triangleHead, t);
	}

	printTriangle(triangleHead);
	translateTriangle(triangleHead, 10, -10);
	std::cout << "Post Translation\n";
	printTriangle(triangleHead);
	
	
	
	
	
	//Point triangle[3];
	//for (int i = 0; i < 3; i++) {
	//	triangle[i].setX(i*2);
	//	triangle[i].setY(i*3);
	//}

	//printTriangle(triangle);

	/*Point p(1, 1);
	p.print();
	return 0;*/
}

//void printTriangle(Point tri[]) {
//	for (int i = 0; i < 3; i++) {
//		tri[i].print();
//	}
//}
void headInsert(PointPtr& head, PointPtr& newItem) {
	newItem->setNext(head);
	head = newItem;
	newItem = NULL;
}
void printTriangle(PointPtr& h) {
	for (PointPtr itr = h; itr != NULL; itr=itr->getNext()) {
		itr->print();
	}
}

void translateTriangle(PointPtr& head, float deltaX, float deltaY) {
	for (PointPtr itr = head; itr != NULL; itr=itr->getNext()) {
		itr->translate(deltaX, deltaY);
	}
}