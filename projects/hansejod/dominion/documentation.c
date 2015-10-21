callSmithy(int currentPlayer_, int handPos_, struct gameState *state_):
The objective of the smithy card action is to allow the player to draw three extra cards. It does this by creating a for loop that calls the drawCard function each iteration. The smithy card is then discarded to the playedCard pile. The function uses the arguments of the currentPlayer, the handPos of the Smithy card, and the gameState structure.

callAdventurer(int currentPlayer_, int cardDrawn_, int *temphand, struct gameState *state):
The goal of the adventure card to find two treasure cards in your deck and discard all the other cards. The function sets a counter variable to 0 and uses it as the conditional in a while loop. While the drawntreasure is less than 2, the code will check if the deck count is empty. If the deck is empty, it will call the suffle function, to shuffle the deck. It calls the drawCard to draw a card. It sets cardDrawn as the top card of the hand. If this card is equal to a treasure card it increases the drawnstreasure by one. If it is not a treasure card, it adds the cardDrawn to the temporary hand and decreases the deckcount by one. It also increases another counter z by one. The end while loop checks if z has been increased, as in we put a card in the temporary hand. If there are cards present they are put in the discard pile

discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag):
The objective of this function is to discard a card in the currentPlayer's hand. The arguments are the currentPlayer, the card's position in the hand, the gameState structure which includes lots of data about the players and cards in the various piles, and a flag that determines if the card is destined to the trash or played card pile.

The first conditional first checks if the card is not trashed. If it isn't it updates the gameState structure variable playedCards array to include the card. It increases the playedCardCount by one.

It then sets the currentPlayer's card in that position to false. This essentially trashes the card if it was not copied to the playCards pile.

The next series of conditionals check the number of cards in the players hand, or handCount. If the card's position is equal to the end of the array, it reduces the currentPlayer's handCount.  If there is only one card in the array, the number of cards in the hand is reduced by one. If neither conditional is met, the last card replaces the discarded card. The new card is set to -1 and the handCount is reduced by one.


updateCoins(int player, struct gameState *state, int bonus):
The goal of updateCoins is to update the value of the treasure cards when a player draws cards. It sets the coins in the gameState structure to 0 and then proceeds to use a for loop to check the player's hand and if it finds a match with copper, silver, or gold, it adds the appropriate amount to the gameState coins. At the end it adds a bonus, if there is one. The arguments passed are the player (by checking the state's whose turn value, the gameState structure, and the bonus, which is 0 when normally drawing and different for the action cards.




