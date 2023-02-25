// CS111-Project-1-5-Richman.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Extends Project one by adding sorting functions

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_SIZE 20
typedef string BoatNames[MAX_SIZE];
typedef string BoatOwnerNames[MAX_SIZE];
typedef double BoatSizes[MAX_SIZE];


//preconditions: --
//postconditions: all array elements are intialized as follows:
//              string: ""
//              int: -1
void initArrays(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size);

//preconditions: --
//postconditions: writes content of arrays bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size);

//preconditions:  all arrays have been initialized
//postconditions: arrays are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int& size);

//preconditions: sizes array has valid data, size is array size
//postconditions: returns the average boat size based on data in sizes
double averageBoatSize(BoatSizes sizes, int size);


//preconditions:  all arrays have valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size, string target);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in ascending order by boat size using bubblesort
void bubbleSortByBoatSize(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, const int size);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in descending order by boat size using selection sort
void selectionSortByBoatSize(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, const int size);

//postcondtition: swaps first and second's values
void swap(int& first, int& second);
void swap(string& first, string& second);


int main() {
    BoatNames boatNames;
    BoatOwnerNames boatOwnerNames;
    BoatSizes boatSizes;
    int arraySize = 0;

    initArrays(boatOwnerNames, boatNames, boatSizes, MAX_SIZE);
    readData(boatOwnerNames, boatNames, boatSizes, arraySize);
    cout << "Number of lines read " << arraySize << endl;
    cout << "The average boat size is " << averageBoatSize(boatSizes, arraySize) << "\n";
    /*string target;
    cout << "Enter name of owner ";
    cin >> target;
    findDataByOwnerName(boatOwnerNames, boatNames, boatSizes, arraySize, target);
    cout << endl;*/
    cout << "\nunsorted:" << "\n";
    printBoatData(boatOwnerNames, boatNames, boatSizes, arraySize);
    
    cout << "\nbubble sorted:" << "\n";
    bubbleSortByBoatSize(boatOwnerNames, boatNames, boatSizes, arraySize);
    printBoatData(boatOwnerNames, boatNames, boatSizes, arraySize);
    
    cout << "\nselection sorted:" << "\n";
    selectionSortByBoatSize(boatOwnerNames, boatNames, boatSizes, arraySize);
    printBoatData(boatOwnerNames, boatNames, boatSizes, arraySize);
}

void initArrays(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size) {
    for (int i = 0; i < size; i++) {
        sizes[i] = -1;
        ownerNames[i] = "";
        boatNames[i] = "";
    }
}

void printBoatData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Boat " << boatNames[i] << " owned by " << ownerNames[i] << " size " << sizes[i] << "\n";
    }
}

void readData(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int& size) {
    ifstream inFS;
    inFS.open("data.txt");
    if (inFS.fail()) {
        cout << "File does not exist or failed to open! -- exiting" << endl;
        exit(1);
    }
    while (size < MAX_SIZE && !inFS.eof()) {
        inFS >> ownerNames[size] >> sizes[size] >> boatNames[size];
        if (!inFS.eof())
            size++;
    }
    if (size == 0) {
        cout << "Nothing read from file -- exiting" << endl;
        inFS.close();
        exit(2);
    }
    if (size >= MAX_SIZE && !inFS.eof()) {
        cout << "--WARNING: File was too big, couldn't read all data" << "\n";
    }
    inFS.close();
}


double averageBoatSize(BoatSizes sizes, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += sizes[i];
    }
    return total / size;
}

void findDataByOwnerName(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, int size, string target) {
    //search
    for (int i = 0; i < size; i++) {
        if (ownerNames[i] == target) {
            cout << "Boat " << boatNames[i] << " owned by " << ownerNames[i] << " size " << sizes[i] << "\n";
            break;
        }
        else if (i + 1 == size) {
            cout << "Owner target not found. Make sure your capitalization is correct and try again." << endl;
        }
    }
}

void bubbleSortByBoatSize(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, const int size) {
    bool done = false;
    for (int i = 0; ((!done) && (i < size-1)); i++) {
        for (int j = 0; j < size-1; j++) {
            done = true;
            if (sizes[j] > sizes[j + 1]) {
                done = false;
                swap(sizes[j], sizes[j + 1]);
                swap(ownerNames[j], ownerNames[j + 1]);
                swap(boatNames[j], boatNames[j + 1]);
            }
        }       
    }
}
void selectionSortByBoatSize(BoatOwnerNames ownerNames, BoatNames boatNames, BoatSizes sizes, const int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (sizes[minIndex] < sizes[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(sizes[i], sizes[minIndex]);
            swap(ownerNames[i], ownerNames[minIndex]);
            swap(boatNames[i], boatNames[minIndex]);
        }
        
    }
}

void swap(double& first, double& second) {
    int temp = first;
    first = second;
    second = temp;
}
void swap(string& first, string& second) {
    string temp = first;
    first = second;
    second = temp;
}