#pragma once

#include <iostream>
#include <string>

using namespace std;
enum MovieQualityRating { terrible = 0, bad = 1, ok = 2, good = 3, great = 4, none = 5 };

class Movie {
private:
	int qualityRating[5];
	float average;
	string name;
	string mpaaRating;
	void calculateQualityAverage();
public:
	Movie();
	Movie(string _name, string _mpaaRating);
	string getMovieName();
	//void setMovieName(string _name);
	string getMPAARating();
	void setMPAARating(string _rating);
	void addMoiveRating(MovieQualityRating movieQualityRating);
	float getAverageRating();
	void print();
};