Robert Ward
10-10-2015
Assignment 2

Documentation

Smithy Card:
The smithy card does two things, first it adds 3 cards to the current players had using the "drawCard" function. Using a for loop the drawCard function is called 3 times.
The second thing that the smithy does is to discard a card from the current players hand using the "discardCard" function.

Adventurer Card:
The adventurer card lets the player draw two treasures from the deck. It loops in a while statement until drawntreasure is greater than >= 2. First the deck is checked to make sure it is not empty. If it is then the "shuffle" function is called to shuffle the discard pile. Next a card is drawn from the deck using "drawCard". If the card is a treasure card then the drawntreasure counter is incremented and the loop starts again. If it is not a treasure card then the card is put into a temporary hand to be discarded once the two treasures are drawn. Once a second treasure card has been drawn the loop ends and a second loop is started to discard the temporary hand holding the drawn cards.

discardCard():
The discardCard function takes four arguments: int handPos, int currentPlayer, struct gameState *state, int trashFlag. 
handPos - the location of the card to discard in the players hand
currentPlayer - the player discarding the card
gameState *state - pointer to the structure that holds the state of the game
trashFlag - whether the card is sent to the playedCards pile or removed from the game

First, the discardCard function checks if the card is being trashed or moved to the playedCards pile. If it is not trashed it is added to playedCards, else it is not referenced again.
Next the position in the players hand that held the discarded cards value is set to -1.
Finally the players hand is updated. If the card was the last card in the players hand then the hand cound is simply decremented. If the player only had one card then the the players hand is also decremented, this should never be reached because only having one card means it is the last card in the players hand... If the card was not the last card then the current last card is moved to the discarded cards position in the array and the number of cards in the players hand is decremented.
The function returns 0 when complete.

updateCoins():
The updateCoins function takes three arguments: int player, struct gameState *state, int bonus.
player - the player that is having the coins counted
gameState *state - pointer to the structure that holds the state of the game
bonus - additional coins to add to the players coin count

This function starts by setting state->coins to 0. It then loops through the cards in the players hand and counts the number of coins that the player has, 1 for copper, 2 for silver and 3 for gold. After counting the coins it adds the bonus to the coin count. state->coins is used to purchase cards.

