#include "movie.h"

Movie::Movie() {
	name = "Not Set";
	mpaaRating = "Not Set";
	average = 0;
	for (int i = 0; i < 5; i++)
		qualityRating[i] = 0;
}
Movie::Movie(string _name, string _mpaaRating) {
	name = _name;
	mpaaRating = _mpaaRating;
	average - 0;
	for (int i = 0; i < 5; i++)
		qualityRating[i] = 0;
}


string Movie::getMovieName() {
	return name;
}
string Movie::getMPAARating() {
	return mpaaRating;
}
void Movie::setMPAARating(string _rating) {
	mpaaRating = _rating;
}
void Movie::calculateQualityAverage() {
	average = 0;
	int numberOfRatings = 0;
	for (int i = 0; i < 5; i++) {
		numberOfRatings += qualityRating[i];
		average += qualityRating[i] * (i + 1);
	}
	average /= numberOfRatings; // 5;
}
void Movie::addMoiveRating(MovieQualityRating movieQualityRating) {
	if (movieQualityRating == none)
		return;
	qualityRating[movieQualityRating]++;
	calculateQualityAverage();
}
float Movie::getAverageRating() {
	return average;
}
void Movie::print() {
	std::cout << "Movie name: " << name << ", Rating: " << mpaaRating <<  "Average viewer rating " << average << "\n";
}