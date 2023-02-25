#include <iostream>
#include "movie.h"

int main(void) {
	Movie m0("Ford vs. Ferrari", "PG-13");
	m0.addMoiveRating(great);
	m0.print();
	Movie m1("Rise of Skywalker", "PG-13");
	m1.addMoiveRating(terrible);
	m1.addMoiveRating(terrible);
	m1.print();
	Movie m2("A new Hope", "PG");
	m2.addMoiveRating(ok);
	m2.addMoiveRating(great);
	m2.addMoiveRating(great);
	m2.addMoiveRating(good);
	m2.addMoiveRating(terrible);
	m2.print();
}