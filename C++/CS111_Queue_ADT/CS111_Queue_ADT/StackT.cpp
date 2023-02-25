

#include "StackT.h"

template <class T>
StackT<T>::StackT() {
	count = 0;
	head = NULL;
}

template <class T>
T StackT<T>::Pop() {
	//if (head == NULL) {
	//	std::cout << "Stack Empty!";
	//	T t;		// is a BAD solution because it assumes there's a constructor for T
	//	return t;
	//}
	S* temp = head;
	head = temp->next;
	temp->next = NULL;
	return temp->item;
}

template <class T>
void StackT<T>::Push(T _item) {
	count++;
	S* temp = new S(_item, head);
	head = temp;
}

template <class T>
bool StackT<T>::empty() {
	return  !count;
}