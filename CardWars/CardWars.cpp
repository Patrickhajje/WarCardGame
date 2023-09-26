#include <iostream>
#include "Console.h"
#include "Input.h"
#include "WarGame.h"
#include <sstream>
#include <fstream>
#include "HighScore.h"

int main()
{
    Console::ResizeWindow(150, 40);

    WarGame war;

    int menuSelection = 0;
    std::vector<std::string> menuOptions{ "1. Show Cards", "2. Show High Scores", "3. Play Card Wars", "4. Exit" };
    std::string highScoreFile = "HighScores.csv";
    std::string cardsFile = "cards.csv";

    WarGame::LoadCards(cardsFile);
    
    std::vector<HighScore>highScores = HighScore::LoadHighScores(highScoreFile);

    do
    {
        Console::Clear();

        menuSelection = Input::GetMenuSelection(menuOptions);

        switch (menuSelection)
        {
        case 1:
        {
            WarGame::ShowCards();
            break;
        }
        case 2:
        {
            HighScore::ShowHighScores(highScores);
            break;
        }
        case 3:
        {
            war.PlayGame(highScoreFile, highScores);
            break;
        }
        default:
            break;
        }

        Input::PressEnter();

    } while (menuSelection != menuOptions.size());

}