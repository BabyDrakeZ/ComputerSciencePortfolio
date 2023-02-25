// Fahrenheit to Celsius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double getInput(string tempName)
{
    double temp;
    cout << "Please enter a temparture in " << tempName << ":\n";
    cin >> temp;
    return temp;
}

double getFileInput(void)
{
    double temp;
    string tempName;
    ifstream inFS;

    // File Format:
    // 1: <string>
    // 2: <double>
    // 3: end of File

    inFS.open("temperatureInput.txt");
    if (!inFS.is_open()) {
        cout << "Failed to open the input file!\n" << "Returning default output 0.0* F:\n\n";
        return NULL;
    }
    getline(inFS, tempName);
    inFS >> temp;

    if (inFS.fail()) {
        cout << "<<Invalid input!>>\n" << "Returning default output for 0.0* F:\n\n";
    }

    cout << tempName << endl;
    cout << temp << endl;
    return temp;
}

int main(void)
{
    double tempF;
    double tempC;
    tempF = getFileInput();
    //tempF = getInput("fahrenhiet");
    tempC = (tempF - 32) * (5 / 9.0);
    cout << "In Celcius that is:\n" << tempC;
}
