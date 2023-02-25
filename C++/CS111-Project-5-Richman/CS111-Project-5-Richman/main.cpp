
#include <iostream>
#include <fstream>

#include "boat.h"



void headInsert(BoatPtr head);

//preconditions: --
//postconditions: writes content of arrays bounded by size in the following order: boatname, 
//                ownerName, size
void printList(BoatPtr head);

//preconditions:  all arrays have been initialized
//postconditions: arrays are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
void readData(BoatPtr& head);

//preconditions: sizes array has valid data, size is array size
//postconditions: returns the average boat size based on data in sizes
double averageBoatSize(BoatPtr head);

//preconditions: head is a pointer to a list of Boat objects or NULL
//postcondition: the list is deleted
void deleteList(BoatPtr& head);


//preconditions:  all arrays have valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatPtr& head, std::string target);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in ascending order by boat size using bubblesort
void bubbleSortByBoatSize(BoatPtr head);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in descending order by boat size using selection sort
void selectionSortByBoatSize(BoatPtr head);

int main(void) {
    BoatPtr head = NULL;
    readData(head);
    std::cout << "The average boat size is " << averageBoatSize(head) << "\n";
    std::cout << "\nBoat Inventory:\n";
    printList(head);

    std::string target;
    std::cout << "Enter name of owner ";
    std::cin >> target;
    findDataByOwnerName(head, target);
    std::cout << "\n";
    deleteList(head);
    printList(head);
    return 0;
}

void headInsert(BoatPtr& head, BoatPtr& ptr) {
    ptr->setNext(head);
    head = ptr;
    ptr = NULL;
}

void printList(BoatPtr head) {
    for (BoatPtr itr = head; itr != NULL; itr = itr->getNext())
        itr->print();
}

void readData(BoatPtr& head) {
    std::ifstream inFS;
    inFS.open("data.txt");
    if (inFS.fail()) {
        std::cout << "file failed to open... quiting.\n";
        exit(1);
    }

    while (!inFS.eof()) {
        std::string tempOwner = "";
        double tempSize = 0;
        std::string tempName = "";
        inFS >> tempOwner;
        if (inFS.eof()) {
            //improperly configured when an entry is incomplete (missing its size)
            std::cout << "File was improperly confiured or empty!";
            exit(1);
        }
        inFS >> tempSize;
        inFS >> tempName;
        BoatPtr boatp = new Boat(tempOwner, tempName, tempSize);
        headInsert(head, boatp);
    }
    inFS.close();
}

double averageBoatSize(BoatPtr head) {
    double count = 0;
    double sum = 0;
    for (BoatPtr itr = head; itr != NULL; itr = itr->getNext()) {
        count++;
        sum += itr->getBoatSize();
    }
    return sum / count;
}

void deleteList(BoatPtr& head) {
    BoatPtr temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->getNext();
        delete temp;
    }
}

void findDataByOwnerName(BoatPtr& head, std::string target) {

    for (BoatPtr itr = head; itr != NULL; itr = itr->getNext()) {
        if (itr->getBoatOwnerName() == target)
        {
            std::cout << "Search found: ";
            itr->print();
            return;
        }
    }
    std::cout << "No such owner found in Inventory.\n";
}