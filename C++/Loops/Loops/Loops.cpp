// Loops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#define NUM_ROWS 20
#define NUM_COLS 6
#define LOOP_LIMIT 10
using namespace std;

// Print the following output 3 5 7 9 11 13... depth-2 depth
void oddForLoop(int depth);

//Using only two loops for formating the shape draw a bunch of diamonds
int main()
{
    for (int r = 0; r < NUM_ROWS; r++) { //ONLY For Displaying many Rows
        
        
        string spaces = "";
        for (int j = 1; j <= LOOP_LIMIT; j++) {
            spaces += ' ';
        }

        string stars = "";
        for (int k = 1; k <= LOOP_LIMIT*2; k++) {
            if (k <= LOOP_LIMIT) {
                stars += "* ";
                spaces = spaces.substr(0, spaces.length() - 1);
            }
            else {
                stars = stars.substr(0, stars.length() - 2);
                spaces += ' ';
            }
            
            for (int c = 0; c < NUM_COLS; c++) { //ONLY For Displaying many Colums
                cout << spaces << stars << spaces;
            }
            cout << "\n";
        }
            
    }
    oddForLoop(LOOP_LIMIT*NUM_COLS*NUM_ROWS);
    return 0;
}

void oddForLoop(int depth){
    char exiter = ' ';
    for (int i = 3; i < depth; i += 2) {
        cout << i << ' ';
    }
    cout << endl;
}