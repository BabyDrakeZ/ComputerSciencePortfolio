
#include "player.h"


Player::Player() {
	playerID = '?';
	selfMarker = '?';
}
Player::Player(char marker, char playerIdentifier) {
	selfMarker = marker;
	playerID = playerIdentifier;
}
void Player::getMove(int& row, int& col) {
	std::cout << "Please input the square (row col) to place your move: ";
	std::cin >> row >> col;
	//this is to prevent the while(true) loop from never ending upon an never filled input
	if (row == EMPTY_MOVE || col == EMPTY_MOVE) {
		std::cout << "We are sorry, but your input is not a cordinate, please restart";
		exit(1);
	}
}
char Player::getMarker() {
	return selfMarker;
}