#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include "score.h"

//high scores class
class HighScores
{
private:
	//contains scores
	Score scores[5];
	//string with score name
	const std::string highScoreFileName = "Scores/highScores.txt";
public:
	//default constructor for high score
	HighScores();
	//updates the high score
	void updateHighScore(Score& s);
	//check if the file exists
	bool checkIfFileExists();
	//use of overload insertion operator to print the top 5 scores
	inline friend std::ostream& operator<<(std::ostream& out, HighScores h) 
	{
		out << "High Scores" << std::endl;
		for (auto i = 0; i < 5; i++)
			out << i + 1 << ":  " << h.scores[i];
		return out;
	}
};

#endif 