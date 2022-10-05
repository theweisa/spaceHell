#include "highScores.h"

HighScores::HighScores()
{
	std::string buffer;
	//check if the file exists; if it doesn't, initialize a new file with all 0s
	if (!checkIfFileExists())
	{
		std::ofstream fout(highScoreFileName);
		for (int i = 0; i < 5; i++)
		{
			fout << 0 << '\n';
		}
		fout.close();
	}
	//open the high score file
	std::ifstream fin(highScoreFileName);
	if (!fin)
	{
		std::cerr << "Can't find " << highScoreFileName << std::endl;
		exit(1);
	}
	//put the scores form the file into the scores array
	for (int i = 0; i < 5; i++)
	{
		if (std::getline(fin, buffer))
		{
			Score temp(stoi(buffer));
			scores[i] = temp;
		}
	}
	fin.close();
}

void HighScores::updateHighScore(Score & s)
{
	//update the scores with the new score if it is a high score
	for (int i = 0; i < 5; i++)
	{
		if (scores[i] < s)
		{
			Score temp = scores[i];
			scores[i] = s;
			s = temp;
		}
	}
	//open the high score file
	std::ofstream fout(highScoreFileName);
	if (!fout)
	{
		std::cerr << "Can't find " << highScoreFileName << std::endl;
		exit(2);
	}
	//save the new scores into the file
	for (int i = 0; i < 5; i++)
		fout << scores[i];
	fout.close();
}

bool HighScores::checkIfFileExists()
{
	std::ifstream fin(highScoreFileName);
	return (static_cast<bool>(fin));
}
