Brian Lamere
CS362_400
Assignment 2

Card and Method Documentation

1. smithy card:
This card draws an addtional 3 cards from the current player's deck and adds them to his hand. The smithy card itself is then discarded.

2. adventurer card:
This card draws cards from the currentPlayer's hand until 2 copper, silver, or gold cards are drawn. Any cards that are not copper, silver, or gold are put into a tempHand array that is then added to a discard array for the currentPlayer, and the card is removed from the currentPlayer's hand. 

3. discardCard() method:
This method takes 4 parameters:
 1) handPos: the position of the card in the currentPlayer's hand that will be discarded with this function
 2) currentPlayer: identifier for player whose card will be discarded
 3) state: the gameState struct holding the current state of the game
 4) trashFlag: if this is NOT set, the discarded card at handPos returns to the collective playedCards pile

The over purpose of this method is to remove the card at handPos from the state->hand array of the currentPlayer, and update the state of the currentPlayer's hand accordingly. If the trashFlag is not set, the card returns to the state's playedCards[] array.

4. updateCoins() method:
The overall purpose of this method is to return the number of coins a player will have available from his hand to use in the BUY portion of his turn.
The method takes 3 parameters:

  1) an integer representing the player whose coins are to be updated
  2) a pointer to a gameState struct which holds the current state of the game
  3) an integer representing any bonus amount of coins the player may be receiving from his played action card.

The first thing this method does is reset the value of the gameState's coins variable. Then, it iterates through the given player's hand of cards, incrementing the value of this variable depending on (a) the count of coin cards in the player's hand, and (b) the individual values of those coin cards (1 for copper, 2 for silver, 3 for gold).

Finally, should a bonus value have been passed into this method, due to the player playing an action card granting him this bonus, it is added to the value of this variable.

