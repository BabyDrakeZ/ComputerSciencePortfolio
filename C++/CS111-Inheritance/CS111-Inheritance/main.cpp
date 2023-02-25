

#include <iostream>
#include "Point.h"
#include "Character.h"

//void printTriangle(Point tri[]);


//List functions
void headInsert(PointPtr& head, PointPtr& newItem);
void printTriangle(PointPtr& h);
void translateTriangle(PointPtr& head, float deltaX, float deltaY);


int main(void) {
	Point a(1, 1);
	Point b(3, 3);
	Point ab = a + b;
	std::cout << "ab: " << ab << std::endl;
	if (a == b) {
		std::cout << "equal\n";
	} else {
		std::cout << "not equal\n";
	}
	std::cout << a;



	//Character character("Foo");
	//character.printCharacter();
	//Character* c;
	//c = new Character("Destryctor");
	//delete c;
	//c = NULL;
	return 0;
}

//void printTriangle(Point tri[]) {
//	for (int i = 0; i < 3; i++) {
//		tri[i].print();
//	}
//}


//bool equal(Point a, Point b) {
//	return a.x == b.x && a.y == b.y;
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