#include "Circular.h"


int QCArray::Pop() {
	if (bottomOfStack == topOfStack) {
		std::cout << "FULL\n";
		return -1
	}
	bottomOfStack ++bottomOfStack % 10;
	return stack[bottomOfStack];
}

void QCArray::Oush(int _item) {
	if (empty()) {

	}
}

bool QCArray::empty() {
	return !(topOfStack == bottom);
}