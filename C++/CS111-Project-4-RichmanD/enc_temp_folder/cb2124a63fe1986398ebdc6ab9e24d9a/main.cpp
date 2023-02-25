
#include <iostream>
#include <fstream>

#include "boat.h"

typedef Boat* BoatPtr;

void headInsert(BoatPtr head);

//preconditions: --
//postconditions: writes content of arrays bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatPtr head);

//preconditions:  all arrays have been initialized
//postconditions: arrays are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatPtr head);

//preconditions: sizes array has valid data, size is array size
//postconditions: returns the average boat size based on data in sizes
double averageBoatSize(BoatPtr head);


//preconditions:  all arrays have valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatPtr head, std::string target);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in ascending order by boat size using bubblesort
void bubbleSortByBoatSize(BoatPtr head);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in descending order by boat size using selection sort
void selectionSortByBoatSize(BoatPtr head);

int main(void) {
    BoatPtr head = NULL;
    readData(head);
    /*cout << "The average boat size is " << averageBoatSize(head) << "\n";
    string target;
    cout << "Enter name of owner ";
    cin >> target;
    findDataByOwnerName(boatOwnerNames, boatNames, boatSizes, arraySize, target);
    cout << endl;*/
    std::cout << "\nunsorted:" << "\n";
    printBoatData(head);

    std::cout << "\nbubble sorted:" << "\n";
    //bubbleSortByBoatSize(head);
    printBoatData(head);

    std::cout << "\nselection sorted:" << "\n";
    //selectionSortByBoatSize(head);
    printBoatData(head);
    return 0;
}

void headInsert(BoatPtr head, BoatPtr ptr) {
    ptr->setNext(head);
    head = ptr;
    ptr = NULL;
}

void printBoatData(BoatPtr head) {
    for (BoatPtr itr = head; itr != NULL; itr = itr->getNext())
        itr->print();
}

void readData(BoatPtr head) {
    std::ifstream inFS;
    inFS.open("data.txt");
    if (inFS.fail()){
        std::cout << "file failed to open... quiting.\n";
        exit(1);
    }
    std::string boatName = "N/A";
    std::string boatOwner = "N/A";
    double boatSize = -1;
    while(!inFS.eof()) {
        inFS >> boatName;
        inFS >> boatOwner;
        inFS >> boatSize;
        BoatPtr boatp = new Boat(boatOwner, boatName, boatSize);
        headInsert(head, boatp);
        boatp = NULL;
    }
    inFS.close();
}