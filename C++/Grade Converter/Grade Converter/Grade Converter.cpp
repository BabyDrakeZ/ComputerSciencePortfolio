// Grade Converter.cpp : This file contains the 'main' function. Program execution begins and ends there.
// convert a number grade (0 to 100) to a letter grade (A, B, C, D, F).

#include <iostream>
using namespace std;

int main()
{
    char letterGrade;
    float numGrade;

    cout << "Enter a number grade (0 through 100):";
    cin >> numGrade;

    // A linked list may be more efficient here, at least it might look nicer, but I am not sure how to use them in c++
    if (numGrade <= 30) {
        letterGrade = 'F';
    }
    // There is no E... it would be too exceptional...
    else if (numGrade <= 40) {
        letterGrade = 'D';
    }
    else if (numGrade <= 60) {
        letterGrade = 'C';
    }
    else if (numGrade <= 90) {
        letterGrade = 'B';
    }
    else if (numGrade <= 100) {
        letterGrade = 'A';
    }
    else {
        cout << "<<INVALID INPUT>>";
        return 1;
    }
    cout << "The equivalent letter grade:" << letterGrade << endl;
    //Fill in code here.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
