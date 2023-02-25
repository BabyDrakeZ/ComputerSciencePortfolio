// Matrixs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#define SIZE 10

typedef double Matrix[SIZE][SIZE];


using namespace std;

void initArray(Matrix m, const int rows, const int cols);

//precondition: a is a square @D array, size is size of row or column
//postconditio: a contents printed in the appropriate order
void printRowMajor(Matrix m, const int rows, const int cols);
void printColMajor(Matrix m, const int rows, const int cols);
void printArray(double a[], const int size);


//precondtition: a is a square 2D array, size is size of row or column
//postcondtion: returns in diagonal a's diagonal
void diagonal(Matrix a, int size, double diag[]);
//postcondtion redturns the sum of all the cells in the matrix
double sumAll(Matrix m, const int rows, const int cols);


void printSpiralIndex(Matrix m, const int size);

int main() {
	srand(100);
    Matrix matrix;
	double diag[SIZE];
	initArray(matrix, SIZE, SIZE);
	//transposition
	printRowMajor(matrix, SIZE, SIZE);
	cout << endl;
	printSpiralIndex(matrix, SIZE);
	cout << endl;
	printColMajor(matrix, SIZE, SIZE);
	cout << "\nThe matrix sum is: " << sumAll(matrix, SIZE, SIZE) << "\n";
	diagonal(matrix, SIZE, diag);
	cout << "\nThe diagonal is: " << endl;
	printArray(diag, SIZE);

}


void initArray(Matrix m, const int rows, const int cols) {
	int sum = 0;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++, sum++)
		{
			m[i][j] = rand()%100;
			m[i][j] = sum;
		}
	}
}

void printColMajor(Matrix m, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << m[j][i] << " ";
		}
		cout << endl;
	}
}

void printRowMajor(Matrix m, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(4) << m[i][j] << " ";
		}
		cout << endl;
	}
}

void printArray(double a[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << a[i] << ", ";
	}
}

//returns a copy of the diagonal
void diagonal(Matrix a, int size, double diag[]) {
	for (int i = 0; i < size; i++) {
		diag[i] = a[i][i];
	}
}

double sumAll(Matrix m, const int rows, const int cols) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum += m[i][j];
		}
	}
	return sum;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
