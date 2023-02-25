//STYLE GUIDE CODE for Homework 0 of CS-111, 9/10/2021, David C.P. Richman, St. Vincent College

#include<iostream>
using namespace std;

//main is my current rendition of what I believe you want.
int main(void){
	int i = 0;
	int sum = 0;
	int num = 12;
	float average = 0.0;
	
	while (i<num) {
		sum += i*i - 5;
		i++;
	}
	average = (sum*1.0) / (num*1.0); // *1.0 causes floating point division
	
	cout << average << endl;
	return 0;
}



//The following code was my first rendition of "bad.cpp" which you rejected, although I did change the while loop from a for loop so that it looked even more alike.
int initalTake(void) {
	int numberOfPeople = 12;
	int sumCost = 0;
	int i = 0;
	float averagePersonalCost = 0.0;

	// for(int i = 0; i < numberOfPeople; i++) {
	while (i < numberOfPeople) {
		sumCost += i*i - 5;
		i++;
	}
	sumCost = abs(sumCost); //Because I am calculating cost instead of generic value I do abs() so that I don't get negatives.
	averagePersonalCost = (sumCost * 1.0) / (numberOfPeople * 1.0); /* *1.0 casts division to floating point*/

	cout << averagePersonalCost << "\n";
	return 0;
}