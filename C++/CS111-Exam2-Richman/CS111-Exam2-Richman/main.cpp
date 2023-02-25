
#include <iostream>
#include "linkedList.h"

#define EMPTY -1


//prints the entire list, each item on a line
void printList(tPtr &h);

//returns min of all items on list; -1 if list is empty
int minOfList(tPtr& h);

//item is inserted in list that has head h
void headInsert(tPtr& h, tPtr& item);

//removes 1st item from list and returns a pointer to it.
// Returned item's next = NULL. Head points to the item after the popped item, if it exists.
//if list is empty, return NULL;
tPtr pop(tPtr& h);


int main(void) {
	srand(time(0));
	tPtr head = NULL;
	for (int i = 0; i < 30; i++) {
		tPtr temp = new T(rand() % 30);
		headInsert(head, temp);
		temp = NULL;
	}
	//forgot to print minIfList
	printList(head);
	tPtr popped = pop(head);
	std::cout << "popped: ";
	popped->print();
	delete(popped);
	printList(head);
	return 0;
}


void printList(tPtr &h) {
	//Error:
	if (h == NULL)
		std::cout << "Empty list, nothing to print \n";
	//------
	for (tPtr i = h; i != NULL; i=i->getNext()){
		i->print();
	}
}


void headInsert(tPtr& h, tPtr &item) {
	item->setNext(h);
	h = item; //--ERROR used ->setNext() instead of assignment for h
	//Error forgot:
	item = NULL;
}


int minOfList(tPtr& h) {
	if (h == NULL) {
		return EMPTY;
	}
	int smallest = INT_MAX;
	for (tPtr i = h; i != NULL; i = i->getNext()) {
		if (i->getF() < smallest)
			smallest = i->getF();
	}
}

tPtr pop(tPtr& h) {
	if (h == NULL) return NULL;
	tPtr temp = h;
	h = h->getNext();
	temp->setNext(NULL);
	return temp;
}