// Exam1Richman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

#define ARRAY_SIZE 9

typedef int NumArray[ARRAY_SIZE];

//precondition: a is an unititialized array, size is arry size
//postcontition: a is inititalized with a random int in the range [0...1000]
void initArray(NumArray a, const int size);

//precondition: a is an initialized array, size is array size
//postcondition: a is sorted using SELECTION SORT in descending order
void sortArray(NumArray a, const int size);

//precondition:--
//postcondition: the values of first and second are swapped
void swap(int& first, int& second);

//precondition:--
//postcondition: array contents printed to the screen (cout)
void printArray(NumArray a, const int size);

//precondition: a has values, size is array size
//postcondition: array average is returned
int averageArray(NumArray a, const int size);

int main() {
    srand(time(0));
	NumArray numArray;
	initArray(numArray, ARRAY_SIZE);
	printArray(numArray, ARRAY_SIZE);
	sortArray(numArray, ARRAY_SIZE);
	printArray(numArray, ARRAY_SIZE);
	int avg = averageArray(numArray, ARRAY_SIZE);
	cout << "Average " << avg;
}

void initArray(NumArray a, const int size) {
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 1000;
	}
}
void sortArray(NumArray a, const int size) {
	//selection sort:
	int largestIndex = 0;
	for (int i = 0; i < size; i++) {
		largestIndex = i;
		for (int j = i; j < size; j++) {
			if (a[largestIndex] < a[j]) {
				largestIndex = j;
			}
		}
		if (i != largestIndex) {
			swap(a[i], a[largestIndex]);
		}
	}
}

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

void printArray(NumArray a, const int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(3) << a[i] << " ";
	}
	cout << endl;
}
int averageArray(NumArray a, const int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum / size;
}
