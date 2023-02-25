
#include <iostream>
#include <fstream>

#include "boat.h"



void headInsert(BoatStructPtr head);

//preconditions: --
//postconditions: writes content of arrays bounded by size in the following order: boatname, 
//                ownerName, size
void printBoatData(BoatStructPtr head);

//preconditions:  all arrays have been initialized
//postconditions: arrays are filled with data from data.tx. 
//                File format is: owner name, boat size, boat name
 //               The parameter size is the number of lines in the file
//Notes: assumes a single string for owner name or boat name. Woods 320 Privacy is valid,
//       Tiger Woods 320 Privacy is not valid (line has three strings)
//       all file operations--opening, checking, reading, closing--must occur in readData(...)
//       It is possible that size may be one more than the number of data lines depending on
//       how the EOF character is represented.
void readData(BoatStructPtr& head);

//preconditions: sizes array has valid data, size is array size
//postconditions: returns the average boat size based on data in sizes
double averageBoatSize(BoatStructPtr head);

//preconditions: head is a pointer to a list of Boat objects or NULL
//postcondition: the list is deleted
void deleteList(BoatStructPtr& head);


//preconditions:  all arrays have valid data
//postconditions: prints data associated with target (boat owner); 
//                if not found, print Owner target not found
void findDataByOwnerName(BoatStructPtr& head, std::string target);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in ascending order by boat size using bubblesort
void bubbleSortByBoatSize(BoatStructPtr head);

//precondition: all arrays have valid data
//postcondition: arrays are sorted in descending order by boat size using selection sort
void selectionSortByBoatSize(BoatStructPtr head);

int main(void) {
    BoatStructPtr head = NULL;
    readData(head);
    std::cout << "The average boat size is " << averageBoatSize(head) << "\n";
    std::cout << "\nBoat Inventory:\n";
    printBoatData(head);

    std::string target;
    std::cout << "Enter name of owner ";
    std::cin >> target;
    findDataByOwnerName(head, target);
    std::cout << "\n";
    deleteList(head);
    return 0;
}

void headInsert(BoatStructPtr& head, BoatStructPtr& ptr) {
    ptr->next = head;
    head = ptr;
    ptr = NULL;
}

void printBoatData(BoatStructPtr head) {
    for (BoatStructPtr itr = head; itr != NULL; itr = itr->next)
        itr->print();
}

void readData(BoatStructPtr& head) {
    std::ifstream inFS;
    inFS.open("data.txt");
    if (inFS.fail()){
        std::cout << "file failed to open... quiting.\n";
        exit(1);
    }
    
    while(!inFS.eof()) {
        BoatStructPtr boatp = new Boat();
        inFS >> boatp->boatOwnerName;
        if (inFS.eof()) {
            //improperly configured when an entry is incomplete (missing its size)
            std::cout << "File was improperly confiured or empty!";
            exit(1);
        }
        inFS >> boatp->boatSize;
        inFS >> boatp->boatName;
        headInsert(head, boatp);
        
    }
    inFS.close();
}

double averageBoatSize(BoatStructPtr head) {
    double count = 0;
    double sum = 0;
    for (BoatStructPtr itr = head; itr != NULL; itr = itr->next) {
        count++;
        sum += itr->boatSize;
    }
    return sum / count;
}

void deleteList(BoatStructPtr& head) {
    BoatStructPtr temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head->next;
        temp->next = NULL;
        std::cout << "removing: ";
        temp->print();
        delete temp;
    }
}

void findDataByOwnerName(BoatStructPtr& head, std::string target) {
    
    for (BoatStructPtr itr = head; itr != NULL; itr = itr->next) {
        if (itr->boatOwnerName == target)
        {
            std::cout << "Search found: ";
            itr->print();
        }
    }
    std::cout << "No such owner found in Inventory.\n";
}