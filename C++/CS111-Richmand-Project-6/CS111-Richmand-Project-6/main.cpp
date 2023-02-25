

#include <iostream>
#include "board.h"
#include "player.h"

int main() {
	Player p1('x', 'a');
	Player p2('o', 'b');
	int moveCount = 0;
	Board board;
	std::cout << "Welcome to tic-tac-toe\n";
	while (true) {
		int r = EMPTY_MOVE, c = EMPTY_MOVE;
		std::cout << "Move number: " << moveCount++ << std::endl;
		board.printBoard();
		p1.getMove(r, c);
		board.submitMove(r, c, p1.getMarker());
		r = EMPTY_MOVE, c = EMPTY_MOVE;
		char winner = board.isWinner();
		if (winner == p1.getMarker() || winner == FULL_BOARD)
			break;
		board.printBoard();
		p2.getMove(r, c);
		board.submitMove(r, c, p2.getMarker());
		winner = board.isWinner();
		if (winner == p2.getMarker() || winner == FULL_BOARD)
			break;
		board.printBoard();
	}
	std::cout << "Final result: ";
	if (board.isWinner() == FULL_BOARD)
		std::cout << " Its a Tie!\n ";
	else
		std::cout << " Player " << board.isWinner() << " wins! \n";
	board.printBoard();
	return 0;
}