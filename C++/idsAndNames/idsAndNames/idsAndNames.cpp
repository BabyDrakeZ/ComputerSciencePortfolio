// idsAndNames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	const int length = 5;
	string names[length];
	int ids[length];
	
	string output = "";
	
	for (int i = 0; i < length; i++) {
		string name;
		int id;
		cout << "Please provide name and id";
		cin >> name >> id; 
		names[i] = name;
		ids[i] = id;
		output = output + name + ", " + to_string(id) + "\n";
	}
	cout << "\n" << output << endl;
	return 0;
}