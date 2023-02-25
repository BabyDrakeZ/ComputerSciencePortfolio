#include<iostream>
using namespace std;


int main(void) {
	int numberOfPeople = 2;
	int sumCost = 0;
	float individualCost = 0.0;

	for (int i =  0; i < numberOfPeople; i++) {
		sumCost += i*i - 5.0;
	}
	sumCost = abs(sumCost);
	individualCost = (sumCost*1.0)/numberOfPeople; /*1.0 cast to double*/

	cout << individualCost << "\n";
	return 0;
}

/* If numberOfPeople was <=3 everyone would be get payed!
   Not good.
   So, I added an absolute value check so that the output is always positive.
*/