Dominion documentation

This file documents how the functions smithy, adventurer, discardCard and updateCoins work.

updateCoins():
Parameters: Update coins takes in 3 parameters: The player id (int), a struct that holds the various game states,
and the bonus amount of coins to add. 

Purpose: The purpose of this function is to count how many coins the player has in their hand
and add the number of bonus coins. That number is stored in that player's game state.

Method: Through a for loop, the function will go through each card in hand and if it 
runs into copper (value 1), silver (value 2), or gold (value 3) it will add that value to the
player's total. Finally it adds the bonus parameter to the player's game state.

############################################################################################################

discardCard():

Parameters: discardCard takes in 4 parameters: The card to be discarded (int handPos),
the id of the player (int currentPlayer), the game state (strut gamestate), and if the card is to be trashed (int trashFlag)

Purpose: The purpose of this function is to remove the card from the player's hand

Method: The cards in each hand is stored in a 2d array stored in the gamestate. They can be accessed as:
array[playerID][handPosition]

If the trashFlag is not set to 1, then the card played (indicated by input handPos) is added to the player's playedCards state
. The played cards count is increased by 1.
The array position where the hands are stored is set to -1 t indicate that it has been played.

The card played is then replaced by the card located in the last in the players hand. This only happens if there are more than 1 card left in hand
or the card played is not the last position. 

Finally the handcount is reduced by 1.

############################################################################################################

smithy():
Parameters: none

Purpose: to draw three cards and add them to the player's hand

Method: using a for loop, the card will call the drawCard() function times. Then it will call the discardCard function to
remove itself from the player's hand.

############################################################################################################

adventurer():
Parameters: none

Purpose: to draw cards until 2 treasure cards are drawn. Those two treasure cards are added to hand while the
rest of the cards are discarded.

Method: Using a while loop, the function calls upon drawcard until 2 treasure cards are drawn. These are indicated by the drawntreasure variable.

Before drawing, if the deck is empty, then the shuffle function is called and all discarded cards are reshuffled into a new deck. Cards are then drawn.

Each card drawn into hand is evaluated. If it is a treasure card, it is allowed to stay in hand and the drawntreasure variable goes up by 1.
If it is not a treasure card, the hand size is reduced by one effectively removing the card from hand. Each card discarded
this way is stored within a temporary array.

All cards that are stored in the temporary array are then added to the discard pile.