// CS111_Parallel_Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// How to Use Arrays -- Week 2 Sem 1;
// Random Number Initialization

#include <iostream>
#include <string>
#include <fstream>


// Foo 15 Mike 697 Kam 1 Joe -1 Ugned 14 Mack 68 Mary 7 Robert 19 Quin 10 Vicky 19

#define ARRAY_LENGTH 2000
#define NOT_FOUND -1


// NEVER DO THIS EXCEPT TO COLLECT DATA
long int gNumberOfSwaps = 0;
long int gNumberOfComparisons = 0;

using namespace std;


void initArrays(int arr[], string n[], const int size); //arrays are always pass by refrence
void printData(int ids[], string names[], const int size);
void getStudentDataFromTTY(int ids[], string names[], const int size);

//precondition: int arr[] is the the list of integers size is size of array
//postcondition: sums the contents of the array and puts the sum in arr[0]
//void sumArrays(int arr[], const int size);

void getStudentDataFromFile(int ids[], string names[], const int size, int& numItemsInFile);

//precondition: int z[] are the IDS...
int searchByNameForID(const int z[], const string n[], const int size, const string target);

string searchByIDForName(const int ids[], const string names[], const int size, const int target);

//precondition: s[] is an array of strings, is[] is an array of corresponding ints, target is search target
//postcondition: return id of target or NOT_FOUND if not found
int search(string s[], int is[], int const size, string target);


void bubbleSortByID(int numbers[], string names[], const int size);

void selectionSortByID(int numbers[], string names[], const int size);

void swap(int &first, int &second);

void swap(string &first, string &second);



int main()
{
    //srand(time(NULL));  //initialized the random number generator--CALL THIS ONLY ONCE //seed rand
    srand(622);
    int ids[ARRAY_LENGTH]; //= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    string names[ARRAY_LENGTH];
    string name = "";
    int id = -1;
    initArrays(ids, names, ARRAY_LENGTH);
    //getStudentDataFromTTY(ids, names, ARRAY_LENGTH);
    //sumArray(ints, ARRAY_LENGTH);

    //cout << "Enter a name or id you would like to search for: ";
    //cin >> name;
    //search(ids, names, ARRAY_LENGTH, name);

    //cout << "Enter a name you would like to search for an id with: ";
    //cin >> name;
    //id = searchByNameForID(ids, names, ARRAY_LENGTH, name);
    //if (id != NOT_FOUND)
    //    cout << "Id found: " << id << endl;
    //else
    //    cout << "Index Failed" << endl;
    //
    //cout << "Enter an id you would like to search for a name with: ";
    //cin >> id;
    //name = searchByIDForName(ids, names, ARRAY_LENGTH, id);
    //if (name != "NOT_FOUND")
    //    cout << "Name found: " << name << endl;
    //else
    //    cout << "Index Failed" << endl;
    cout << "Bubble" << "\n";
    bubbleSortByID(ids, names, ARRAY_LENGTH);
    cout << "numSwaps" << gNumberOfSwaps << "\n";
    cout << "numComps" << gNumberOfComparisons << "\n";

    initArrays(ids, names, ARRAY_LENGTH);
    gNumberOfSwaps = 0;
    gNumberOfComparisons = 0;
    cout << "Selection" << "\n";
    selectionSortByID(ids, names, ARRAY_LENGTH);

    cout << "numSwaps" << gNumberOfSwaps << "\n";
    cout << "numComps" << gNumberOfComparisons << "\n";
    return 0;
}

void initArrays(int z[], string n[], const int size) {
    for (int i = 0; i < size; i++) {
        z[i] = rand() % 100; //0's are not a good number, pick values that will break things, like random numbers
        z[i] = i;
        n[i] = "Name_" + to_string(z[i]);
    }
}
void printData(int ids[], string names[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << "Student " << names[i] << " has ID: " << ids[i] << "\n";
    }
}

void getStudentDataFromTTY(int ids[], string names[], const int size) {
    cout << "Please input " << size << " names and ids" << "\n";
    for (int i = 0; i < size; i++) {
        string name = "";
        int id = 0;
        cout << "Input name and id: ";
        cin >> name >> id;
        ids[i] = id;
        names[i] = name;
    }
}
int searchForIndex(const string n[], const int is[], const int size, const string target){
    for (int i = 0; i < size; i++) {
        if (n[i] == target || (to_string(is[i]) == target)) {
            //cout << "Search found: " << n[i] << " " << is[i] << "\n";
            return i;
        }
    }
    return NOT_FOUND;
}

string searchByIDForName(const int ids[], const string names[], const int size, const int target) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == target) {
            return names[i];
        }
    }
    return "NOT_FOUND";
}

int searchByNameForID(const int ids[], const string names[], const int size, const string target) {
    //int index = searchForIndex(n, z, size, target);
    //return z[index];
    for (int i = 0; i < size; i++) {
        if (names[i] == target) {
            //cout << "Search found: " << names[i] << " " << ids[i] << "\n";
            return ids[i];
        }
    }
    return NOT_FOUND;
}

void bubbleSortByID(int numbers[], string names[], const int size) {
    bool done = false;
    for (int i = size-1; ((!done) && (i > 0)); i--){
        done = true; // until we know better
        for (int j = 0; j < size-1; j++) {
            gNumberOfComparisons++;
            if (numbers[j] > numbers[j + 1]) {
                done = false; // because we are making a swap
                swap(numbers[j], numbers[j + 1]);
                swap(names[j], names[j + 1]);
                gNumberOfSwaps += 2;
            }
        }
    }
}

void selectionSortByID(int numbers[], string names[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            gNumberOfComparisons++;
            if (numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(numbers[i], numbers[minIndex]);
            swap(names[i], names[minIndex]);
            gNumberOfSwaps += 2;
        }
    }
}

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}
void swap(string &first, string &second) {
    string temp = first;
    first = second;
    second = temp;
}

void getStudentDataFromFile(int ids[], string names[], const int size, int& numItemsInFile){
    string name = "";
    int id = -1;
    ifstream dataFile;
    dataFile.open("data.txt");
    if (dataFile.fail()) {
        cout << "Can't open data file \n";
        exit(1);
    }
    int iterator = 0;
    while (int i = 0; i < size; dataFile >> name >> id, i++) {
        dataFile >> n >> id;
        names[iterator] = n;
        ids[iterator] = id;
        if (iterator++ == size || dataFile.eof()) {
            break;
        }
    }
}


//void sumArray(int arr[], const int size) {
//    for (int i = 1; i < size; i++) {
//        arr[0] += arr[i];
//    }
//}