// HW 1 -- Arrays and Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This project is built to practice using arrays and files in conjunction with each other

#include <iostream>
#include <fstream>
#define ARRAY_LENGTH 5

using namespace std;

int main()
{
	//Initialize variables and streams:
	ifstream inFS;
	ofstream outFS;
	int minValue = 0;
	int arr[ARRAY_LENGTH];
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		arr[i] = -1;
	}

	//Open files
	cout << "opening files..." << endl;
	inFS.open("data.txt");
	outFS.open("smallest.txt");
	if (inFS.fail() || outFS.fail()) {
		cout << "FILE FAILED TO OPEN! EXITING..." << endl;
		exit(1);
	}

	//Collect data into array
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		inFS >> arr[i]; //old: arr[i] = currentValue;
		if (i == 0 || arr[i] < minValue) {
// i==0 || is so there is always a minValue to compare to. It may have been more explicit to put an assignment outside the for loop, but I didn't.
			minValue = arr[i];
		}
	}

	//Output minimum value
	outFS << minValue << ""; //I added the "" because it wouldn't work otherwise, I am not sure why. I'll ask you in class.
	
	cout << "closing files" << "\n";
	inFS.close();
	outFS.close();
	return 0;
}