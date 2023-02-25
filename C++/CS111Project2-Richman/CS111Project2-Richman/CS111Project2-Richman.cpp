// CS111Project2-Richman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

#define SIZE 15

using namespace std;

typedef double Matrix[SIZE][SIZE];

//precondition: matrix is the simulation, size is the number of colums and rows
//postcondition: matrix is initialized to border temperature.
//Ask the user to supply a boundary temperature greater than 0
//All non-border elements are all set to zero
void initializeSimulation(Matrix matrix, const int size);

//precondition: matrix is the simulation, size is number of columns and rows, 
// runs is the of simulation runs.
//postcondition: matrix contains the simulation values after the simulation completes 
// runs runs. 
void simulate(Matrix matrix, const int size, int runs);

//precondtion: matrix is the simulation, size is number of colums and rows,
// tolerance is the desired tolerance of the simulation and is not zero.
//postcondition: matrix contains the simulation values after the simulation reaches
// a maximum difference of tolerance
void simulate(Matrix matrix, const int size, double tolerance);

//precodition: matrix is the simulation, size is the size of the array.
//postcondition: averageNeighbors is called on every index in the array (excepting edge cases)
// returns greatest delta
double averageMatrix(Matrix matrix, const int size);

//precondtion: matrix is the simulation, row and col are a non-border index
//postcondtion: the index's value becomes 98% (due to losses) of the average its neighbors
double averageNeighbors(Matrix matrix, int row, int col);

//precondition: matrix is the simulation, size is number of columns and rows
//postcondition: the contents of the matrix are output to the screen
// set precision to one and width to four
void printSimulationResult(Matrix matrix, const int size);


int main() {
	Matrix simulation;
	int runs = 20;
	double tolerance = 0.001;
	initializeSimulation(simulation, SIZE);
	printSimulationResult(simulation, SIZE);
	//simulate(simulation, SIZE, runs); //uncomment this...
	simulate(simulation, SIZE, tolerance); //and comment this to do runs.
	printSimulationResult(simulation, SIZE);
	return 0;
}

void initializeSimulation(Matrix matrix, const int size) {
	double roomTemp = 0.0; //room temperature
	double initTemp = 0.0;
	cout << "Please enter a room temperature, greater than 0: ";
	cin >> roomTemp;
	//inititalize boundary temperatures
	for (int i = 0; i < size; i++) {
		//inititalize boundary temperature
		matrix[0][i] = roomTemp;
		matrix[i][0] = roomTemp;
		matrix[size - 1][i] = roomTemp;
		matrix[i][size - 1] = roomTemp;
		//initialize interior temperature
		for (int j = 1; j < size-1 && (0 < i && i < size-1); j++) {
			matrix[i][j] = initTemp; 
		}
	}
}

void printSimulationResult(Matrix matrix, const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(4) << setprecision(1) << fixed << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void simulate(Matrix matrix, const int size, int runs) {
	for (int i = 0; i < runs; i++) {
		averageMatrix(matrix, size);
	}
}
void simulate(Matrix matrix, const int size, double tolerance) {
	double delta = tolerance + 1; // +1 ensures that the loop executes at least once
	while (delta>tolerance) {
		delta = averageMatrix(matrix, size);
	}
}

double averageMatrix(Matrix m, int size) {
	double largestDelta = 0;
	double delta = 0;
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			delta = averageNeighbors(m, i, j);
			if (delta > largestDelta) {
				largestDelta = delta;
			}
		}
	}
	return largestDelta;
}

double averageNeighbors(Matrix m, int row, int col) {
	double sumNeighbors = 0;
	double delta = 0;
	sumNeighbors += m[row][col - 1] + m[row - 1][col] + m[row][col + 1] + m[row + 1][col];
	/*for (int i = row - 1; i < row + 2; i++) {
		for (int j = col - 1; j < col + 2 && !(j == col && i == row); j++) {
			sumNeighbors += m[i][j];
		}
	}*/
	delta = ((sumNeighbors/4)*0.98) - m[row][col];
	m[row][col] = (sumNeighbors / 4)*0.98; //8)*0.98;
	return delta;
}