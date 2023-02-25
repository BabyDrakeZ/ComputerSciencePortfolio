#pragma once

#include <iostream>


#define EMPTY_MOVE -1 //for preventing erronious inputs

class Player {
public:
	//precondition: -
	//postcondition: playerId='?', selfMarker = '?'
	Player();
	//precondition: -
	//postcondition self Marker = marker, playerID = playerIdentifier
	Player(char marker, char playerIdentifier);
	//precondtion: row, col are defined by calling function
	//postcondition: row, col contain player input; function prompts player for input
	void getMove(int& row, int& col);
	char getMarker(); //return selfMarker
private:
	char selfMarker; //either X or O
	char playerID; // either a or b
};