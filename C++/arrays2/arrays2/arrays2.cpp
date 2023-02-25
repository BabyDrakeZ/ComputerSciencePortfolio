// arrays2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>

// precondition arr is a valid array and len is the length of that array
// postcondition sums all the values of an array at index 0
void sumIntArray(int arr[], int len);


int main()
{
    int a[] = { 12, -3, 5, 20, 17, 8, 0, -6, 9 };
    int aLength = std::size(a);

    //sumation of array
    sumIntArray(a, aLength);

    std::cout << "sum = " << a[0] << std::endl;
    return 0;
}

void sumIntArray(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        arr[0] = arr[0] + arr[i];
    }
}