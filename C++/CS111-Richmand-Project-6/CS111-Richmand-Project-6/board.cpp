#include "board.h"

Board::Board(){
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			theBoard[i][j] = EMPTY_MARKER;
}

void Board::printBoard() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << theBoard[i][j] << " ";
		std::cout << std::endl;
	}
	
}

bool Board::submitMove(int row, int col, char player) {
	if (isMoveValid(row, col)) {
		theBoard[row][col] = player;
		countNumberOfTakenSquares++;
		return true;
	}
	else {
		std::cout << "Invalid Move! Turn Forfieted.\n";
		return false;
	}
}

bool Board::isMoveValid(int row, int col) {
	if (row >= BOARD_SIZE || row < 0 || col >= BOARD_SIZE || col < 0) {
		std::cout << "Out Of Bounds!\n";
		return false;
	}
	return theBoard[row][col] == EMPTY_MARKER;
}

char Board::isWinner() {
	//precondition: more than BOARD_SIZE moves completed
	if (countNumberOfTakenSquares < BOARD_SIZE)
		return EMPTY_MARKER;

	//initialize diagonal variables
	bool winT = true; // top diagonal (\)
	char majorT = theBoard[0][0];
	bool winB = true; // bottom diagonal
	// [0][SIZE], [1][SIZE-1], [2][SIZE-2] ...
	char majorB = theBoard[0][BOARD_SIZE];
	
	//for vertical and horizontal victory conditions
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		bool winH = true;
		bool winV = true;
		char majorH = theBoard[i][0];
		char majorV = theBoard[0][i];
		for (int j = 0; j < BOARD_SIZE; j++) {
			//horizontally?
			if (winH && theBoard[i][j] != majorH)
				winH = false;
			//vertically?
			if (winV && theBoard[j][i] != majorV)
				winV = false;
		}
		//V and H victories
		if (winH)
			return majorH;
		if (winV)
			return majorV;

		//diagonals?
		if (theBoard[i][i] != majorT) {
			winT = false;
		}
		if (theBoard[i][BOARD_SIZE - i] != majorB) {
			winB = false;
		}
	}
	//diagonal victories
	if (winT)
		return majorT;
	if (winB)
		return majorB;
	//draw
	if (countNumberOfTakenSquares >= BOARD_SIZE * BOARD_SIZE)
		return FULL_BOARD;
	
	return EMPTY_MARKER;
}