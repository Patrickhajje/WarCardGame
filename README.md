# WarCardGame
Welcome to the Card Game Readme! 
This document provides an overview of the rules and instructions for playing the card game. The game is designed to be played in a console environment and follows a specific set of rules outlined below.

Game Rules
1. Shuffle the Deck
To start the game, call the shuffle function and pass in a vector of cards. This will randomize the order of the cards in the deck.

2. Split the Deck
After shuffling, split the shuffled deck into two equal vectors: playerCards and npcCards. These will represent the player's and the non-player character's (NPC) hands, respectively.

3. Create Piles
Create three empty vectors: playerPile, npcPile, and unclaimedPile. These will be used to store cards as the game progresses.

4. Start the Game Loop
The game is played in a loop until the playerCards vector is empty. Here are the steps for each iteration of the loop:

a. Print Cards
Print out the first card from both playerCards and npcCards. You can call the print method on the cards to display them.

b. Add to Unclaimed Pile
Add the first card from both playerCards and npcCards to the unclaimedPile.

c. Compare Cards
Call the compare method of the card class and pass the first card from playerCards and npcCards. The compare method returns:

-1 if card1 is less than card2.
0 if card1 is equal to card2.
1 if card1 is greater than card2.
d. NPC Wins
If compare returns -1, add the unclaimedPile to the npcPile, clear the unclaimedPile, and print "NPC wins."

e. Player Wins
If compare returns 1, add the unclaimedPile to the playerPile, clear the unclaimedPile, and print "Player wins."

f. Remove Cards
Remove the first card from both playerCards and npcCards.

5. Determine the Overall Winner
After the game loop, determine the overall winner based on the number of hands won by each player. Here's how to do it:

Keep track of the number of hands won by the player and the NPC as the game progresses.
a. NPC Wins More Hands
If the NPC wins more hands than the player, print "NPC won the game."

b. Tie
If the player and the NPC win an equal number of hands, print "The game ended in a tie."

c. Player Wins More Hands
If the player wins more hands than the NPC, print "Player won the game."

i. Check for New High Score
If the player's score is a new high score, do the following:

Get the player's name using Input.getString.
Loop through the high score vector.
If the player's score is greater than or equal to the score in the vector, insert a new high score object into the vector at that index.
Remove the last score in the vector.
Call SaveHighScores to save the updated high scores.
Call ShowHighScores to display the new top 10 high scores.
Please note that this game is designed for a console environment and requires the implementation of specific functions and classes, such as shuffle, print, compare, Input.getString, SaveHighScores, and ShowHighScores, as mentioned in the instructions.

Enjoy playing the card game, and may the player or the NPC win the most hands!
