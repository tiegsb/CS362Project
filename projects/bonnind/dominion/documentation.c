Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
documentation.c

This file contains documentation for the Smithy and Adventurer cards, and 
the discardCard() and updateCoins() functions.

Smithy card: 
When the Smithy card is played, the player draws 3 cards. This consumes 1 action. 
This card activates calls drawCard() 3 times, then calls discardCard().

Adventurer card:
When the Adventurer card is played, the player draws from the deck until 2 
treasure cards are uncovered. All other drawn cards are discarded. 

This card performs a while loop that calls drawCard(), checks the new card for 
treasure, and leaves the new card in the hand if it is treasure. If the new 
card is not treasure, it is removed from the hand and added to a temporary 
hand. Once 2 treasure cards are revealed, the temporary hand is discarded 
via a while loop.  

discardCard():
Removes a card from the player's hand array. The card is either
trashed or placed into a playedCards array.

If the position of the discarded card is not at the end of the hand array, 
the last card in the hand array replaces the discarded card. 

updateCoins():
Calculates number of coins player currently has available. The function 
increments the coins variable by looping through the hand array and incrementing
coins by the appropriate value for any treasure cards encountered. The function
also takes a "bonus" parameter, which is added to coins.  