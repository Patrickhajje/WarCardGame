#include "WarGame.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Input.h"


std::vector<Card> WarGame::mCards;

WarGame::WarGame()
{
}
/// <summary>
/// Accepts a string parameter (filePath).
/// It reads the csv file and split the data to get each string. 
/// It Stores each card in the mCards vector field of the class.
/// </summary>
/// <param name="filePath"></param>
void WarGame::LoadCards(std::string& filePath)
{
    std::vector<std::string>faces;
    std::vector<std::string>suites;
    char delimiter = ',';
    std::ifstream inputFile(filePath);
    std::string suitLine;
    std::string faceLine;

    std::getline(inputFile, suitLine);
    std::stringstream inputStream(suitLine);
    std::string placeHolder;
    while (std::getline(inputStream, placeHolder, delimiter))
    {
        suites.push_back(placeHolder);
    }

    std::getline(inputFile, faceLine);
    std::stringstream inputDataStream(faceLine);
    while (std::getline(inputDataStream, placeHolder, delimiter))
    {
        faces.push_back(placeHolder);
    }
    for (auto& suit : suites) 
    {
        for (auto& face : faces)
        {
            Card card(suit, face);
            mCards.push_back(card);
        }
    }
}
/// <summary>
/// It loops over the vector and calls the Print method on each card.
/// </summary>
void WarGame::ShowCards()
{
    for(auto& card : mCards)
    {
        card.print();
        std::cout << std::endl;
    }
}

/// <summary>
/// Plays the game and compares the player vs the npc reults
/// thus declaring a new winner and updating the csv file with the new highscores.
/// <param name="highscoreFile"></param>
/// <param name="highscores"></param>
/// /// </summary>
void WarGame::PlayGame(std::string& highscoreFile, std::vector<HighScore>& highscores)
{
    
/// Starts by calling shuffle passing in the vector of cards.
/// Then takes the shuffled vector and split it into 2 equal vectors : playerCards and npcCards.
/// Created 3 vectors : playerPile, npcPile, unclaimedPile.
/// Loops while the playerCards vector is not empty
/// It prints out the first card from playerCards and npcCards.
/// Then it adds the first card from playerCards and npcCards to the unclaimed pile.
/// It then calls the compare method of the card class and passes the first card from the playerCards and npcCards.
/// If compare returns - 1, we add the unclaimed pile to the npcPile and print that NPC wins.
/// If compare returns 1, add the unclaimed pile to the playerPile and print player wins.
/// Then remove the first card from the playerCards and npcCards.
/// After the loop, we check who won.
/// I player has more round wins then print out that the player won and check if it’s a new high score.
/// If the playerPile count is greater than the last score in the high score vector, the player has a new high score.
/// If the player’s score is a new high score,
/// It gets the user’s name using Input.getString

    shuffle();
    std::vector<Card>playerCards(mCards.begin(), mCards.begin() + mCards.size() / 2);
    std::vector<Card>npcCards(mCards.begin() + mCards.size() / 2, mCards.end());

    std::vector<Card>playerPile;
    std::vector<Card>npcPile;
    std::vector<Card>unclaimedPile;
    int playerCount = 0;
    int npcCount = 0;
    while (playerCards.size() > 0)
    {
        playerCards[0].print();
        std::cout << " vs ";
        npcCards[0].print();

        unclaimedPile.push_back(playerCards[0]);
        unclaimedPile.push_back(npcCards[0]);
        int result = playerCards[0].compare(npcCards[0]);
        if (result == -1)
        {
            npcPile.push_back(unclaimedPile[0]);
            npcPile.push_back(unclaimedPile[1]);
            unclaimedPile.clear();
            std::cout << " NPC wins" << "\n";
            playerCards.erase(playerCards.begin());
            npcCards.erase(npcCards.begin());
            npcCount++;
        }
        if (result == 1)
        {
            playerPile.push_back(unclaimedPile[0]); 
            playerPile.push_back(unclaimedPile[1]);
            unclaimedPile.clear();
            std::cout << " Player wins" << "\n";
            playerCards.erase(playerCards.begin());
            npcCards.erase(npcCards.begin());
            playerCount++;
        }
        if (result == 0)
        {
            unclaimedPile.clear();
            playerCards.erase(playerCards.begin());
            npcCards.erase(npcCards.begin());
            std::cout << "\n";
        }
    }
    if (playerCount < npcCount)
    {
        std::cout << "\nNPC WINS! " << npcCount << " to " << playerCount << "\n";
    }
    if (playerCount == npcCount)
    {
        std::cout << "\nTIE! " << playerCount << " to " << npcCount << "\n";
    }
    if (playerCount > npcCount)
    {
        std::cout << "\nPLAYER WINS! " << playerCount << " to " << npcCount << "\n";
    }
    if (playerCount > highscores.back().score() && playerCount > npcCount)
    {
        std::string name;
       name = Input::GetString("\nNEW HIGH SCORE! What is your name? ");
        std::cout << name << std::endl;
        for (int i = 0; i < highscores.size() ; i++)
        {    
            
            if (playerCount >= highscores[i].score())
            {  
                HighScore newHighScore;
                newHighScore.name(name);
                newHighScore.score(playerCount);
                highscores.insert(highscores.begin() + i, newHighScore); 
                highscores.pop_back();
                HighScore::SaveHighScores(highscoreFile, highscores);
                HighScore::ShowHighScores(highscores);
                break;
            } 
        }
    }     
}

void WarGame::shuffle()
{
    int ndx1, ndx2;
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < 52; i++)
    {
        ndx1 = rand() % 52;
        ndx2 = rand() % 52;

        Card temp = mCards[ndx1];
        mCards[ndx1] = mCards[ndx2];
        mCards[ndx2] = temp;
    }
}
