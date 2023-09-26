#include "HighScore.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Console.h"
#include <iomanip>

/// <summary>
/// It deserializes the CSV file into a vector<HighScore>.
/// It then returns the vector.
/// </summary>
/// <param name="filePath"></param>
/// <returns></returns>
std::vector<HighScore> HighScore::LoadHighScores(std::string filePath)
{
    std::vector<HighScore>highscores;
    std::ifstream inputFile(filePath);
    std::string line;
    while (!inputFile.eof())
    {
        std::getline(inputFile, line);
        std::vector<std::string>items;
        std::string hsCSV;
        std::stringstream hsStream(line);
        while (std::getline(hsStream, hsCSV, ','))
        {
            items.push_back(hsCSV);
        }
        HighScore highscore;
        highscore.name(items[0]);
        highscore.score(stoi(items[1]));
        highscores.push_back(highscore);
    }
    return highscores;
}

/// <summary>
/// It prints a “High Scores” title then loops over the high scores vector and prints each item.
/// </summary>
/// <param name="highScores"></param>
void HighScore::ShowHighScores(std::vector<HighScore>& highScores)
{
    std::cout << "----High Scores----" << std::endl;
    for (auto highscore : highScores)
    {
        
        std::cout<< std::left <<std::setw(13) << highscore.name();
        
        Console::SetForegroundColor(Yellow);
        std::cout << std::setw(4) << highscore.score() << std::endl;
        Console::SetForegroundColor(White);
    }
}

/// <summary>
/// It serializes the vector of high scores to the file.
/// Then it calls this method in the game when a player gets a new high score.
/// </summary>
/// <param name="filePath"></param>
/// <param name="highScore"></param>
void HighScore::SaveHighScores(std::string filePath, std::vector<HighScore>& highScore)
{
    char delim = ',';
    bool isFirst = true;
    std::ofstream file(filePath);
    for (auto& highscore : highScore)
    {
        if (!isFirst) {
            file << "\n";
        }
        highscore.serialize(file, delim);
        isFirst = false;
    }
    file.close();
}
