// CS111-Recursion_F21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct T {
    int i;
    T* next;
    T() { i = 0; next = NULL; }
};


typedef T* tPtr;
void traverseList(tPtr& t);

uint64_t factorial(uint64_t n);
int fibonacci(int n);

void dpTableWrite(uint64_t value, int index);
uint64_t dpTableGetValue(int index);
uint64_t dpTable[40];



int main()
{
    //uint64_t arg = 6;
    //uint64_t test = factorial(arg);

    //std::cout << "Factorial of " << arg << " is " << test << std::endl;
    const uint64_t arg = 35;
    tPtr head = NULL;
    for (int i = 0; i < 5; i++) {
        tPtr temp = new T();
        temp->i = i;
        temp->next = head;
        head = temp;
    }

    //for (int i = 0; i < arg; i++) {
    //    dpTable[i] = 0;
    //}
    //int value_table[arg];
    //int test = fibonacci(arg);
    //std::cout << "Fibonacci of " << arg << " is " << test << std::endl;

}


uint64_t factorial(uint64_t n) {
    //uint64_t temp = 1;
    //for (uint64_t i = n; i > 0; i--) {
    //    temp *= i;
    //    std::cout << "n " << i << std::endl;
    //}
    //return temp;
    if (n == 0)
        return 1;
    std::cout << "n " << n << std::endl;
    return n * factorial(n - 1);
}

//base cases: n == 0, return 0, n==1, return 1;
//recursive call f(n) = f(n-1) + fib(n-2)
//int fibonacci(int n) {
//    if (n <= 1)
//        return n;
//    std::cout << "n " << n << std::endl;
//    return fibonacci(n - 1) + fibonacci(n - 2);
//}
int fibonacci(int n) {
    std::cout << "n " << n << std::endl;
    if (dpTableGetValue(n) != 0) {
        std::cout << "Value found, I saved lots of time\n";
        return dpTableGetValue(n);
    }
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    uint64_t temp = fibonacci(n - 1) + fibonacci(n - 2);
    dpTableWrite(temp, n);
    return temp;
}


void dpTableWrite(uint64_t value, int index) {
    dpTable[index] = value;
}

uint64_t dpTableGetValue(int index) {
    return dpTable[index];
}

void traverseList(tPtr& t) {
    //if (t!=NULL)
        //std::cout << t->i << std::endl; //prefixing
    if (t == NULL)
        return;
    traverseList(t->next);
    std::cout << t->i << std::endl; //postfixing
}