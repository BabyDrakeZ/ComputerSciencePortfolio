// CS111_Pointers_F21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point.h"

typedef Point* PointPtr;


void headInsert(PointPtr& head, PointPtr& newItem);
void printList(PointPtr& head);
void deleteList(PointPtr& head);
//Postcondition: Return ptr tp target's Point or NULL
PointPtr searchList(PointPtr& head, double target);
void searchListAndInsert(PointPtr& head, double target, PointPtr newItem);
void tailInsert(PointPtr& head, PointPtr& tail, PointPtr newItem);
void tailInsert(PointPtr& head, PointPtr newItem);


int main(void)
{
	PointPtr head = NULL;
	PointPtr tail = NULL;
	
	double start = time(0);

	int listLength = 50000;
	for (int i = 0; i < listLength; i++){
		PointPtr p = new Point(i, i, "New Item");
		tailInsert(head, tail, p);
		
		p = NULL;
	}
	double end = time(0);
	double elapsed = end - start;
	//printList(head);
	std::cout << "Ellapsed time " << elapsed << std::endl;
	//printList(head);
	//double target;
	//cout << "\nsearch for something: ";
	//cin >> target;
	//PointPtr newHead = NULL;
	//PointPtr temp = searchList(head, target);
	//if (temp != NULL) {
	//	std::cout << "Found it!\n";
	//} else {
	//	std::cout << "Not Found!\n";
	//}
	//PointPtr nt = new Point(10, 10, "TEST");
	//searchListAndInsert(newHead, target, nt);
	//printList(newHead);
	
	////deleteList(head);
	//printList(head);
	return 0;
}

void headInsert(PointPtr& head, PointPtr& newItem) {
	newItem->next = head;
	head = newItem;
	newItem = NULL;
}
void tailInsert(PointPtr& head, PointPtr& tail, PointPtr newItem) {
	if (head == NULL) {//empty list
		headInsert(head, newItem);
		tail = head;
		return;
	}
	tail->next = newItem;
	tail = newItem;
	newItem = NULL;
	return;
}
void tailInsert(PointPtr& head, PointPtr newItem) {
	PointPtr itr = head;
	if (head == NULL) {//empty list
		headInsert(head, newItem);
		return;
	}
	for (; itr->next != NULL; itr = itr->next);
	itr->next = newItem;
	itr = newItem;
	newItem = NULL;
	return;
}
void printList(PointPtr& head) {
	if (head == NULL)
		std::cout << "\nEmpty lis\n";
	for (PointPtr itr=head; itr != NULL; itr=itr->next) {
		itr->print();
	}
}

void deleteList(PointPtr& head) {
	PointPtr temp = NULL;
	while(head != NULL) {
		temp = head;
		head = head->next;
		temp->next = NULL; //just to make sure nothing points to next
		temp->print();
		delete temp;
	}
}

PointPtr searchList(PointPtr& head, double target) {
	PointPtr t = head;
	for (; t != NULL && (t->x != target); t=t->next);
	return t;
}
void searchListAndInsert(PointPtr& head, double target, PointPtr newItem) {
	if (head == NULL) {
		headInsert(head, newItem);
		return;
	}
	PointPtr t = head;
	for (; t != NULL; t = t->next) {
		if (t->x == target) {
			newItem->next = t->next;
			t->next = newItem;
			//OR
			// headInsert(t->next, newItem)
			return;
		}

	}
	headInsert(head, newItem);
}

//p->print();
//Point p1(-1, -1, "Negative");
//delete p;
//p = &p1;
//p->print();
//p->name = "Wow! That's cool!!!";
//p1.print();




//int size = 0;
//std::cout << "How big would you like your array? ";
//std::cin >> size;
//int* array = NULL;
//array = new int[size];

//for (int i = 0; i < size; i++) {
//	array[i] = i;
//}
//delete	[] array;



//int* p = NULL; //dynamic allocation;
//p = new int(10);
//p = NULL; // BAD now points to nothing, but integer is still in the program; This is a memory leak. VERY BAD!
//delete p; //deletes the integer, not p;
//p = NULL; //as soon as you delete set the pointer to NULL

//every new must have a matching delete. If you don't you will have memory links and if you have memory links you


//int foo = 1;
//int* p = NULL;
//int* r = NULL;
//p = &foo;
//r = p;
//for (int i = 0; i < 100; i++) {
//	(*p)++;
//}

//std::cout << "Ptr foo " << *p << " Var foo " << foo << std::endl;
////I no longer p, r to point to foo
////we can't delete a pointer
//p = NULL;
//r = NULL;
