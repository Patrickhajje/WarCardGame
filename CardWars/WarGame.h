#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include <fstream>
#include <sstream>
#include "HighScore.h"

class WarGame

{
private:
	static std::vector<Card> mCards;

	static void shuffle();

public:
	WarGame(); 
	static void LoadCards(std::string& filePath);

	static void ShowCards();
	void PlayGame(std::string& highscoreFile, std::vector<HighScore>& highscores);
};

