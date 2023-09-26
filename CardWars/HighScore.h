#pragma once
#include <string>
#include <vector>
#include <fstream>
class HighScore
{
private:
	std::string mName;
	int mScore;

public:

	std::string name() const
	{
		return mName;
	}
	void name(std::string newName)
	{
		mName = newName;
	}
	int score() const
	{
		return mScore;
	}
	void score(int newScore)
	{
		mScore = newScore;
	}
	void serialize(std::ofstream& file, char delim)
	{

		file << mName << delim << mScore;
	}
	static std::vector<HighScore> LoadHighScores(std::string filePath);
	static void ShowHighScores(std::vector<HighScore>& highScore);
	static void SaveHighScores(std::string filePath, std::vector<HighScore>& highScore);
};

