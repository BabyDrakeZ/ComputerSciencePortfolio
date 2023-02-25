#pragma once

#include <iostream>
#include <vector>

const int BOARD_SIZE = 3;
const char EMPTY_MARKER = '-';
const char FULL_BOARD = '&';
typedef char TheBoard[BOARD_SIZE][BOARD_SIZE];

class Board {
public:
	//precondition: -
	//postcondition: board is assigned EMPTY_MARKER
	Board();
	//precondition: theBoard is initialized
	//postcondition: theBoard is printed to cout
	void printBoard();
	//precondition: row, col have input from player
	//postcondition: if valid, theBoard contains player's mark at row, col;
	//	if invalid move, it is rejected, and error message is displayed to player
	//	and player forfeits turn
	// consider using try/catch for handling moves.
	bool submitMove(int row, int col, char player);
	//precondition: board has EMPTY_MARKER or player marks, or both
	//postcondition: returns 'n' for no winner, 'd' for draw, 'X' or 'O' if a or b won
	char isWinner();
private:
	TheBoard theBoard; //game board
	//precondition: row, col have player input
	//postcondition: return true if theBoard[row][col]==EMPTPY_MARKER; false otherwise
	bool isMoveValid(int row, int col);
	int countNumberOfTakenSquares = 0; //useful for determining draw if no winnining and all squares are marked by players
};