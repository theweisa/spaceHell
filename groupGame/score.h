#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

//score class
class Score
{
private:
	//points a score has
	unsigned int points;
public:
	//default constructor for score
	Score() = default;
	//initializes the points
	Score(unsigned int p)
		: points(p) {}
	//override < operator to compare points
	inline bool operator<(const Score& obj) const { return points < obj.points; }
	//override insertion operator to print points when score is printede
	inline friend std::ostream& operator<<(std::ostream& out, const Score& obj) {
		out << obj.points << std::endl;
		return out;
	}
};

#endif 