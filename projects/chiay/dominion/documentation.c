Documentation:

Smithy:
Smithy allows the player to draw 3 more cards from the deck, so the code contains a for loop to run the drawCard function 3 times. Since each player are allowed only 1 action per round (exclude bonus action), and the card does not give any additional "action point" to the player to play another Action card, the player will then proceed to the Buy phase, and eventually discard all the cards to the pile.

Adventurer:
The action of this card is to keep revealing card from the deck until 2 Treasure cards are revealed (what the while loop is doing here), and these two Treasure cards are then include to player's hand. First, the player will draw a card from the deck and check whether if it is a Treasure card in the if-else statement. The drawntreasure variable, which controls the looping, will increment if the player draw a Treasure card, or else that particular card will be discarded. 

discardCard():
During the discard, the trashFlag "0" is passed to the function, which caused the first if-else statement to execute. Whatever number of card in the player's hand will be counted as the card the player has played. 

updateCoins():
Every time during a player's turn, the initial coin in hand is 0. The for loop will go over the player's hand to check for the 3 different values of Treasure cards and calculate how much coins does the player has to buy the cards from the Supply.
